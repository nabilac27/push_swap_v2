/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchairun <nchairun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 07:26:17 by nchairun          #+#    #+#             */
/*   Updated: 2025/03/09 23:41:59 by nchairun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	get_index(t_stack *stack)
{
	int	i;
	int	median;

	i = 0;
	median = count_stack_len(stack) / 2;
	while (stack)
	{
		stack->index = i;
		if (i <= median)
			stack->median = true;
		else
			stack->median = false;
		stack = stack->next;
		i++;
	}
}

void	get_target_stack_b(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*target_node;
	t_stack	*temp_stack_b;
	int		check_target_value;

	while (stack_a)
	{
		target_node = NULL;
		check_target_value = INT_MIN;
		temp_stack_b = stack_b;
		while (temp_stack_b)
		{
			if (temp_stack_b->value < stack_a->value
				&& temp_stack_b->value > check_target_value)
			{
				check_target_value = temp_stack_b->value;
				target_node = temp_stack_b;
			}
			temp_stack_b = temp_stack_b->next;
		}
		if (target_node)
			stack_a->target = target_node;
		else
			stack_a->target = find_value(stack_b, FIND_MAX_VALUE);
		stack_a = stack_a->next;
	}
}

void	calc_cost(t_stack *stack_a, t_stack *stack_b)
{
	int	stack_a_len;
	int	stack_b_len;

	stack_a_len = count_stack_len(stack_a);
	stack_b_len = count_stack_len(stack_b);
	while (stack_a)
	{
		stack_a->move_cost = stack_a->index;
		if (stack_a->median == false)
			stack_a->move_cost = stack_a_len - (stack_a->index);
		if (stack_a->median == true)
			stack_a->move_cost = stack_a->move_cost + (stack_b_len
					- stack_a->target->index);
		else
			stack_a->move_cost = stack_a->move_cost + stack_a->target->index;
		stack_a = stack_a->next;
	}
}

void	get_cheapest(t_stack *stack_a)
{
	int		cheapest;
	t_stack	*temp;

	cheapest = INT_MAX;
	while (stack_a)
	{
		if (stack_a->move_cost < cheapest)
		{
			cheapest = stack_a->move_cost;
			temp = stack_a;
		}
		stack_a = stack_a->next;
	}
	temp->cheapest_move = true;
}
