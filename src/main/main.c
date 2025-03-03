/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchairun <nchairun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 21:04:17 by nchairun          #+#    #+#             */
/*   Updated: 2025/03/03 22:09:37 by nchairun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

// void check_leaks(void)
// {
//  pid_t   pid;
//  char    cmd[256];

//  pid = getpid();
//  snprintf(cmd, sizeof(cmd), "leaks %d", pid);
//  system(cmd);
// }

int	main(int argc, char *argv[])
{
	t_stack_node	*stack_a;
	t_stack_node	*stack_b;
	char			**argv_num;
	int				*int_num;
	int				num;
	int				stack_len;
	int				i;

	argv_num = NULL;
	int_num = NULL;
	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2 || argv[1] == NULL)
		return (0);
	if (argc == 2)
	{
		argv_num = split_and_convert(argv[1], &int_num, &num);
		if (!(argv_num))
			return (1);
	}
	else
	{
		i = 0;
		argv_num = argv + 1;
		num = argc - 1;
		int_num = malloc(sizeof(int) * num);
		if (!int_num)
			return (1);
		while (i < num)
		{
			int_num[i] = ft_atoi(argv_num[i]);
			i++;
		}
	}
	if (!(validate_and_add_to_stack(argv_num, &stack_a)))
	{
		if (argc == 2)
			free_split(argv_num);
		free(int_num);
		return (1);
	}
	// fill_stack(&stack_a, argv + 1);
	stack_len = count_stack_len(stack_a);
	if ((stack_len == 2) && (stack_sorted(stack_a) == false))
		sa(&stack_a);
	/*
			if 3 --> sort 3
			else --> turk_algorithm
	*/
	if (argc == 2)
		free_split(argv_num);
	else
		free(int_num);
	// atexit(check_leaks);
	return (0);
}

char	**split_and_convert(char *input, int **int_num, int *num)
{
	char	**argv;
	int		i;

	argv = ft_split(input, ' ');
	i = 0;
	while (argv[i] != NULL)
		i++;
	*num = i;
	*int_num = malloc(sizeof(int) * i);
	if (!*int_num)
	{
		free_split(argv);
		return (NULL);
	}
	i = 0;
	while (argv[i] != NULL)
	{
		(*int_num)[i] = ft_atoi(argv[i]);
		i++;
	}
	return (argv);
}

void	free_split(char **array)
{
	int	i;

	i = 0;
	while (array[i] != NULL)
		free(array[i++]);
	free(array);
}

// bool	is_sorted(t_stack_node *stack)
// {
// 	while (stack && stack->next)
// 	{
// 		if (stack->num > stack->next->num)
// 			return (false);
// 		stack = stack->next;
// 	}
// 	return (true);
// }
