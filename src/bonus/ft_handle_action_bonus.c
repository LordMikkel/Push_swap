/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_action_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 02:19:19 by migarrid          #+#    #+#             */
/*   Updated: 2025/04/12 03:02:26 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int	ft_handle_pushes(char *action, t_stack *stack_a, t_stack *stack_b)
{
	int	control;

	if (!ft_strcmp(action, "pa"))
	{
		ft_do_pa_bonus(stack_a, stack_b);
		control = 1;
	}
	else if (!ft_strcmp(action, "pb"))
	{
		ft_do_pb_bonus(stack_a, stack_b);
		control = 1;
	}
	return (control);
}

static int	ft_handle_swaps(char *action, t_stack *stack_a, t_stack *stack_b)
{
	int	control;

	if (!ft_strcmp(action, "sa"))
	{
		ft_do_swap_bonus(stack_a);
		control = 1;
	}
	else if (!ft_strcmp(action, "sb"))
	{
		ft_do_swap_bonus(stack_b);
		control = 1;
	}
	else if (!ft_strcmp(action, "ss"))
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

	if (!ft_strcmp(action, "ra"))
	{
		ft_do_rotate_bonus(stack_a);
		control = 1;
	}
	else if (!ft_strcmp(action, "rb"))
	{
		ft_do_rotate_bonus(stack_b);
		control = 1;
	}
	else if (!ft_strcmp(action, "rr"))
	{
		ft_do_rotate_bonus(stack_a);
		ft_do_rotate_bonus(stack_b);
		control = 1;
	}
	return (control);
}

static int	ft_handle_reverse_rotates(char *action, t_stack *stack_a, t_stack *stack_b)
{
	int	control;

	if (!ft_strcmp(action, "rra"))
	{
		ft_do_reverse_rotate_bonus(stack_a);
		control = 1;
	}
	else if (!ft_strcmp(action, "rrb"))
	{
		ft_do_reverse_rotate_bonus(stack_b);
		control = 1;
	}
	else if (!ft_strcmp(action, "rrr"))
	{
		ft_do_reverse_rotate_bonus(stack_a);
		ft_do_reverse_rotate_bonus(stack_b);
		control = 1;
	}
	return (control);
}

void	ft_handle_action(char *action, t_stack *stack_a, t_stack *stack_b)
{
	int control = 0;

	control += ft_handle_pushes(action, stack_a, stack_b);
	control += ft_handle_swaps(action, stack_a, stack_b);
	control += ft_handle_rotates(action, stack_a, stack_b);
	control += ft_handle_reverse_rotates(action, stack_a, stack_b);
	free(action);
	if (!control)
		ft_error(stack_a, stack_b);
}
