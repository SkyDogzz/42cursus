/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skydogzz </var/spool/mail/skydogzz>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 22:40:15 by skydogzz          #+#    #+#             */
/*   Updated: 2024/11/27 00:58:46 by skydogzz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/include/ft_printf.h"

typedef struct s_number
{
	int				number;
	unsigned int	indice;
}	t_number;

t_bool ft_canatoi(const char *str)
{
	while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\r' || *str == '\f' || *str == '\v')
		str++;
	if (*str == '+' || *str == '-')
		str++;
	return (*str >= '0' && *str <= '9');
}

t_bool	ft_onlyint(int argc, char *argv[])
{
	int	pos;

	pos = 1;
	while (pos < argc)
		if (!ft_canatoi(argv[pos++]))
			return (FALSE);
	return (TRUE);
}

void	ft_displaypile(t_number *pile, size_t n)
{
	size_t	pos;
	
	pos = 0;
	while (pos < n)
	{
		ft_printf("%d ", pile[pos].number);
		pos++;
	}
}

void	ft_displaypileindice(t_number *pile, size_t n)
{
	size_t	pos;
	
	pos = 0;
	while (pos < n)
	{
		ft_printf("%d|%d ", pile[pos].number, pile[pos].number);
		pos++;
	}
}

t_bool	ft_populate(t_number *pile, char *argv[], size_t n)
{
	size_t	pos;
	size_t	pos2;
	int		tmp;

	pos = 1;
	while (pos < n)
	{
		pos2 = 0;
		tmp = ft_atoi(argv[pos]);
		while (pos2 < pos)
		{
			if (tmp == pile[pos2].number)
				return (FALSE);
			pos2++;
		}
		pile[pos - 1].number = tmp;
		pile[pos - 1].indice = pos;
		pos++;
	}
	return (TRUE);
}

int partition(int *arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return (i + 1);
}

void quicksort(int *arr, int low, int high) {
    if (low < high) {
        int pivot = partition(arr, low, high);
        quicksort(arr, low, pivot - 1);
        quicksort(arr, pivot + 1, high);
    }
}

int	main(int argc, char *argv[])
{
	t_number	pile_a[argc - 1];

	if (argc < 2)
	{
		ft_dprintf(2, "Not args\n");
		exit(0);
	}
	if (!ft_onlyint(argc, argv) || !ft_populate(pile_a, argv, argc))
	{
		ft_dprintf(2, "Not only int in args!\n");
		exit(0);
	}

	ft_displaypile(pile_a, argc - 1);
	int tab[] = {1, 2, 3, 5, 5};
	quicksort(tab, 0, 4);

	return EXIT_SUCCESS;
}
