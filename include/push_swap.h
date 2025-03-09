/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchairun <nchairun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 21:02:30 by nchairun          #+#    #+#             */
/*   Updated: 2025/03/09 23:45:45 by nchairun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../include/lib/ft_printf/ft_printf.h"
# include "../include/lib/libft/libft.h"
# include <limits.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_node
{
	int				value;
	int				index;

	int				move_cost;
	bool			median;
	bool			cheapest_move;

	struct s_node	*prev;
	struct s_node	*next;
	struct s_node	*target;
}					t_stack;

typedef enum e_value
{
	FIND_MIN_VALUE,
	FIND_MAX_VALUE
}					t_value;

/* **********	PARSING ********** */
// main_utils.c
char				**check_valid_args(int argc, char *argv[]);
char				**get_input_num(char **argv);
bool				check_sorted_stack(t_stack *stack);
int					count_stack_len(t_stack *stack);

// fill_stack_a.c
void				fill_stack_a(t_stack **stack_a, char **num);
bool				check_valid_num(char *str);
bool				check_dup_num(t_stack *stack_a, int current_num);
void				add_node_to_stack_a(t_stack **stack_a, int num);

// utils.c
void				sort_3(t_stack **stack_a);
t_stack				*find_value(t_stack *stack, t_value value_type);
void				free_stack(t_stack **stack);
void				error_free_stack(t_stack **stack);

/* ********** TURK ********** */
// turk.c
void				turk_algorithm(t_stack **stack_a, t_stack **stack_b);

// fill_stack_b.c
void				calc_moves_fill_stack_b(t_stack *stack_a, t_stack *stack_b);

// utils.c
void				get_index(t_stack *stack);
void				get_target_stack_b(t_stack *stack_a, t_stack *stack_b);
void				calc_cost(t_stack *stack_a, t_stack *stack_b);
void				get_cheapest(t_stack *stack_a);

/* ********** OPERATION ********** */
// push.c
void				push(t_stack **dst, t_stack **src);
void				pa(t_stack **stack_a, t_stack **stack_b);
void				pb(t_stack **stack_b, t_stack **stack_a);

// swap.c
void				swap(t_stack *stack);
void				sa(t_stack *stack_a);
void				sb(t_stack *stack_b);
void				ss(t_stack *stack_a, t_stack *stack_b);

// rotate.c
void				rotate(t_stack **stack);
void				ra(t_stack **stack_a);
void				rb(t_stack **stack_b);
void				rr(t_stack **a, t_stack **b);
t_stack				*get_current_end(t_stack *stack);

// rev_rotate.c
void				rev_rotate(t_stack **stack);
void				rra(t_stack **stack_a);
void				rrb(t_stack **stack_b);
void				rrr(t_stack **a, t_stack **b);

/*
	OPERATIONS
		push.c (push, pa, pb)
		swap.c (swap. sa, sb)
		rotate.c (rotate, ra, rb, rr)
		rev_rotate.c (rev_rotate, rra, rrb, rrr)

	PARSING
		main.c
		main_utils.c (error_message, free_stack, calc_stack_len, check_sorted,
			sort_3)
		handle_input.c (check_args, check_num, check_string)
		init_stacks_stack_a.c (add_input_to_node, check_int_overflow-check_dup,
			check_syntax-check_symbol, check_error, convert_to_long_int)

	SORT_TURK
		sort_utils.c (find_last_stack, find_min, find_max, find_cheapest,
			check_above_median)
		main_turk.c (main_turk)
		push_to_stack_b.c (pb-pb, min-max, find_target, calc_cost, operations)
		push_back_to_stack_a.c (min-max, pa, find_target, calc_cost,
			median-operations)
		final_sort_stack_a.c (find_min, check_above_median, operation)
*/

#endif
