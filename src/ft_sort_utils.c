/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 14:25:22 by migarrid          #+#    #+#             */
/*   Updated: 2025/04/10 23:00:23 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_find_min_num(t_stack *stack)
{
	int	i;
	int	min;

	i = 0;
	min = stack->stack[0];
	while (i < stack->size)
	{
		if (stack->stack[i] < min)
			min = stack->stack[i];
		i++;
	}
	return (min);
}

int	ft_find_max_num(t_stack *stack)
{
	int	i;
	int	max;

	i = 0;
	max = stack->stack[0];
	while (i < stack->size)
	{
		if (stack->stack[i] > max)
			max = stack->stack[i];
		i++;
	}
	return (max);
}

void	ft_move_min_num_to_top(t_stack *stack, char c)
{
	int	i;
	int	min;

	i = 0;
	min = ft_find_min_num(stack);
	while (stack->stack[i] != min)
		i++;
	if (i < stack->size / 2)
	{
		while (stack->stack[0] != min)
			ft_do_rotate(stack, c);
	}
	else
	{
		while (stack->stack[0] != min)
			ft_do_reverse_rotate(stack, c);
	}
}

void	ft_move_max_num_to_top(t_stack *stack, char c)
{
	int	i;
	int	max;

	i = 0;
	max = ft_find_max_num(stack);
	while (stack->stack[i] != max)
		i++;
	if (i < stack->size / 2)
	{
		while (stack->stack[0] != max)
			ft_do_rotate(stack, c);
	}
	else
	{
		while (stack->stack[0] != max)
			ft_do_reverse_rotate(stack, c);
	}
}

int	ft_get_optimal_chunk_size(int total)
{
	int	chunk_size;

	if (total <= 10)
		chunk_size = total;
	else if (total <= 100)
		chunk_size = total / 5;
	else
		chunk_size = total / 10;
	return (chunk_size);
}
