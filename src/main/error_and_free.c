/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_and_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchairun <nchairun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 21:02:21 by nchairun          #+#    #+#             */
/*   Updated: 2025/03/03 21:46:55 by nchairun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	error_message(t_stack_node **a)
{
	free_stack(a);
	write(2, "Error\n", 6);
	exit(1);
}

void	free_stack(t_stack_node **stack)
{
	t_stack_node	*tmp;
	t_stack_node	*tbf;

	if (!stack)
		return ;
	tbf = *stack;
	while (tbf)
	{
		tmp = tbf->next;
		tbf->num = 0;
		free(tbf);
		tbf = tmp;
	}
	*stack = NULL;
}
