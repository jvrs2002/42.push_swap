/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-vri <joao-vri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 11:15:45 by joao-vri          #+#    #+#             */
/*   Updated: 2025/06/23 13:35:09 by joao-vri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include "limits.h"
# include "../libs/Libft/libft.h"

typedef struct s_data
{
	int				number;
	struct s_data	*next;
	struct s_data	*prev;
}				t_data;

typedef struct s_stack
{
	t_data	*head_a;
	t_data	*head_b;
	size_t	size_a;
	size_t	size_b;
	size_t	cs[100000];
	size_t	ci;
	int		med1;
	int		med2;
	size_t	is_first;
	size_t	rb_rr;
	size_t	ra_rr;
	int		*sorted_a;
	int		*sorted_b;
	size_t	last_pushed;
	size_t	last_rotated;
	size_t	og_size;
}	t_stack;

int		*parse_multiple_arguments(char **av, size_t array_count);
int		*parse_one_argument(char **av, size_t *array_count);
size_t	input_count(const char *str, char c);
void	init_stack(t_data **head_a, int *nbrs, size_t array_count);
void	*free_array(int i, char **strs);
void	free_list(t_data *head);
int		pop(t_data **head);
void	push(t_data **head, int data);
void	first_median_push_b(t_stack *stack);
void	second_median_push_b(t_stack *stack);
void	median_push_b(t_stack *stack);
void	first_sort_a(t_stack *stack);
int		*copy_to_array(t_data *head, size_t *size);
void	pa(t_data **head_a, t_data **head_b, size_t *size_a, size_t *size_b);
void	pb(t_data **head_a, t_data **head_b, size_t *size_a, size_t *size_b);
void	ra(t_data **head_a, size_t *ra_rr, int flag);
void	rb(t_data **head_b, size_t *rb_rr, int flag, size_t size_b);
void	rr(t_stack *stack);
void	rra(t_data **head, int flag);
void	rrb(t_data **head, int flag);
void	rrr(t_data **head_a, t_data **head_b);
void	sa(t_data **head_a, int flag);
void	sb(t_data **head_b, int flag);
void	ss(t_data **head_a, t_data **head_b);
int		*bubble_sort(int *nbrs, size_t size_checkpoint, int flag);
int		calc_median(int *nbrs_sorted, size_t chunk_size);
void	last_median_push_b(t_stack *stack);
int		find_smallest_number(int *nbrs, size_t size);
void	handle_median_push_b(t_stack *stack, int *nbrs);
int		check_rep_nbr(int *nbrs, int size);
size_t	calc_pushed(int *nbrs, size_t chunk_size, int median, int flag);
void	manage_chunk_push_b(t_stack *stack, size_t ci);
void	process_stack_push_b(t_stack *stack, size_t ci, int *nbrs);
void	sort_3(t_stack *stack, size_t last_rotated);
void	handle_median_push_a(t_stack *stack);
void	handle_small_chunks(t_stack *stack);
int		*rem_update_array(int *nbrs_sorted, size_t size, size_t pushed);
void	init_struct(t_stack *stack);
void	sort_6(t_stack *stack, size_t last_pushed_to_add);
void	sort_6_push_rotate(t_stack *stack, size_t *rotated, size_t *pushed);
void	sort_12(t_stack *stack);
void	handle_big_chunks(t_stack *stack);
void	push_big_chunks_pa(t_stack *stack);
int		*add_update_array(int *dst, size_t dst_size, int *src, size_t n);
void	first_push_big_chunks_pb(t_stack *stack);
void	second_push_big_chunks_pb(t_stack *stack);
void	free_all(t_stack *stack, int *nbrs);
void	swap_nodes(t_data **head);
void	update_arrays(t_stack *stack, int flag);
void	update_arrays_2(t_stack *stack, int flag);
void	sort_4(t_stack *stack, size_t last_rotated);
void	sort_13(t_stack *stack);
void	sort_12_13_rt(t_stack *stack, int *rotated, int *remaining, int flag);
void	check_error(int *nbrs, size_t input_count, t_stack stack);
int		is_valid_number(const char *s);
int		ft_safe_atoi(const char *str, int *out);
int		check_sorted(int *nbrs, size_t input_count);
void	sort_12_13_push(t_stack *stack, int *rotated, int *can_rr);

#endif
