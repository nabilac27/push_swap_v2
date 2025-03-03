/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchairun <nchairun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 16:07:34 by nchairun          #+#    #+#             */
/*   Updated: 2025/02/08 21:11:29 by nchairun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	rotate(t_stack_node **node)
{
	t_stack_node	*last;
	t_stack_node	*new_node;

	last = *node;
	while (last->next != NULL)
		last = last->next;
	new_node = (*node)->next;
	new_node->prev = NULL;
	last->next = *node;
	(*node)->next = NULL;
	(*node)->prev = last;
	*node = new_node;
}

void	ra(t_stack_node **stack_a)
{
	rotate(stack_a);
	write(1, "ra\n", 3);
}

void	rb(t_stack_node **stack_b)
{
	rotate(stack_b);
	write(1, "rb\n", 3);
}

void	rr(t_stack_node **stack_a, t_stack_node **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	write(1, "rr\n", 3);
}
