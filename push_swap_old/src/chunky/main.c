/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstephan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 13:33:36 by tstephan          #+#    #+#             */
/*   Updated: 2024/12/11 14:41:54 by tstephan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

// chunk numbers are arbitrary
int	chunk_number(t_list *list)
{
	int	list_size;

	list_size = ft_lstsize(list);
	if (list_size <= 101)
		return (10);
	if (list_size <= 300)
		return (8);
	return (11);
}

void	free_chunks(int	**chunks, int pos)
{
	while (--pos)
		free(chunks[pos]);
	free(chunks);
}

void	sort_array(int *array, int size)
{
	int pos;
	int	flag;
	int	temp;

	flag = 1;
	while (flag)
	{
		flag = 0;
		pos = 0;
		while (pos < size - 1)
			if (array[pos] > array[pos + 1])
			{
				temp = array[pos];
				array[pos] = array[pos + 1];
				array[pos + 1] = temp;
				flag = 1;
			}
	}
}

void	fill_chunks(t_list *list)
{
	int pos1;
	int	pos2;
	int len;
	int	*ordered;

	len = ft_lstsize(list);
	ordered = (int *)malloc(sizeof(int) * len);
	if (!ordered)
		return ;
	pos1 = 0;
	while (list)
	{
		ordered[pos1] = *(int *)list->content;
		list = list->next;
	}
	sort_array(ordered, len);
}

int	**get_chunks(t_list *list)
{
	int	pos;
	int	chunk_nbr;
	int	chunk_size;
	int	**chunks;

	chunk_nbr = chunk_number(list);
	chunks = (int **)malloc(sizeof(int *) * chunk_nbr);
	if (!chunks)
		return (NULL);
	chunk_size = ft_lstsize(list) / chunk_nbr;
	pos = 0;
	while (pos < chunk_nbr - 1)
	{
		chunks[pos] = (int *)malloc(sizeof(int) * chunk_size);
		if (!chunks[pos])
			free_chunks(chunks, pos);
		pos++;
	}	
	chunks[pos] = (int *)malloc(sizeof(int) * (ft_lstsize(list) % chunk_size + chunk_size));
	if (!chunks[pos])
		free_chunks(chunks, pos);
	chunks[0][0] = 10;
	// fill_chunks(list, chunks);
	return (chunks);
}

void	chunky_sort(t_wrapper *wrapper, t_list **l1, t_list **l2)
{
	int	**chunks;

	chunks = get_chunks(*l1);
	(void) wrapper;
	(void) l1;
	(void) l2;
}
