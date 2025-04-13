/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_action_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 02:19:19 by migarrid          #+#    #+#             */
/*   Updated: 2025/04/13 14:21:15 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int	ft_handle_pushes(char *action, t_stack *stack_a, t_stack *stack_b)
{
	int	control;

	control = 0;
	if (!ft_strcmp(action, "pa\n"))
	{
		ft_do_pa_bonus(stack_a, stack_b);
		control = 1;
	}
	else if (!ft_strcmp(action, "pb\n"))
	{
		ft_do_pb_bonus(stack_a, stack_b);
		control = 1;
	}
	return (control);
}

static int	ft_handle_swaps(char *action, t_stack *stack_a, t_stack *stack_b)
{
	int	control;

	control = 0;
	if (!ft_strcmp(action, "sa\n"))
	{
		ft_do_swap_bonus(stack_a);
		control = 1;
	}
	else if (!ft_strcmp(action, "sb\n"))
	{
		ft_do_swap_bonus(stack_b);
		control = 1;
	}
	else if (!ft_strcmp(action, "ss\n"))
	{
		ft_do_swap_bonus(stack_a);
		ft_do_swap_bonus(stack_b);
		control = 1;
	}
	return (control);
}

static int	ft_handle_rotates(char *action, t_stack *stack_a, t_stack *stack_b)
{
	int	control;

	control = 0;
	if (!ft_strcmp(action, "ra\n"))
	{
		ft_do_rotate_bonus(stack_a);
		control = 1;
	}
	else if (!ft_strcmp(action, "rb\n"))
	{
		ft_do_rotate_bonus(stack_b);
		control = 1;
	}
	else if (!ft_strcmp(action, "rr\n"))
	{
		ft_do_rotate_bonus(stack_a);
		ft_do_rotate_bonus(stack_b);
		control = 1;
	}
	return (control);
}

static int	ft_handle_reverse_rotates(char *action,
	t_stack *stack_a, t_stack *stack_b)
{
	int	control;

	control = 0;
	if (!ft_strcmp(action, "rra\n"))
	{
		ft_do_reverse_rotate_bonus(stack_a);
		control = 1;
	}
	else if (!ft_strcmp(action, "rrb\n"))
	{
		ft_do_reverse_rotate_bonus(stack_b);
		control = 1;
	}
	else if (!ft_strcmp(action, "rrr\n"))
	{
		ft_do_reverse_rotate_bonus(stack_a);
		ft_do_reverse_rotate_bonus(stack_b);
		control = 1;
	}
	return (control);
}

void	ft_handle_action(char *action, t_stack *stack_a, t_stack *stack_b)
{
	int	control;

	control = 0;
	control += ft_handle_pushes(action, stack_a, stack_b);
	control += ft_handle_swaps(action, stack_a, stack_b);
	control += ft_handle_rotates(action, stack_a, stack_b);
	control += ft_handle_reverse_rotates(action, stack_a, stack_b);
	free(action);
	if (!control)
		ft_error_gnl(stack_a, stack_b);
}
