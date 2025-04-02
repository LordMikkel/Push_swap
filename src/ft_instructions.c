/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_instructions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 23:47:10 by migarrid          #+#    #+#             */
/*   Updated: 2025/04/02 17:58:12 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_do_pa(t_stack *stack_a, t_stack *stack_b)
{
	int	tmp;

	if (stack_b->size == 0)
		return ;
	stack_a->size += 1;
	stack_b->size -= 1;
	tmp = stack_b->stack[0];
	ft_memmove(stack_b->stack, stack_b->stack + 1, stack_b->size * sizeof(int));
	ft_memmove(stack_a->stack + 1, stack_a->stack, stack_a->size * sizeof(int));
	stack_a->stack[0] = tmp;
	ft_print_instructions("pa");
}

void	ft_do_pb(t_stack *stack_a, t_stack *stack_b)
{
	int	tmp;

	if (stack_a->size == 0)
		return ;
	stack_a->size -= 1;
	stack_b->size += 1;
	tmp = stack_a->stack[0];
	ft_memmove(stack_a->stack, stack_a->stack + 1, stack_a->size * sizeof(int));
	ft_memmove(stack_b->stack + 1, stack_b->stack, stack_b->size * sizeof(int));
	stack_b->stack[0] = tmp;
	ft_print_instructions("pb");
}

void	ft_do_swap(t_stack *stack, char c)
{
	int	tmp;

	if (stack->size < 2)
		return ;
	tmp = stack->stack[0];
	stack->stack[0] = stack->stack[1];
	stack->stack[1] = tmp;
	if (c == 'a')
		ft_print_instructions("sa");
	else if (c == 'b')
		ft_print_instructions("sb");
}

void	ft_do_rotate(t_stack *stack, char c)
{
	int	tmp;

	if (stack->size < 2)
		return ;
	tmp = stack->stack[0];
	ft_memmove(stack->stack, stack->stack + 1, stack->size * sizeof(int));
	stack->stack[stack->size - 1] = tmp;
	if (c == 'a')
		ft_print_instructions("ra");
	else if (c == 'b')
		ft_print_instructions("rb");
}

void	ft_do_reverse_rotate(t_stack *stack, char c)
{
	int	tmp;

	if (stack->size < 2)
		return ;
	tmp = stack->stack[stack->size - 1];
	ft_memmove(stack->stack + 1, stack->stack, stack->size * sizeof(int));
	stack->stack[0] = tmp;
	if (c == 'a')
		ft_print_instructions("rra");
	else if (c == 'b')
		ft_print_instructions("rrb");
}
