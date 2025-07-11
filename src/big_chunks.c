/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_chunks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-vri <joao-vri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 18:25:44 by joao-vri          #+#    #+#             */
/*   Updated: 2025/06/21 13:54:52 by joao-vri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	push_big_chunks_pa(t_stack *stack)
{
	int	to_push;

	stack->med1 = calc_median(stack->sorted_b, stack->cs[stack->ci]);
	stack->last_pushed = calc_pushed(stack->sorted_b,
			stack->cs[stack->ci], stack->med1, 0);
	to_push = stack->last_pushed;
	stack->og_size = stack->last_pushed;
	stack->last_rotated = 0;
	while (to_push > 0)
	{
		if (stack->head_b->number > stack->med1)
		{
			pa(&stack->head_a, &stack->head_b, &stack->size_a, &stack->size_b);
			to_push--;
		}
		else
		{
			rb(&stack->head_b, &stack->rb_rr, 1, stack->size_b);
			stack->last_rotated++;
		}
	}
	while (stack->last_rotated--)
		rrb(&stack->head_b, 1);
	stack->cs[stack->ci] -= stack->last_pushed;
	update_arrays(stack, 0);
}

void	first_push_big_chunks_pb(t_stack *stack)
{
	int	og_size;

	stack->last_rotated = 0;
	stack->med1 = calc_median(stack->sorted_a, stack->last_pushed);
	stack->last_pushed = calc_pushed(stack->sorted_a,
			stack->last_pushed, stack->med1, 2);
	og_size = stack->og_size;
	while (og_size--)
	{
		if (stack->head_a->number <= stack->med1)
			pb(&stack->head_a, &stack->head_b, &stack->size_a, &stack->size_b);
		else
		{
			ra(&stack->head_a, &stack->ra_rr, 1);
			stack->last_rotated++;
		}
	}
	stack->cs[stack->ci] = stack->last_pushed;
	stack->og_size -= stack->last_pushed;
	update_arrays(stack, 1);
}

void	second_push_big_chunks_pb(t_stack *stack)
{
	int	remaining;

	stack->med1 = calc_median(stack->sorted_a, stack->og_size);
	stack->last_pushed = calc_pushed(stack->sorted_a,
			stack->og_size, stack->med1, 2);
	remaining = stack->last_rotated - stack->last_pushed;
	stack->cs[stack->ci] = stack->last_pushed;
	while (stack->last_rotated--)
	{
		rra(&stack->head_a, 1);
		if (stack->head_a->number <= stack->med1)
			pb(&stack->head_a, &stack->head_b, &stack->size_a, &stack->size_b);
	}
	update_arrays(stack, 1);
	if (remaining <= 3)
		sort_3(stack, 0);
	else
	{
		stack->ci++;
		stack->cs[stack->ci] = remaining;
		while (remaining--)
			pb(&stack->head_a, &stack->head_b, &stack->size_a, &stack->size_b);
		update_arrays(stack, 2);
	}
}
