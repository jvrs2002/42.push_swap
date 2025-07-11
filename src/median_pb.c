/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median_pb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-vri <joao-vri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 16:36:39 by joao-vri          #+#    #+#             */
/*   Updated: 2025/06/23 16:04:05 by joao-vri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	handle_median_push_b(t_stack *stack, int *nbrs)
{
	stack->sorted_a = bubble_sort(nbrs, stack->size_a, 0);
	if (stack->size_a == 2)
	{
		if (stack->head_a->number > stack->head_a->next->number)
			sa(&stack->head_a, 1);
		return ;
	}
	if (stack->size_a == 3 || stack->size_a == 4)
	{
		if (stack->size_a == 4)
			last_median_push_b(stack);
		first_sort_a(stack);
		pa(&stack->head_a, &stack->head_b, &stack->size_a, &stack->size_b);
		return ;
	}
	first_median_push_b(stack);
	if (stack->size_a > 4 && stack->size_a != 5)
		second_median_push_b(stack);
	while (stack->size_a > 4)
		median_push_b(stack);
	if (stack->size_a == 4)
		last_median_push_b(stack);
	first_sort_a(stack);
}

void	first_median_push_b(t_stack *stack)
{
	if (stack->size_a <= 6)
	{
		stack->med1 = calc_median(stack->sorted_a, stack->size_a);
		stack->med2 = calc_median(stack->sorted_a, stack->size_a / 2);
	}
	else
	{
		stack->med1 = calc_median(stack->sorted_a, stack->size_a / 2);
		stack->med2 = calc_median(stack->sorted_a, stack->size_a / 4);
	}
	stack->ci += 2;
	stack->cs[0] = 0;
	stack->cs[1] = 0;
	stack->cs[2] = 0;
	stack->is_first = 1;
	process_stack_push_b(stack, 0, stack->sorted_a);
	stack->sorted_a = rem_update_array(stack->sorted_a,
			stack->size_a, stack->last_pushed);
}

void	second_median_push_b(t_stack *stack)
{
	size_t	i;

	stack->ci += 2;
	stack->cs[2] = 0;
	stack->cs[3] = 0;
	stack->med1 = calc_median(stack->sorted_a, stack->size_b * 2);
	stack->med2 = calc_median(stack->sorted_a, stack->size_b);
	stack->is_first = 0;
	process_stack_push_b(stack, 2, stack->sorted_a);
	i = stack->cs[3];
	while (i-- > 0)
		rrb(&stack->head_b, 1);
	stack->sorted_a = rem_update_array(stack->sorted_a,
			stack->size_a, stack->last_pushed);
}

void	median_push_b(t_stack *stack)
{
	size_t	i;

	stack->cs[stack->ci] = 0;
	stack->cs[stack->ci + 1] = 0;
	stack->med1 = calc_median(stack->sorted_a, stack->size_a);
	stack->med2 = calc_median(stack->sorted_a, stack->size_a / 2);
	process_stack_push_b(stack, stack->ci, stack->sorted_a);
	i = stack->cs[stack->ci + 1];
	while (i-- > 0)
		rrb(&stack->head_b, 1);
	stack->ci += 2;
	if (stack->size_a == 3)
		stack->ci--;
	stack->sorted_a = rem_update_array(stack->sorted_a,
			stack->size_a, stack->last_pushed);
}

void	last_median_push_b(t_stack *stack)
{
	int	smallest;

	stack->cs[stack->ci] = 1;
	smallest = find_smallest_number(stack->sorted_a, stack->size_a);
	while (stack->head_a->number != smallest)
		ra(&stack->head_a, &stack->ra_rr, 1);
	pb(&stack->head_a, &stack->head_b, &stack->size_a, &stack->size_b);
	stack->last_pushed = 1;
	stack->sorted_a = rem_update_array(stack->sorted_a,
			stack->size_a, stack->last_pushed);
}
