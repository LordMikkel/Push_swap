/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 16:21:58 by migarrid          #+#    #+#             */
/*   Updated: 2025/03/29 18:55:08 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <limits.h>
# include "../lib/libft_plus.h"

// -------------- Structure (Principal) ----------------
typedef struct s_stack
{
	int	*stack;
	int	size;
	int	max_size;
	int	middle;
}	t_stack;

// ----------- Principal (Algortimo) ------------
/*
 *	Parser
 */

int		ft_args_check(int ac, char **av);
char	**ft_args_process(int ac, char **av, t_stack *stack_a);
int		*ft_args_parser(char **splitted, t_stack *stack_a);

/*
 *	Algorithm
 */

void	ft_init_sort(t_stack *stack_a, t_stack *stack_b);

/*
 *	Sort Utils
 */

int		ft_is_sorted(t_stack *stack_a);

/*
 *	Exit Utils
 */

void	ft_error(t_stack *stack_a, t_stack *stack_b);
void	ft_free_all_stacks(t_stack *stack_a, t_stack *stack_b);
void	ft_free_splitted(char **splitted);

/*
 *	Instructions
 */

// -------------- Bonus (Checker) ---------------

#endif
