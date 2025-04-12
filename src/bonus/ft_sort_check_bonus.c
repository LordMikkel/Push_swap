/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_check_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 02:22:20 by migarrid          #+#    #+#             */
/*   Updated: 2025/04/12 02:22:23 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	ft_is_sorted(t_stack *stack_a)
{
	int	i;

	i = 0;
	while (i < stack_a->size - 1)
	{
		if (stack_a->stack[i] > stack_a->stack[i + 1])
			return (0);
		i++;
	}
	return (1);
}
