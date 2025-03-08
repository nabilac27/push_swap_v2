/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchairun <nchairun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 23:57:39 by nchairun          #+#    #+#             */
/*   Updated: 2025/03/08 08:58:03 by nchairun         ###   ########.fr       */
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
	if (sorted_stack(stack_a) == false)
	{
		// printf("%s", "not sorted");
		if (count_stack_len(stack_a) == 2)
			sa(stack_a);
		else if (count_stack_len(stack_a) == 3)
			printf("%s", "sort three");
		else
			printf("%s", "turk algorithm");
	}
	free_stack(&stack_a);
	return (0);
}

// int	main(int argc, char *argv[])
// {
// 	t_stack	*stack_a;
// 	t_stack	*stack_b;
// 	char	**input_num;

// 	stack_a = NULL;
// 	stack_b = NULL;
// 	input_num = NULL;
// 	if (argc < 2 || !argv[1])
// 		return (0);
// 	else if (argc == 2)
// 		input_num = ft_split(argv[1], ' ');
// 	else
// 		input_num = get_input_num(argv);
// 	fill_stack_a(&stack_a, input_num);
// 	if (sorted_stack(stack_a) == false)
// 	{
// 		// printf("%s", "not sorted");
// 		if (count_stack_len(stack_a) == 2)
// 			sa(stack_a);
// 		else if (count_stack_len(stack_a) == 3)
// 			printf("%s", "sort three");
// 		else
// 			printf("%s", "turk algorithm");
// 	}
// 	free_stack(&stack_a);
// 	return (0);
// }