/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchairun <nchairun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 16:06:21 by nchairun          #+#    #+#             */
/*   Updated: 2025/02/08 21:11:55 by nchairun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	push(t_stack_node **dst, t_stack_node **src)
{
	t_stack_node	*tmp;

	tmp = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	tmp->next = *dst;
	if (*dst)
		(*dst)->prev = tmp;
	*dst = tmp;
	tmp->prev = NULL;
}

void	pa(t_stack_node **stack_a, t_stack_node **stack_b)
{
	push(stack_a, stack_b);
	write(1, "pa\n", 3);
}

void	pb(t_stack_node **stack_b, t_stack_node **stack_a)
{
	push(stack_b, stack_a);
	write(1, "pb\n", 3);
}
