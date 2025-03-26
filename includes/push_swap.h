/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 16:21:58 by migarrid          #+#    #+#             */
/*   Updated: 2025/03/26 18:35:40 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <limits.h>
# include "./libft_plus/libft_plus.h"


// -------------- Structure (Principal) ----------------
typedef struct s_stack
{
	int	*stack;
	int	size;
	int	max_size;
	int middle;
}	t_stack;

// ----------- Principal (Algortimo) ------------


/*
 *	Parser
 */

 void	ft_check_args(int ac, char **av);
 int	*ft_parse_args(char **splitted, t_stack *stack);
 char	**ft_process_args(int	ac, char **av, t_stack *stack);

/*
 *	Algorithm
 */

/*
 *	Sort Utils
 */

/*
 *	Exit Utils
 */
void	ft_exit(t_stack *stack_a, t_stack *stack_b);
void	ft_error(char **splitted, t_stack *stack_a, t_stack *stack_b);
void	ft_free_all_stacks(t_stack *stack_a, t_stack *stack_b);

/*
 *	Instructions
 */

// -------------- Bonus (Checker) ---------------

#endif
