/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-vri <joao-vri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 20:03:47 by joao-vri          #+#    #+#             */
/*   Updated: 2025/06/22 22:43:39 by joao-vri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	*rem_update_array(int *nbrs_sorted, size_t size, size_t pushed)
{
	int	*new_nbrs_sorted;

	new_nbrs_sorted = NULL;
	if (!nbrs_sorted)
		return (NULL);
	new_nbrs_sorted = (int *)malloc(sizeof(int) * size);
	if (!new_nbrs_sorted)
		return (NULL);
	ft_memcpy(new_nbrs_sorted, &nbrs_sorted[pushed], size * sizeof(int));
	free(nbrs_sorted);
	return (new_nbrs_sorted);
}

int	*add_update_array(int *dst, size_t dst_size, int *src, size_t pushed)
{
	int		*new_array;
	size_t	i;

	new_array = NULL;
	if ((!dst && dst_size > 0) || (!src && pushed > 0))
		return (NULL);
	new_array = (int *)malloc(sizeof(int) * (dst_size + pushed));
	if (!new_array)
		return (NULL);
	i = 0;
	while (i < pushed)
	{
		new_array[i] = src[pushed - 1 - i];
		i++;
	}
	if (dst_size > 0)
		ft_memcpy(new_array + pushed, dst, dst_size * sizeof(int));
	free(dst);
	return (new_array);
}

void	update_arrays(t_stack *stack, int flag)
{
	if (flag == 0)
	{
		stack->sorted_a = add_update_array(stack->sorted_a,
				stack->size_a - stack->last_pushed, stack->sorted_b,
				stack->last_pushed);
		stack->sorted_b = rem_update_array(stack->sorted_b,
				stack->size_b, stack->last_pushed);
	}
	else if (flag == 1)
	{
		stack->sorted_b = add_update_array(stack->sorted_b,
				stack->size_b - stack->last_pushed,
				stack->sorted_a, stack->last_pushed);
		stack->sorted_a = rem_update_array(stack->sorted_a,
				stack->size_a, stack->last_pushed);
	}
	else if (flag == 2 || flag == 3 || flag == 4)
		update_arrays_2(stack, flag);
}

void	update_arrays_2(t_stack *stack, int flag)
{
	if (flag == 2)
	{
		stack->sorted_b = add_update_array(stack->sorted_b,
				stack->size_b - stack->cs[stack->ci],
				stack->sorted_a, stack->cs[stack->ci]);
		stack->sorted_a = rem_update_array(stack->sorted_a,
				stack->size_a, stack->cs[stack->ci]);
	}
	else if (flag == 3)
	{
		stack->sorted_a = add_update_array(stack->sorted_a,
				stack->size_a - stack->last_pushed, stack->sorted_b,
				stack->last_pushed);
		stack->sorted_b = rem_update_array(stack->sorted_b,
				stack->size_b, stack->cs[stack->ci]);
	}
	else if (flag == 4)
	{
		stack->sorted_a = add_update_array(stack->sorted_a,
				stack->size_a - 7, stack->sorted_b, 7);
		stack->sorted_b = rem_update_array(stack->sorted_b,
				stack->size_b, 7);
	}
}

int	*copy_to_array(t_data *head, size_t *size)
{
	size_t	i;
	int		*nbrs;
	t_data	*node;

	i = 0;
	if (!head || !size || *size == 0)
		return (NULL);
	nbrs = (int *)malloc(sizeof(int) * (*size));
	if (!nbrs)
		return (NULL);
	node = head;
	while (i < *size)
	{
		nbrs[i] = node->number;
		node = node->next;
		++i;
		if (node == head)
			break ;
	}
	i = 0;
	return (nbrs);
}
