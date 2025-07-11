/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_4.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-vri <joao-vri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 20:28:17 by joao-vri          #+#    #+#             */
/*   Updated: 2025/06/19 20:28:39 by joao-vri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	pa(t_data **head_a, t_data **head_b, size_t *size_a, size_t *size_b)
{
	int	first_data_b;

	if (*head_b == NULL)
		return ;
	first_data_b = pop(head_b);
	push(head_a, first_data_b);
	++(*size_a);
	--(*size_b);
	write(1, "pa\n", 3);
}

void	pb(t_data **head_a, t_data **head_b, size_t *size_a, size_t *size_b)
{
	int	first_data_a;

	if (*head_a == NULL)
		return ;
	first_data_a = pop(head_a);
	push(head_b, first_data_a);
	--(*size_a);
	++(*size_b);
	write(1, "pb\n", 3);
}
