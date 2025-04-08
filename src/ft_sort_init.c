/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 18:47:16 by migarrid          #+#    #+#             */
/*   Updated: 2025/04/08 15:40:26 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	ft_sort_two(t_stack *stack)
{
	ft_do_swap(stack, 'a');
}

static void	ft_sort_three(t_stack *stack)
{
	if (stack->stack[2] > stack->stack[1])
	{
		if (stack->stack[2] > stack->stack[0])
			ft_do_swap(stack, 'a');
		else
			ft_do_rotate(stack, 'a');
	}
	if (stack->stack[0] > stack->stack[2])
	{
		if (stack->stack[0] > stack->stack[1])
			ft_do_swap(stack, 'a');
		ft_do_reverse_rotate(stack, 'a');
	}
	if (stack->stack[1] > stack->stack[2])
	{
		ft_do_swap(stack, 'a');
		ft_do_rotate(stack, 'a');
	}
}

static void	ft_sort_four(t_stack *stack_a, t_stack *stack_b)
{
	ft_move_min_num_to_top(stack_a, 'a');
	if (!ft_is_sorted(stack_a))
	{
		ft_do_pb(stack_a, stack_b);
		ft_sort_three(stack_a);
		ft_do_pa(stack_a, stack_b);
	}
}

static void	ft_sort_five(t_stack *stack_a, t_stack *stack_b)
{
	ft_move_min_num_to_top(stack_a, 'a');
	ft_do_pb(stack_a, stack_b);
	ft_sort_four(stack_a, stack_b);
	ft_do_pa(stack_a, stack_b);
}

void	ft_init_sort(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->size == 2)
		ft_sort_two(stack_a);
	else if (stack_a->size == 3)
		ft_sort_three(stack_a);
	else if (stack_a->size == 4)
		ft_sort_four(stack_a, stack_b);
	else if (stack_a->size == 5)
		ft_sort_five(stack_a, stack_b);
	else if (stack_a->size <= 120)
		ft_insert_sort(stack_a, stack_b);
		//ft_chunk_sort(stack_a, stack_b, 18);*/
	else
		ft_insert_sort(stack_a, stack_b);
		//ft_chunk_sort(stack_a, stack_b, 50);*/
	ft_print_instructions(NULL);
}
