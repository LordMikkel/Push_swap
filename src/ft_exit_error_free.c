/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit_error_free.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 18:34:17 by migarrid          #+#    #+#             */
/*   Updated: 2025/03/26 23:19:47 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_free_all_stacks(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a)
	{
		free(stack_a->stack);
		free(stack_a);
	}
	if (stack_b)
	{
		free(stack_b->stack);
		free(stack_b);
	}
}

void	ft_error(char **splitted, t_stack *stack_a, t_stack *stack_b)
{
	int	i;

	i = 0;
	ft_free_all_stacks(stack_a, stack_b);
	if (splitted)
	{
		while (splitted[i])
			free(splitted[i++]);
		free(splitted);
	}
	ft_putstr_fd("Error\n", 2);
	exit(EXIT_FAILURE);
}
