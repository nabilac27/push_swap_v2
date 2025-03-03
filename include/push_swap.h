/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchairun <nchairun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 21:02:30 by nchairun          #+#    #+#             */
/*   Updated: 2025/03/03 22:03:46 by nchairun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../lib/ft_printf/ft_printf.h"
# include "../lib/libft/libft.h"
# include <limits.h>
# include <stdbool.h>
# include <stdio.h>

typedef struct s_stack_node
{
	int					num;
	int					index;
	int					push_moves;
	// bool				above_median;
	// bool				cheapest_moves;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
	struct s_stack_node	*target;
}						t_stack_node;

/**** 			MAIN			 ****/
// main.c
char					**split_and_convert(char *input, int **numbers,
							int *count);
void					free_split(char **array);

// main_helper.c
bool					validate_and_add_to_stack(char **argv_num,
							t_stack_node **stack_a);
bool					check_valid_num(const char *str);
bool					check_duplicate(t_stack_node *stack, int num);
void					add_node_to_stack(t_stack_node **stack, int num);
int						count_stack_len(t_stack_node *stack);

// fill_stack.c
void					fill_stack(t_stack_node **stack_a, char **argv);
long					ft_atol(char *str);
bool					stack_sorted(t_stack_node *stack);

// error_and_free.c
void					error_message(t_stack_node **a);
void					free_stack(t_stack_node **stack);

/**** 			OPERATION			 ****/
// ps_push.c
void					push(t_stack_node **dst, t_stack_node **src);
void					pa(t_stack_node **stack_a, t_stack_node **stack_b);
void					pb(t_stack_node **stack_b, t_stack_node **stack_a);

// ps_rev_rotate.c
void					rev_rotate(t_stack_node **stack);
void					rra(t_stack_node **stack_a);
void					rrb(t_stack_node **stack_b);
void					rrr(t_stack_node **stack_a, t_stack_node **stack_b);

// ps_rotate.c
void					rotate(t_stack_node **node);
void					ra(t_stack_node **stack_a);
void					rb(t_stack_node **stack_b);
void					rr(t_stack_node **stack_a, t_stack_node **stack_b);

// ps_swap.c
void					swap(t_stack_node **node);
void					sa(t_stack_node **stack_a);
void					sb(t_stack_node **stack_b);
void					ss(t_stack_node **stack_a, t_stack_node **stack_b);

/****			TURK_ALGORITHM 			****/

#endif
