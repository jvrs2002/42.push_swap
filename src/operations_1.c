/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-vri <joao-vri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 12:29:56 by joao-vri          #+#    #+#             */
/*   Updated: 2025/06/19 20:28:35 by joao-vri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sa(t_data **head_a, int flag)
{
	t_data	*first;
	t_data	*second;

	if (!*head_a || (*head_a)->next == *head_a)
		return ;
	first = *head_a;
	second = first->next;
	if (second->next == first)
	{
		*head_a = second;
		if (flag)
			write(1, "sa\n", 3);
		return ;
	}
	swap_nodes(head_a);
	if (flag)
		write(1, "sa\n", 3);
}

void	swap_nodes(t_data **head)
{
	t_data	*first;
	t_data	*second;
	t_data	*third;
	t_data	*last;

	first = *head;
	second = first->next;
	third = second->next;
	last = first->prev;
	second->next = first;
	second->prev = last;
	first->next = third;
	first->prev = second;
	last->next = second;
	third->prev = first;
	*head = second;
}

void	sb(t_data **head_b, int flag)
{
	if (!*head_b || (*head_b)->next == *head_b)
		return ;
	if ((*head_b)->next->next == *head_b)
		*head_b = (*head_b)->next;
	else
		swap_nodes(head_b);
	if (flag)
		write(1, "sb\n", 3);
}

void	ss(t_data **head_a, t_data **head_b)
{
	sa(head_a, 0);
	sb(head_b, 0);
	write(1, "ss\n", 3);
}
