/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_commands.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paola <paola@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 09:35:21 by paola             #+#    #+#             */
/*   Updated: 2024/05/21 10:18:56 by paola            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*
 * Bottom to top
	* last->prev->next = NULL; ~second next recive null
	* last->next = *stack; ~third next point to first
	* last->prev = NULL; ~third recive null
	*stack = last; ~point to second
	* last->next->prev = last; ~second prev point to third
*/
static void	reverse_rotate(t_stack_node **stack)
{
	t_stack_node	*last;
	int				len;

	len = stack_len(*stack);
	if (NULL == *stack || NULL == stack || 1 == len)
		return ;
	last = find_last_node(*stack);
	last->prev->next = NULL;
	last->next = *stack;
	last->prev = NULL;
	*stack = last;
	last->next->prev = last;
}

void	rra(t_stack_node **a, bool checker)
{
	reverse_rotate(a);
	if (!checker)
		ft_putstr_fd("rra", 1);
}

void	rrb(t_stack_node **b, bool checker)
{
	reverse_rotate(b);
	if (!checker)
		ft_putstr_fd("rrb", 1);
}

void	rrr(t_stack_node **a, t_stack_node **b, bool checker)
{
	reverse_rotate(a);
	reverse_rotate(b);
	if (!checker)
		ft_putstr_fd("rrr", 1);
}
