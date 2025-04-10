/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_helper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 16:52:41 by migarrid          #+#    #+#             */
/*   Updated: 2025/04/10 21:16:28 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_get_index_num(t_stack *stack, int num)
{
	int	index;

	index = 0;
	while (index < stack->size)
	{
		if (stack->stack[index] == num)
			return (index);
		index++;
	}
	return (-1);
}

int	ft_find_next_min_num(t_stack *stack, int min)
{
	int	i;
	int	next_min;

	i = 0;
	next_min = INT_MAX;
	while (i < stack->size)
	{
		if (stack->stack[i] > min && stack->stack[i] < next_min)
			next_min = stack->stack[i];
		i++;
	}
	return (next_min);
}

int	ft_find_next_max_num(t_stack *stack, int max)
{
	int	i;
	int	next_max;

	i = 0;
	next_max = INT_MIN;
	while (i < stack->size)
	{
		if (stack->stack[i] < max && stack->stack[i] > next_max)
			next_max = stack->stack[i];
		i++;
	}
	return (next_max);
}

void	ft_move_num_to_top(t_stack *stack, int num, char c)
{
	int	index;

	index = ft_get_index_num(stack, num);
	if (index == -1)
		return ;
	if (index < stack->size / 2)
	{
		while (stack->stack[0] != num)
			ft_do_rotate(stack, c);
	}
	else
	{
		while (stack->stack[0] != num)
			ft_do_reverse_rotate(stack, c);
	}
}

void	ft_move_top_and_push_to_a(t_stack *a, t_stack *b, int first, int sec)
{
	ft_move_num_to_top(b, first, 'b');
	ft_do_pa(a, b);
	ft_move_num_to_top(b, sec, 'b');
	ft_do_pa(a, b);
}
