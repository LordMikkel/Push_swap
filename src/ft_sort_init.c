/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 18:47:16 by migarrid          #+#    #+#             */
/*   Updated: 2025/03/30 00:29:18 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	ft_sort_two(t_stack *stack_a, t_stack *stack_b)
{
	ft_do_swap(stack_a, 'a');
}

static void	ft_sort_three(t_stack *stack_a, t_stack *stack_b)
{
}

static void	ft_sort_five(t_stack *stack_a, t_stack *stack_b)
{
}

void	ft_init_sort(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->size == 2)
		ft_sort_two(stack_a, stack_b);
	else if (stack_a->size == 5)
		ft_sort_three(stack_a, stack_b);
	else if (stack_a->size <= 5)
		ft_sort_five(stack_a, stack_b);
	else if (stack_a->size <= 120)
		ft_chunk_sort(stack_a, stack_b, 18);
	else
		ft_chunk_sort(stack_a, stack_b, 50);
	ft_print_instructions("");
}
