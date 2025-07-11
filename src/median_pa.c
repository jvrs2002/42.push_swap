/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median_pa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-vri <joao-vri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 12:22:12 by joao-vri          #+#    #+#             */
/*   Updated: 2025/06/23 15:53:37 by joao-vri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	handle_median_push_a(t_stack *stack)
{
	int	*nbrs;

	if (stack->size_b <= 0)
		return ;
	nbrs = copy_to_array(stack->head_b, &stack->size_b);
	stack->sorted_b = bubble_sort(nbrs, stack->size_b, 1);
	free(nbrs);
	while (stack->size_b > 0)
	{
		if (stack->cs[stack->ci] <= 3 && stack->size_b > 0)
			handle_small_chunks(stack);
		if (stack->size_a == 6 && stack->size_b == 0)
			sort_3(stack, 0);
		while (stack->cs[stack->ci] <= 6 && \
		stack->cs[stack->ci] > 0 && stack->size_b > 0)
			sort_6(stack, 0);
		while (stack->cs[stack->ci] <= 12 && \
		stack->cs[stack->ci] > 6 && stack->size_b > 0)
			sort_12(stack);
		while (stack->cs[stack->ci] == 13 && stack->size_b > 0)
			sort_13(stack);
		while (stack->cs[stack->ci] > 13 && stack->size_b > 0)
			handle_big_chunks(stack);
	}
}

void	handle_small_chunks(t_stack *stack)
{
	int	chunk_size;

	stack->last_pushed = 0;
	while (stack->cs[stack->ci] <= 3 && stack->size_b > 0)
	{
		while (stack->cs[stack->ci] == 0)
			stack->ci--;
		chunk_size = stack->cs[stack->ci];
		if (chunk_size > 3)
			return ;
		while (chunk_size-- > 0)
		{
			pa(&stack->head_a, &stack->head_b, &stack->size_a, &stack->size_b);
			stack->last_pushed++;
		}
		if (stack->cs[stack->ci] == 2 && \
		stack->head_a->number > stack->head_a->next->number)
			sa(&stack->head_a, 1);
		else if (stack->cs[stack->ci] == 3)
			sort_3(stack, 0);
		if (stack->ci > 0)
			stack->ci--;
	}
	update_arrays(stack, 0);
}

void	handle_big_chunks(t_stack *stack)
{
	if (stack->cs[stack->ci] <= 12)
		return ;
	push_big_chunks_pa(stack);
	stack->ci++;
	first_push_big_chunks_pb(stack);
	if (stack->og_size <= 3)
	{
		while (stack->last_rotated--)
			rra(&stack->head_a, 1);
		sort_3(stack, 0);
	}
	else
	{
		stack->ci++;
		second_push_big_chunks_pb(stack);
	}
}
