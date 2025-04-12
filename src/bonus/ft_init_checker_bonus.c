/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_checker_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 02:21:20 by migarrid          #+#    #+#             */
/*   Updated: 2025/04/12 03:01:27 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_init_checker(t_stack *stack_a, t_stack *stack_b)
{
	char	*action;

	while (1)
	{
		action = get_next_line(0);
		if (!action)
		{
			free(action);
			break ;
		}
		ft_handle_action(action, stack_a, stack_b);
	}
	if (!ft_is_sorted(stack_a) || stack_b->size)
		ft_printf("KO\n");
	else
		ft_printf("OK\n");
}
