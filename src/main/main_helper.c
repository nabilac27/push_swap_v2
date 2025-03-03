/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchairun <nchairun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 16:10:33 by nchairun          #+#    #+#             */
/*   Updated: 2025/02/08 21:04:19 by nchairun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

bool	validate_and_add_to_stack(char **argv_num, t_stack_node **stack_a)
{
	int	i;
	int	num;

	i = 0;
	while (argv_num[i] != NULL)
	{
		if (check_valid_num(argv_num[i]) == false)
			return (false);
		num = ft_atoi(argv_num[i]);
		if (num < INT_MIN || num > INT_MAX || check_duplicate(*stack_a, num))
			return (false);
		add_node_to_stack(stack_a, num);
		i++;
	}
	return (true);
}

bool	check_valid_num(const char *str)
{
	if (*str == '-' || *str == '+')
		str++;
	if (!*str)
		return (false);
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (false);
		str++;
	}
	return (true);
}

bool	check_duplicate(t_stack_node *stack, int num)
{
	while (stack)
	{
		if (stack->num == num)
			return (true);
		stack = stack->next;
	}
	return (false);
}

void	add_node_to_stack(t_stack_node **stack, int num)
{
	t_stack_node	*new_node;

	new_node = malloc(sizeof(t_stack_node));
	if (!new_node)
		return ;
	new_node->num = num;
	new_node->next = *stack;
	*stack = new_node;
}

int	count_stack_len(t_stack_node *stack)
{
	int	count;

	count = 0;
	while (stack != NULL)
	{
		count++;
		stack = stack->next;
	}
	return (count);
}
