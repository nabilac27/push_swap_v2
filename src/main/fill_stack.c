/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchairun <nchairun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 21:40:15 by nchairun          #+#    #+#             */
/*   Updated: 2025/03/03 22:09:12 by nchairun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

// void	fill_stack(t_stack_node **stack_a, char **argv)
// {
// 	long	n;
// 	int		i;
	
// 	i = 0;
// 	if (!argv || argv[i] == NULL)
// 		return ;
// 	while (argv[i])
// 	{
// 		if (check_valid_num(argv[i]) == false)
// 			error_message(stack_a);
// 		n = ft_atol(argv[i]);
// 		if (n > INT_MAX || n < INT_MIN)
// 			error_message(stack_a);
// 		if (check_duplicate(*stack_a, n) == false)
// 			error_message(stack_a);
// 		add_node_to_stack(stack_a, (int)n);
// 		i++;
// 	}
// }

long	ft_atol(char *str)
{
	int		sign;
	long	num;
	int		x;

	sign = 1;
	num = 0;
	x = 0;
	while (str[x] == ' ' || (str[x] >= '\t' && str[x] <= '\r'))
		x++;
	if (str[x] == '+' || str[x] == '-')
	{
		if (str[x] == '-')
			sign = -1;
		x++;
	}
	while (str[x] >= '0' && str[x] <= '9')
	{
		num = num * 10 + (str[x] - '0');
		x++;
	}
	return (sign * num);
}

bool	stack_sorted(t_stack_node *stack)
{
	if (!stack)
		return (0);
	while (stack->next)
	{
		if (stack->num >= stack->next->num)
			return (true);
		stack = stack->next;
	}
	return (false);
}

