/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paola <paola@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 09:52:01 by paola             #+#    #+#             */
/*   Updated: 2024/05/21 10:24:11 by paola            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include <stdlib.h>
#include <stdio.h>

/*
 * write error on the screen.
*/
void	msg_error(void)
{
	printf("MSG_ERROR\n");
	ft_putstr_fd("Error\n", 2);
}

/*
 * organizes the free memory and left the program
*/
void	error_free(t_stack_node **a, char **argv, bool flag_argc_2)
{
	free_stack(a);
	if (flag_argc_2)
		free_matrix(argv);
	msg_error();
	exit(1);
}

/*
 * Check if there are some digits mistakes
 * 1. If the first char is not valid
 * 2. If the first char is valid but the second is not
 * 3. If the all char is digits
 	* ~return 1 -> True
 	* ~return 0 -> False
*/
int	error_digit(char *str_nbr)
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
 * Check if there are some repetition number in stack value
	* ~return 1 -> True
	* ~return 0 -> False
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
