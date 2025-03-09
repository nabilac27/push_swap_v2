/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchairun <nchairun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 06:54:48 by nchairun          #+#    #+#             */
/*   Updated: 2025/03/09 23:41:16 by nchairun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	turk_algorithm(t_stack **stack_a, t_stack **stack_b)
{
	int	len;

	len = count_stack_len(*stack_a);
	if (len-- > 3)
		pb(stack_b, stack_a);
	if (len-- > 3 && (check_sorted_stack(*stack_a) == false))
		pb(stack_b, stack_a);
	// while (len-- > 3 && (check_sorted_stack(*stack_a) == false))
	// {
	// 	calc_moves_fill_stack_b(*stack_a, *stack_b);
	// 	fill_stack_b(stack_a, stack_b);
	// }
	// sort_3(stack_a);
	// while (*stack_b)
	// {
	// 	calc_moves_fill_back_stack_a(*stack_a, *stack_b);
	// 	fill_back_stack_a(stack_a, stack_b);
	// }
	// final_sort(stack_a);
}
