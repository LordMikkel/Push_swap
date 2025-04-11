/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_checker.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 18:59:26 by migarrid          #+#    #+#             */
/*   Updated: 2025/04/11 18:59:31 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_init_checker(t_stack *stack_a, t_stack *stack_b)
{
	int	action;

	while (1)
	{
		action = get_next_line(0);
		if (!action)
			break ;
		ft_handle_action(action, stack_b, stack_b);
	}
	if (!ft_is_sorted(stack_a) || stack_b->size)
		ft_printf("KO\n");
	else
		ft_printf("OK\n");
}
