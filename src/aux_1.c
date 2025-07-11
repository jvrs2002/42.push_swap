/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-vri <joao-vri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 14:15:51 by joao-vri          #+#    #+#             */
/*   Updated: 2025/06/19 22:21:06 by joao-vri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	init_stack(t_data **head_a, int *nbrs, size_t array_count)
{
	if (!head_a)
		return ;
	*head_a = NULL;
	while (array_count > 0)
	{
		push(head_a, nbrs[array_count - 1]);
		--array_count;
	}
}

void	init_struct(t_stack *stack)
{
	if (stack == NULL)
		return ;
	stack->head_a = NULL;
	stack->head_b = NULL;
	stack->sorted_b = NULL;
	stack->sorted_a = NULL;
	stack->last_pushed = 0;
	stack->med1 = 0;
	stack->med2 = 0;
	stack->size_a = 0;
	stack->size_b = 0;
	stack->ra_rr = 0;
	stack->rb_rr = 0;
	stack->ci = 0;
	stack->last_rotated = 0;
	stack->og_size = 0;
	stack->is_first = 0;
}

void	*free_array(int i, char **strs)
{
	while (i > 0)
		free(strs[--i]);
	free(strs);
	return (NULL);
}

void	free_list(t_data *head)
{
	t_data	*node;
	t_data	*temp;

	if (head == NULL)
		return ;
	node = head->next;
	while (node != head)
	{
		temp = node->next;
		free(node);
		node = temp;
	}
	free(head);
}

void	free_all(t_stack *stack, int *nbrs)
{
	free_list(stack->head_a);
	free_list(stack->head_b);
	free(nbrs);
	free(stack->sorted_b);
	free(stack->sorted_a);
}
