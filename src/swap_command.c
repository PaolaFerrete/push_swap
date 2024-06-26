/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paola <paola@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 09:53:41 by utente            #+#    #+#             */
/*   Updated: 2024/05/22 10:04:29 by paola            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*
 * reverses the positions of the two first nodes
 	* head = (*head)->next; ~point to second
	* (*head)->prev->prev = *head; ~prev first point to second
	* (*head)->prev->next = (*head)->next; ~second next point to first
	* if ((*head)->next)
	*	(*head)->next->prev = (*head)->prev; ~first next point to third
	* (*head)->next = (*head)->prev; ~second next point to first
	* (*head)->prev = NULL; ~second prev recive null

*/
static void	swap(t_stack_node **head)
{
	int	len;

	len = stack_len(*head);
	if (NULL == *head || NULL == head || 1 == len)
		return ;
	*head = (*head)->next;
	(*head)->prev->prev = *head;
	(*head)->prev->next = (*head)->next;
	if ((*head)->next)
		(*head)->next->prev = (*head)->prev;
	(*head)->next = (*head)->prev;
	(*head)->prev = NULL;
}

void	sa(t_stack_node	**a, bool checker)
{
	swap(a);
	if (!checker)
		ft_putstr_fd("sa\n", 1);
}

void	sb(t_stack_node **b, bool checker)
{
	swap(b);
	if (!checker)
		ft_putstr_fd("sb\n", 1);
}

void	ss(t_stack_node **a, t_stack_node **b, bool checker)
{
	swap(a);
	swap(b);
	if (!checker)
		ft_putstr_fd("ss\n", 1);
}
