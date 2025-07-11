/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-vri <joao-vri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 12:04:46 by joao-vri          #+#    #+#             */
/*   Updated: 2025/06/22 01:16:50 by joao-vri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ra(t_data **head_a, size_t *ra_rr, int flag)
{
	if (!head_a || !*head_a || (*head_a)->next == *head_a)
		return ;
	*head_a = (*head_a)->next;
	if (flag == 1)
		write(1, "ra\n", 3);
	*ra_rr = 0;
}

void	rb(t_data **head_b, size_t *rb_rr, int flag, size_t size_b)
{
	if (size_b > 0)
	{
		if (!head_b || !*head_b || (*head_b)->next == *head_b)
		{
			*rb_rr = 0;
			return ;
		}
		*head_b = (*head_b)->next;
		if (flag == 1)
			write(1, "rb\n", 3);
	}
	*rb_rr = 0;
}

void	rr(t_stack *stack)
{
	ra(&stack->head_a, &stack->ra_rr, 0);
	rb(&stack->head_b, &stack->rb_rr, 0, stack->size_b);
	write(1, "rr\n", 3);
}
