/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-vri <joao-vri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 12:04:46 by joao-vri          #+#    #+#             */
/*   Updated: 2025/04/29 19:14:54 by joao-vri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	rra(t_data **head_a, int flag)
{
	if (!head_a || !*head_a || (*head_a)->next == *head_a)
		return ;
	*head_a = (*head_a)->prev;
	if (flag == 1)
		write(1, "rra\n", 4);
}

void	rrb(t_data **head_b, int flag)
{
	if (!head_b || !*head_b || (*head_b)->next == *head_b)
		return ;
	*head_b = (*head_b)->prev;
	if (flag == 1)
		write(1, "rrb\n", 4);
}

void	rrr(t_data **head_a, t_data **head_b)
{
	rra(head_a, 0);
	rrb(head_b, 0);
	write(1, "rrr\n", 4);
}
