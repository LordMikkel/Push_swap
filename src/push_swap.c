/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 00:38:42 by migarrid          #+#    #+#             */
/*   Updated: 2025/03/27 02:25:36 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	**splitted;

	ft_args_check(ac, av);
	stack_a = ft_calloc(1, sizeof(t_stack));
	stack_b = ft_calloc(1, sizeof(t_stack));
	if (!stack_a || !stack_b)
		ft_error(NULL, stack_a, stack_b);
	splitted = ft_args_process(ac, av, stack_a);
	if (!splitted)
		ft_error(NULL, stack_a, stack_b);
	/*stack_a->stack = ft_args_parser(splitted, stack_a);
	if (!stack_a->stack)
		ft_error(splitted, stack_a, stack_b);
	*//*stack_b->stack = ft_calloc(stack_a->size, sizeof(int));
	if (!stack_b->stack)
		ft_error (splitted, stack_a, stack_b);
	*/stack_b->size = 0;
	/*if (!ft_is_sorted(stack_a))
		ft_init_sort(stack_a, stack_b);
	*/return (ft_free_all_stacks(stack_a, stack_b), 0);
}
