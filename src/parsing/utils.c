/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchairun <nchairun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 01:52:37 by nchairun          #+#    #+#             */
/*   Updated: 2025/03/08 08:58:10 by nchairun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

char	**check_valid_args(int argc, char *argv[])
{
	char	**input_num;

	if (argc < 2 || !argv[1])
		return (NULL);
	else if (argc == 2)
		input_num = ft_split(argv[1], ' ');
	else
		input_num = get_input_num(argv);
	return (input_num);
}

char	**get_input_num(char **argv)
{
	int		i;
	int		argc;
	char	**input_num;

	i = 0;
	argc = 0;
	while (argv[argc])
		argc++;
	input_num = (char **)malloc(sizeof(char *) * argc);
	if (!input_num)
		return (NULL);
	while (argv[i + 1])
	{
		input_num[i] = ft_strdup(argv[i + 1]);
		if (!input_num[i])
		{
			while (i > 0)
				free(input_num[--i]);
			free(input_num);
			return (NULL);
		}
		i++;
	}
	input_num[i] = NULL;
	return (input_num);
}

int	count_stack_len(t_stack *stack)
{
	int	len;

	len = 0;
	if (!stack)
		return (0);
	while (stack)
	{
		stack = stack->next;
		len++;
	}
	// printf("len: %d", len);
	return (len);
}

bool	sorted_stack(t_stack *stack)
{
	if (!stack)
		return (false);
	while (stack->next)
	{
		if (stack->value > stack->next->value)
			return (false);
		stack = stack->next;
	}
	return (true);
}

// long	ft_atol(const char *str)
// {
//     return ((long)ft_atoi(str));
// }

// long	ft_atol(char *str)
// {
// 	int		sign;
// 	long	input_num;
// 	int		x;

// 	sign = 1;
// 	input_num = 0;
// 	x = 0;
// 	while (str[x] == ' ' || (str[x] >= '\t' && str[x] <= '\r'))
// 		x++;
// 	if (str[x] == '+' || str[x] == '-')
// 	{
// 		if (str[x] == '-')
// 			sign = -1;
// 		x++;
// 	}
// 	while (str[x] >= '0' && str[x] <= '9')
// 	{
// 		input_num = input_num * 10 + (str[x] - '0');
// 		x++;
// 	}
// 	return (sign * input_num);
// }
