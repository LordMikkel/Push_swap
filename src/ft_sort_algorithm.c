/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_algorithm.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 21:44:33 by migarrid          #+#    #+#             */
/*   Updated: 2025/04/08 15:40:15 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	ft_push_b_to_a(t_stack *stack_a, t_stack *stack_b)
{
	while (stack_b->size)
	{
		ft_do_pa(stack_a, stack_b);
	}
}

/*void	ft_chunk_sort(t_stack *stack_a, t_stack *stack_b, int size)
{
}*/

void	ft_insert_sort(t_stack *stack_a, t_stack *stack_b)
{
	while (stack_a->size)
	{
		ft_move_min_num_to_top(stack_a, 'a');
		ft_do_pb(stack_a, stack_b);
	}
	ft_push_b_to_a(stack_a, stack_b);
}
