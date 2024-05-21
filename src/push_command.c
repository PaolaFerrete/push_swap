/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paola <paola@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 10:36:47 by utente            #+#    #+#             */
/*   Updated: 2024/05/21 14:02:51 by paola            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 * Push a node to the top from src to dest
 * 🚨 attention If stack empty (i.e. NULL)
*/
static void	push(t_stack_node **dest, t_stack_node **src)
{
	t_stack_node	*node_to_push;

	if (NULL == *src)
		return ;
	node_to_push = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	node_to_push->prev = NULL;
	if (NULL == *dest)
	{
		*dest = node_to_push;
		node_to_push->next = NULL;
	}
	else
	{
		node_to_push->next = *dest;
		node_to_push->next->prev = node_to_push;
		*dest = node_to_push;
	}
}

void	pa(t_stack_node **a, t_stack_node **b, bool checker)
{
	push(a, b);
	if (!checker)
		ft_putstr_fd("pa\n", 1);
}

void	pb(t_stack_node **b, t_stack_node **a, bool checker)
{
	push(b, a);
	if (!checker)
		ft_putstr_fd("pb\n", 1);
}
