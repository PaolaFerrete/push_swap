/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paola <paola@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 20:57:22 by utente            #+#    #+#             */
/*   Updated: 2024/05/21 17:16:07 by paola            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	msg_error(void)
{
	ft_putstr_fd("Error\n", 2);
}

/*
 * Matrix starts from -1
 * because i artificially made Up
 * equal to argv
*/
void	error_free(t_stack_node **a, char **argv, bool flag)
{
	free_stack(a);
	if (flag)
		free_matrix(argv);
	msg_error();
	exit(1);
}

/*
 * Check if there are some syntactical mistakes
*/
int	error_syntax(char *str_nbr)
{
	if (!(*str_nbr == '+'
			|| *str_nbr == '-'
			|| (*str_nbr >= '0' && *str_nbr <= '9')))
		return (1);
	if ((*str_nbr == '+'
			|| *str_nbr == '-')
		&& !(str_nbr[1] >= '0' && str_nbr[1] <= '9'))
		return (1);
	while (*++str_nbr)
	{
		if (!(*str_nbr >= '0' && *str_nbr <= '9'))
			return (1);
	}
	return (0);
}

/*
 * Loop into the stack for some repetition
*/
int	error_repetition(t_stack_node *a, int nbr)
{
	if (NULL == a)
		return (0);
	while (a)
	{
		if (a->value == nbr)
			return (1);
		a = a->next;
	}
	return (0);
}
