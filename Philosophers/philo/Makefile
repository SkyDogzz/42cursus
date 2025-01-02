NAME=philo
CFLAGS=-Wall -Wextra -Werror
CC=cc

SRC=philo.c parse.c utils.c

all: $(NAME)

$(NAME): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)

clean:
	rm -rf *.o

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
