/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchairun <nchairun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 03:36:42 by nchairun          #+#    #+#             */
/*   Updated: 2025/03/09 02:22:33 by nchairun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	fill_stack_a(t_stack **stack_a, char **num)
{
	long	long_num;
	int		i;

	i = 0;
	while (num[i])
	{
		if (!check_valid_num(num[i]))
			error_free_stack(stack_a);
		long_num = (long)ft_atoi(num[i]);
		if (long_num < INT_MIN || long_num > INT_MAX)
			error_free_stack(stack_a);
		if (!check_dup_num(*stack_a, (int)long_num))
			error_free_stack(stack_a);
		add_node_to_stack_a(stack_a, (int)long_num);
		i++;
	}
	i = 0;
	while (num[i])
	{
		free(num[i]);
		i++;
	}
}

bool	check_valid_num(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (str[i] == '+' || str[i] == '-')
		return (false);
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (false);
		i++;
	}
	return (true);
}

bool	check_dup_num(t_stack *stack_a, int current_num)
{
	while (stack_a)
	{
		if (stack_a->value == current_num)
			return (false);
		stack_a = stack_a->next;
	}
	return (true);
}

void	add_node_to_stack_a(t_stack **stack_a, int num)
{
	t_stack	*node;
	t_stack	*last_node;

	node = malloc(sizeof(t_stack));
	if (node == NULL)
		return ;
	node->value = num;
	node->next = NULL;
	node->cheapest_move = false;
	if (!(*stack_a))
	{
		node->prev = NULL;
		*stack_a = node;
	}
	else
	{
		last_node = *stack_a;
		while (last_node->next != NULL)
			last_node = last_node->next;
		last_node->next = node;
		node->prev = last_node;
	}
}
