/* ************************************************************************** */
/*                                                                            */
/*                            Dining Philosophers                            */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>

// Struct for philosopher data
typedef struct s_philosopher {
    int id;
    pthread_t thread;
    int left_fork;
    int right_fork;
    long last_meal;
    int meals_eaten;
    struct s_data *data;
} t_philosopher;

// Struct for shared data
typedef struct s_data {
    int nb_philosophers;
    long time_to_die;
    long time_to_eat;
    long time_to_sleep;
    int nb_meals;
    int all_satisfied;
    int stop_simulation;
    pthread_mutex_t *forks;
    pthread_mutex_t print_lock;
    t_philosopher *philosophers;
    long start_time;
} t_data;

// Utility: Get the current time in milliseconds
long get_time(void) {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
}

// Utility: Print thread-safe messages
void print_status(t_philosopher *philo, const char *msg) {
    pthread_mutex_lock(&philo->data->print_lock);
    if (!philo->data->stop_simulation) {
        printf("%ld %d %s\n", get_time() - philo->data->start_time, philo->id, msg);
    }
    pthread_mutex_unlock(&philo->data->print_lock);
}

// Sleep for a given number of milliseconds
void smart_sleep(long ms) {
    long start = get_time();
    while (get_time() - start < ms)
        usleep(100);
}

// Philosopher lifecycle
void *philosopher_routine(void *arg) {
    t_philosopher *philo = (t_philosopher *)arg;
    t_data *data = philo->data;

    while (!data->stop_simulation) {
        // Attempt to take both forks atomically
        if (philo->id % 2 == 0) {
            pthread_mutex_lock(&data->forks[philo->left_fork]);
            if (pthread_mutex_trylock(&data->forks[philo->right_fork]) == 0) {
                print_status(philo, "has taken a fork");
                print_status(philo, "has taken a fork");

                // Eat
                print_status(philo, "is eating");
                philo->last_meal = get_time();
                philo->meals_eaten++;
                if (data->nb_meals > 0 && ++data->all_satisfied >= data->nb_philosophers * data->nb_meals) {
                    data->stop_simulation = 1;
                }
                smart_sleep(data->time_to_eat);

                // Put down forks
                pthread_mutex_unlock(&data->forks[philo->right_fork]);
                pthread_mutex_unlock(&data->forks[philo->left_fork]);

                // Sleep
                print_status(philo, "is sleeping");
                smart_sleep(data->time_to_sleep);

                // Think
                print_status(philo, "is thinking");
            } else {
                pthread_mutex_unlock(&data->forks[philo->left_fork]);
            }
        } else {
            pthread_mutex_lock(&data->forks[philo->right_fork]);
            if (pthread_mutex_trylock(&data->forks[philo->left_fork]) == 0) {
                print_status(philo, "has taken a fork");
                print_status(philo, "has taken a fork");

                // Eat
                print_status(philo, "is eating");
                philo->last_meal = get_time();
                philo->meals_eaten++;
                if (data->nb_meals > 0 && ++data->all_satisfied >= data->nb_philosophers * data->nb_meals) {
                    data->stop_simulation = 1;
                }
                smart_sleep(data->time_to_eat);

                // Put down forks
                pthread_mutex_unlock(&data->forks[philo->left_fork]);
                pthread_mutex_unlock(&data->forks[philo->right_fork]);

                // Sleep
                print_status(philo, "is sleeping");
                smart_sleep(data->time_to_sleep);

                // Think
                print_status(philo, "is thinking");
            } else {
                pthread_mutex_unlock(&data->forks[philo->right_fork]);
            }
        }
    }
    return NULL;
}

// Monitor philosophers for starvation
void *monitor_routine(void *arg) {
    t_data *data = (t_data *)arg;

    while (!data->stop_simulation) {
        for (int i = 0; i < data->nb_philosophers; i++) {
            t_philosopher *philo = &data->philosophers[i];
            if (get_time() - philo->last_meal > data->time_to_die) {
                pthread_mutex_lock(&data->print_lock);
                if (!data->stop_simulation) {
                    printf("%ld %d died\n", get_time() - data->start_time, philo->id);
                }
                data->stop_simulation = 1;
                pthread_mutex_unlock(&data->print_lock);
                return NULL;
            }
        }
        usleep(1000);
    }
    return NULL;
}

// Initialize data and philosophers
int init(t_data *data, int argc, char **argv) {
    data->nb_philosophers = atoi(argv[1]);
    data->time_to_die = atol(argv[2]);
    data->time_to_eat = atol(argv[3]);
    data->time_to_sleep = atol(argv[4]);
    data->nb_meals = (argc == 6) ? atoi(argv[5]) : -1;
    data->all_satisfied = 0;
    data->stop_simulation = 0;
    data->forks = malloc(sizeof(pthread_mutex_t) * data->nb_philosophers);
    data->philosophers = malloc(sizeof(t_philosopher) * data->nb_philosophers);
    if (!data->forks || !data->philosophers)
        return 1;
    pthread_mutex_init(&data->print_lock, NULL);
    for (int i = 0; i < data->nb_philosophers; i++)
        pthread_mutex_init(&data->forks[i], NULL);
    for (int i = 0; i < data->nb_philosophers; i++) {
        data->philosophers[i].id = i + 1;
        data->philosophers[i].left_fork = i;
        data->philosophers[i].right_fork = (i + 1) % data->nb_philosophers;
        data->philosophers[i].last_meal = get_time();
        data->philosophers[i].meals_eaten = 0;
        data->philosophers[i].data = data;
    }
    data->start_time = get_time();
    return 0;
}

// Clean up resources
void cleanup(t_data *data) {
    for (int i = 0; i < data->nb_philosophers; i++)
        pthread_mutex_destroy(&data->forks[i]);
    pthread_mutex_destroy(&data->print_lock);
    free(data->forks);
    free(data->philosophers);
}

int main(int argc, char **argv) {
    if (argc < 5 || argc > 6) {
        printf("Usage: %s <nb_philosophers> <time_to_die> <time_to_eat> <time_to_sleep> [nb_meals]\n", argv[0]);
        return 1;
    }

    t_data data;
    if (init(&data, argc, argv)) {
        printf("Initialization failed\n");
        return 1;
    }

    pthread_t monitor;
    pthread_create(&monitor, NULL, monitor_routine, &data);

    for (int i = 0; i < data.nb_philosophers; i++)
        pthread_create(&data.philosophers[i].thread, NULL, philosopher_routine, &data.philosophers[i]);

    for (int i = 0; i < data.nb_philosophers; i++)
        pthread_join(data.philosophers[i].thread, NULL);

    pthread_join(monitor, NULL);
    cleanup(&data);
    return 0;
}
