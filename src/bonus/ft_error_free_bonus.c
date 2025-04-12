/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_free_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 02:22:04 by migarrid          #+#    #+#             */
/*   Updated: 2025/04/12 02:22:06 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_free_splitted(char **splitted)
{
	int	i;

	i = 0;
	if (splitted)
	{
		while (splitted[i])
		{
			free(splitted[i]);
			i++;
		}
		free(splitted);
	}
}

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

void	ft_error(t_stack *stack_a, t_stack *stack_b)
{
	ft_free_all_stacks(stack_a, stack_b);
	ft_putstr_fd("Error\n", 2);
	exit(EXIT_FAILURE);
}
