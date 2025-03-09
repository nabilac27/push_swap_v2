/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchairun <nchairun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 23:57:39 by nchairun          #+#    #+#             */
/*   Updated: 2025/03/09 23:14:43 by nchairun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	**input_num;

	stack_a = NULL;
	stack_b = NULL;
	input_num = check_valid_args(argc, argv);
	if (!input_num)
		return (0);
	fill_stack_a(&stack_a, input_num);
	if (check_sorted_stack(stack_a) == false)
	{
		if (count_stack_len(stack_a) == 2)
			sa(stack_a);
		else if (count_stack_len(stack_a) == 3)
			sort_3(&stack_a);
		else
			turk_algorithm(&stack_a, &stack_b);
	}
	free_stack(&stack_a);
	return (0);
}

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

bool	check_sorted_stack(t_stack *stack)
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
	return (len);
}
