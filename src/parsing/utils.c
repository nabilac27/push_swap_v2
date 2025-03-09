/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchairun <nchairun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 08:00:31 by nchairun          #+#    #+#             */
/*   Updated: 2025/03/09 23:40:49 by nchairun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	sort_3(t_stack **stack_a)
{
	t_stack	*max;

	max = find_value(*stack_a, FIND_MAX_VALUE);
	if (max == *stack_a)
		ra(stack_a);
	else if ((*stack_a)->next == max)
		rra(stack_a);
	if ((*stack_a)->value > (*stack_a)->next->value)
		sa(*stack_a);
}

t_stack	*find_value(t_stack *stack, t_value value_type)
{
    int		value;
    t_stack	*find_value;

    if (value_type == FIND_MIN_VALUE)
        value = INT_MAX;
    else
        value = INT_MIN;
    while (stack)
    {
        if ((value_type == FIND_MIN_VALUE && value >= stack->value) ||
            (value_type == FIND_MAX_VALUE && value <= stack->value))
        {
            value = stack->value;
            find_value = stack;
        }
        stack = stack->next;
    }
    return (find_value);
}

void	free_stack(t_stack **stack)
{
	t_stack	*temp;

	if (!stack || !(*stack))
		return ;
	while (*stack)
	{
		temp = (*stack)->next;
		free(*stack);
		*stack = temp;
	}
	*stack = NULL;
}

void	error_free_stack(t_stack **stack)
{
	free_stack(stack);
	write(2, "Error\n", 6);
	exit(1);
}