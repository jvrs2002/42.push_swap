/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-vri <joao-vri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 21:21:23 by joao-vri          #+#    #+#             */
/*   Updated: 2025/06/23 13:22:50 by joao-vri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	pop(t_data **head)
{
	t_data	*first;
	t_data	*last;
	int		data;

	if (*head == NULL)
		return (-1);
	first = *head;
	data = first->number;
	if (first->next == first)
		*head = NULL;
	else
	{
		last = first->prev;
		*head = first->next;
		(*head)->prev = last;
		last->next = *head;
	}
	free(first);
	return (data);
}

void	push(t_data **head, int data)
{
	t_data	*new_node;
	t_data	*last;

	new_node = (t_data *)malloc(sizeof(t_data));
	if (!new_node)
		return ;
	new_node->number = data;
	if (*head == NULL)
	{
		new_node->next = new_node;
		new_node->prev = new_node;
		*head = new_node;
	}
	else
	{
		last = (*head)->prev;
		last->next = new_node;
		new_node->next = *head;
		new_node->prev = last;
		(*head)->prev = new_node;
		(*head) = new_node;
	}
}

int	check_sorted(int *nbrs, size_t input_count)
{
	size_t	i;

	if (input_count < 2)
		return (1);
	i = 0;
	while (i < input_count - 1)
	{
		if (nbrs[i] < nbrs[i + 1])
			i++;
		else
			return (1);
	}
	return (0);
}
