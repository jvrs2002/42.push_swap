/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-vri <joao-vri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 11:43:30 by joao-vri          #+#    #+#             */
/*   Updated: 2025/06/23 13:22:20 by joao-vri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	check_error(int *nbrs, size_t input_count, t_stack stack)
{
	if ((input_count == 0 || input_count == 1) && nbrs)
	{
		if (nbrs)
			free(nbrs);
		exit (0);
	}
	if (!nbrs || check_rep_nbr(nbrs, stack.size_a) == 0)
	{
		if (nbrs)
			free(nbrs);
		write(2, "Error\n", 7);
		exit (0);
	}
	if (check_sorted(nbrs, stack.size_a) == 0 && nbrs)
	{
		if (nbrs)
			free(nbrs);
		exit (0);
	}
}

int	main(int ac, char **av)
{
	int		*nbrs;
	size_t	input_count;
	t_stack	stack;

	nbrs = NULL;
	init_struct(&stack);
	input_count = ac - 1;
	if (input_count == 0)
		return (0);
	if (input_count == 1)
		nbrs = parse_one_argument(av, &input_count);
	else if (input_count > 1)
		nbrs = parse_multiple_arguments(av, input_count);
	stack.size_a = input_count;
	check_error(nbrs, input_count, stack);
	init_stack(&stack.head_a, nbrs, input_count);
	handle_median_push_b(&stack, nbrs);
	handle_median_push_a(&stack);
	free_all(&stack, nbrs);
}
