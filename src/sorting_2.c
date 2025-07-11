/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-vri <joao-vri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 12:18:35 by joao-vri          #+#    #+#             */
/*   Updated: 2025/06/23 13:36:07 by joao-vri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort_12(t_stack *stack)
{
	int	rotated;
	int	remaining;
	int	last_pushed;

	rotated = 0;
	remaining = 0;
	if (stack->cs[stack->ci] > 12)
		return ;
	stack->med1 = calc_median(stack->sorted_b, stack->cs[stack->ci]);
	stack->last_pushed = calc_pushed(stack->sorted_b,
			stack->cs[stack->ci], stack->med1, 0);
	last_pushed = stack->last_pushed;
	stack->med2 = calc_median(stack->sorted_b, stack->last_pushed);
	sort_12_13_rt(stack, &rotated, &remaining, 0);
	sort_3(stack, 0);
	while (rotated--)
		rra(&stack->head_a, 1);
	sort_3(stack, 0);
	while (remaining--)
		rrb(&stack->head_b, 1);
	stack->sorted_b = rem_update_array(stack->sorted_b,
			stack->size_b, last_pushed);
	sort_6(stack, last_pushed);
}

void	sort_13(t_stack *stack)
{
	int	rotated;
	int	remaining;
	int	last_pushed;

	rotated = 0;
	remaining = 0;
	if (stack->cs[stack->ci] != 13)
		return ;
	stack->med1 = calc_median(stack->sorted_b, stack->cs[stack->ci]);
	stack->last_pushed = calc_pushed(stack->sorted_b,
			stack->cs[stack->ci], stack->med1, 0);
	stack->last_pushed++;
	last_pushed = stack->last_pushed;
	stack->med2 = calc_median(stack->sorted_b, stack->last_pushed);
	sort_12_13_rt(stack, &rotated, &remaining, 1);
	sort_3(stack, 0);
	while (rotated--)
		rra(&stack->head_a, 1);
	update_arrays(stack, 4);
	sort_4(stack, 0);
	while (remaining--)
		rrb(&stack->head_b, 1);
	sort_6(stack, last_pushed);
}

void	sort_12_13_rt(t_stack *stack, int *rotated, int *remaining, int flag)
{
	int	can_rr;

	can_rr = 0;
	while (stack->last_pushed > 0)
	{
		if ((stack->head_b->number > stack->med1 && flag == 0) || \
		(stack->head_b->number >= stack->med1 && flag == 1))
			sort_12_13_push(stack, rotated, &can_rr);
		else
		{
			if (can_rr == 1)
			{
				rr(stack);
				can_rr = 2;
			}
			else
				rb(&stack->head_b, &stack->rb_rr, 1, stack->size_b);
			(*remaining)++;
		}
	}
}

void	sort_12_13_push(t_stack *stack, int *rotated, int *can_rr)
{
	if (*can_rr == 1)
	{
		ra(&stack->head_a, &stack->ra_rr, 1);
		*can_rr = 2;
	}
	pa(&stack->head_a, &stack->head_b, &stack->size_a, &stack->size_b);
	stack->last_pushed--;
	stack->cs[stack->ci]--;
	if (stack->head_a->number <= stack->med2)
	{
		if (*can_rr == 0)
			*can_rr = 1;
		else
			ra(&stack->head_a, &stack->ra_rr, 1);
		(*rotated)++;
	}
}
