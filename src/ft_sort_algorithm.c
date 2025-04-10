/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_algorithm.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 21:44:33 by migarrid          #+#    #+#             */
/*   Updated: 2025/04/10 23:00:55 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_get_first_smaller_index(t_stack *stack, int min)
{
	int	i;

	i = 0;
	while (i < stack->size)
	{
		if (stack->stack[i] <= min)
			break ;
		i++;
	}
	return (i);
}

static void	ft_merge_chunks_b_to_a(t_stack *stack_a, t_stack *stack_b)
{
	int	max;
	int	next_max;
	int	max_index;
	int	next_max_index;

	while (stack_b->size)
	{
		max = ft_find_max_num(stack_b);
		next_max = ft_find_next_max_num(stack_b, max);
		max_index = ft_get_index_num(stack_b, max);
		next_max_index = ft_get_index_num(stack_b, next_max);
		if (max_index > stack_b->size / 2)
			max_index = stack_b->size - max_index;
		if (next_max_index > stack_b->size / 2)
			next_max_index = stack_b->size - next_max_index;
		if (max_index < next_max_index)
			ft_move_top_and_push_to_a(stack_a, stack_b, max, next_max);
		else
			ft_move_top_and_push_to_a(stack_a, stack_b, next_max, max);
		if (stack_a->stack[0] > stack_a->stack[1])
			ft_do_swap(stack_a, 'a');
	}
}

void	ft_chunk_sort(t_stack *stack_a, t_stack *stack_b, int chunk_size)
{
	int	index;
	int	min_x_piv_up;
	int	elements_processed;

	while (stack_a->size)
	{
		elements_processed = 0;
		min_x_piv_up = ft_find_min_num(stack_a);
		while (elements_processed++ < chunk_size)
		{
			min_x_piv_up = ft_find_next_min_num(stack_a, min_x_piv_up);
			if (elements_processed == chunk_size / 2)
				stack_a->pivot = min_x_piv_up;
		}
		elements_processed = 0;
		while (elements_processed++ < chunk_size)
		{
			index = ft_get_first_smaller_index(stack_a, min_x_piv_up);
			ft_move_num_to_top(stack_a, stack_a->stack[index], 'a');
			ft_do_pb(stack_a, stack_b);
			if (stack_b->stack[0] < stack_a->pivot)
				ft_do_rotate(stack_b, 'b');
		}
	}
	ft_merge_chunks_b_to_a(stack_a, stack_b);
}
