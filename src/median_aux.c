/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median_aux.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-vri <joao-vri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 12:19:52 by joao-vri          #+#    #+#             */
/*   Updated: 2025/06/19 22:21:06 by joao-vri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	manage_chunk_push_b(t_stack *stack, size_t ci)
{
	if ((!(stack->is_first) && stack->head_b->number > stack->med2) || \
		(stack->is_first && stack->head_b->number < stack->med2))
	{
		stack->rb_rr = 1;
		if (stack->is_first)
			stack->cs[ci] += 1;
		else
			stack->cs[ci + 1] += 1;
	}
	else
	{
		if (stack->is_first)
			stack->cs[ci + 1] += 1;
		else
			stack->cs[ci] += 1;
	}
}

void	process_stack_push_b(t_stack *stack, size_t ci, int *nbrs)
{
	size_t	pushed;

	stack->last_pushed = calc_pushed(nbrs, stack->size_a, stack->med1, 1);
	pushed = stack->last_pushed;
	while (pushed > 0)
	{
		if (stack->head_a->number < stack->med1)
		{
			if (stack->rb_rr == 1)
				rb(&stack->head_b, &stack->rb_rr, 1, stack->size_b);
			pb(&stack->head_a, &stack->head_b, &stack->size_a, &stack->size_b);
			manage_chunk_push_b(stack, ci);
			pushed--;
		}
		else
		{
			if (stack->size_a > 3 && stack->rb_rr == 1)
				rr(stack);
			else if (stack->size_a > 3)
				ra(&stack->head_a, &stack->ra_rr, 1);
		}
	}
	if (pushed == 0 && stack->rb_rr == 1)
		rb(&stack->head_b, &stack->rb_rr, 1, stack->size_b);
}
