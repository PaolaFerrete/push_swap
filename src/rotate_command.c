/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paola <paola@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 10:07:07 by utente            #+#    #+#             */
/*   Updated: 2024/05/15 14:18:03 by paola            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
/*
 * Top node to bottom position
*/
static void	rotate(t_stack_node **stack)
{
	t_stack_node	*last_node;
	int				len;

	len = stack_len(*stack);
	if (NULL == stack || NULL == *stack || 1 == len)
		return ;
	last_node = find_last_node(*stack);
	last_node->next = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	last_node->next->prev = last_node;
	last_node->next->next = NULL;
}

void	ra(t_stack_node **a, bool checker)
{
	rotate(a);
	if (!checker)
		printf("ra\n");
}

void	rb(t_stack_node **b, bool checker)
{
	rotate(b);
	if (!checker)
		printf("rb\n");
}

void	rr(t_stack_node **a, t_stack_node **b, bool checker)
{
	rotate(a);
	rotate(b);
	if (!checker)
	{
		printf("rr\n");
	}
}
