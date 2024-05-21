/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_commands.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paola <paola@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 09:34:49 by paola             #+#    #+#             */
/*   Updated: 2024/05/21 10:17:46 by paola            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*
 * Top node to bottom position
	* 	last_node->next = *stack; ~third point to first
	* 	*stack = (*stack)->next; ~point to second
	* 	(*stack)->prev = NULL; ~third prev recive null
	* 	last_node->next->prev = last_node; ~first prev point to third
	* 	last_node->next->next = NULL; ~first next recive null
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
		ft_putstr_fd("ra", 1);
}

void	rb(t_stack_node **b, bool checker)
{
	rotate(b);
	if (!checker)
		ft_putstr_fd("rb", 1);
}

void	rr(t_stack_node **a, t_stack_node **b, bool checker)
{
	rotate(a);
	rotate(b);
	if (!checker)
		ft_putstr_fd("rr", 1);
}


