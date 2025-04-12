/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 17:02:54 by migarrid          #+#    #+#             */
/*   Updated: 2025/04/12 02:59:10 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	**splitted;

	if (!ft_args_check(ac, av))
		ft_error(NULL, NULL);
	stack_a = ft_calloc(1, sizeof(t_stack));
	stack_b = ft_calloc(1, sizeof(t_stack));
	if (!stack_a | !stack_b)
		ft_error(stack_a, stack_b);
	splitted = ft_args_split(ac, av, stack_a);
	if (!splitted)
		ft_error(stack_a, stack_b);
	stack_a->stack = ft_args_array(splitted, stack_a);
	ft_free_splitted(splitted);
	if (!stack_a->stack)
		ft_error(stack_a, stack_b);
	stack_b->size = 0;
	ft_init_checker(stack_a, stack_b);
	return (ft_free_all_stacks(stack_a, stack_b), 0);
}
