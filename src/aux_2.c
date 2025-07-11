/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-vri <joao-vri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 17:38:37 by joao-vri          #+#    #+#             */
/*   Updated: 2025/06/23 15:37:23 by joao-vri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	*bubble_sort(int *nbrs, size_t size_checkpoint, int flag)
{
	size_t	i;
	int		swap;
	int		*nbrs_sorted;

	nbrs_sorted = (int *)malloc(sizeof(int) * size_checkpoint);
	if (!nbrs_sorted)
		return (NULL);
	ft_memcpy(nbrs_sorted, nbrs, size_checkpoint * sizeof(int));
	while (size_checkpoint != 0)
	{
		i = 0;
		while (i < size_checkpoint - 1)
		{
			if ((nbrs_sorted[i] > nbrs_sorted[i + 1] && flag == 0) || \
			(nbrs_sorted[i] < nbrs_sorted[i + 1] && flag == 1))
			{
				swap = nbrs_sorted[i];
				nbrs_sorted[i] = nbrs_sorted[i + 1];
				nbrs_sorted[i + 1] = swap;
			}
			++i;
		}
		--size_checkpoint;
	}
	return (nbrs_sorted);
}

int	find_smallest_number(int *nbrs, size_t size)
{
	int		smallest;
	size_t	i;

	if (size == 0)
		return (0);
	smallest = nbrs[0];
	i = 1;
	while (i < size)
	{
		if (nbrs[i] < smallest)
			smallest = nbrs[i];
		i++;
	}
	return (smallest);
}

int	check_rep_nbr(int *nbrs, int size)
{
	int	i;

	size--;
	i = 0;
	while (size >= 0)
	{
		i = size - 1;
		while (i >= 0)
		{
			if (nbrs[size] == nbrs[i])
				return (0);
			i--;
		}
		size--;
	}
	return (1);
}

size_t	calc_pushed(int *nbrs, size_t chunk_size, int median, int flag)
{
	size_t	i;
	size_t	pushed;

	i = 0;
	pushed = 0;
	while (i < chunk_size)
	{
		if ((nbrs[i] > median && flag == 0) || \
		(nbrs[i] < median && flag == 1) || \
		(nbrs[i] <= median && flag == 2))
			pushed++;
		i++;
	}
	return (pushed);
}

int	calc_median(int *nbrs_sorted, size_t chunk_size)
{
	int	mid1;
	int	mid2;

	if (chunk_size == 1)
		return (nbrs_sorted[0]);
	mid1 = nbrs_sorted[(chunk_size / 2) - 1];
	mid2 = nbrs_sorted[chunk_size / 2];
	if (chunk_size == 0 || !nbrs_sorted)
		return (-1);
	if (chunk_size % 2 == 1)
		return (nbrs_sorted[chunk_size / 2]);
	else
	{
		if ((mid1 + mid2) < 0 && (mid1 + mid2) % 2 != 0)
			return ((mid1 + mid2) / 2 - 1);
		else
			return ((mid1 + mid2) / 2);
	}
}
