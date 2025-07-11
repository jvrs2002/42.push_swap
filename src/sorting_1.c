/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-vri <joao-vri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 12:18:35 by joao-vri          #+#    #+#             */
/*   Updated: 2025/06/23 15:56:27 by joao-vri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	first_sort_a(t_stack *stack)
{
	int	a;
	int	b;
	int	c;

	if (stack->size_a != 3)
		return ;
	a = stack->head_a->number;
	b = stack->head_a->next->number;
	c = stack->head_a->next->next->number;
	if (a > b && b < c && a < c)
		sa(&stack->head_a, 1);
	else if (a > b && b > c)
	{
		sa(&stack->head_a, 1);
		rra(&stack->head_a, 1);
	}
	else if (a > b && b < c && a > c)
		ra(&stack->head_a, &stack->ra_rr, 1);
	else if (a < b && b > c && a < c)
	{
		sa(&stack->head_a, 1);
		ra(&stack->head_a, &stack->ra_rr, 1);
	}
	else if (a < b && b > c && a > c)
		rra(&stack->head_a, 1);
}

void	sort_3(t_stack *stack, size_t last_rotated)
{
	int	a;
	int	b;
	int	c;

	a = stack->head_a->number;
	b = stack->head_a->next->number;
	c = stack->head_a->next->next->number;
	if (a < b && b < c)
		return ;
	if (a > b && b < c && a < c)
		return (sa(&stack->head_a, 1));
	else if ((a > b && b > c) || (a > b && b < c && a > c))
		sa(&stack->head_a, 1);
	ra(&stack->head_a, &stack->ra_rr, 1);
	sa(&stack->head_a, 1);
	if (last_rotated >= 1)
	{
		rrr(&stack->head_a, &stack->head_b);
		stack->last_rotated -= 1;
	}
	else
		rra(&stack->head_a, 1);
	if ((a < b && b > c && a > c) || (a > b && b > c))
		sa(&stack->head_a, 1);
}

void	sort_4(t_stack *stack, size_t last_rotated)
{
	int	smallest;
	int	rotated;

	rotated = 0;
	smallest = find_smallest_number(stack->sorted_a, 4);
	while (stack->head_a->number != smallest)
	{
		ra(&stack->head_a, &stack->ra_rr, 1);
		rotated++;
	}
	pb(&stack->head_a, &stack->head_b, &stack->size_a, &stack->size_b);
	while (rotated > 0)
	{
		rra(&stack->head_a, 1);
		rotated--;
	}
	sort_3(stack, last_rotated);
	pa(&stack->head_a, &stack->head_b, &stack->size_a, &stack->size_b);
}

void	sort_6(t_stack *stack, size_t last_pushed_to_add)
{
	size_t	pushed;
	size_t	remaining;

	if (stack->cs[stack->ci] > 6)
		return ;
	stack->last_rotated = 0;
	stack->med1 = calc_median(stack->sorted_b, stack->cs[stack->ci]);
	stack->last_pushed = calc_pushed(stack->sorted_b, stack->cs[stack->ci],
			stack->med1, 0);
	pushed = stack->last_pushed;
	remaining = stack->cs[stack->ci] - pushed;
	stack->last_pushed += remaining;
	sort_6_push_rotate(stack, &stack->last_rotated, &pushed);
	sort_3(stack, stack->last_rotated);
	while (stack->last_rotated--)
		rrb(&stack->head_b, 1);
	while (remaining--)
		pa(&stack->head_a, &stack->head_b, &stack->size_a, &stack->size_b);
	sort_3(stack, 0);
	stack->last_pushed += last_pushed_to_add;
	if (stack->size_b > 0)
	{
		update_arrays(stack, 3);
		stack->ci--;
	}
}

void	sort_6_push_rotate(t_stack *stack, size_t *rotated, size_t *pushed)
{
	while (*pushed > 0)
	{
		if (stack->head_b->number <= stack->med1)
		{
			rb(&stack->head_b, &stack->rb_rr, 1, stack->size_b);
			(*rotated)++;
		}
		else
		{
			pa(&stack->head_a, &stack->head_b, &stack->size_a, &stack->size_b);
			(*pushed)--;
		}
	}
}
