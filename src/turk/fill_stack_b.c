/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchairun <nchairun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 09:31:18 by nchairun          #+#    #+#             */
/*   Updated: 2025/03/09 23:44:01 by nchairun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	calc_moves_fill_stack_b(t_stack *stack_a, t_stack *stack_b)
{
	get_index(stack_a);
	get_index(stack_b);
	get_target_stack_b(stack_a, stack_b);
	calc_cost(stack_a, stack_b);
	get_cheapest(stack_a);
}
