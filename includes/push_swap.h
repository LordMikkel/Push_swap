/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 16:21:58 by migarrid          #+#    #+#             */
/*   Updated: 2025/04/13 14:21:00 by migarrid         ###   ########.fr       */
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
	int	pivot;
}	t_stack;

// ----------- Principal (Algoritmo) ------------
/*
 *	Parser
 */

int		ft_args_check(int ac, char **av);
char	**ft_args_split(int ac, char **av, t_stack *stack_a);
int		*ft_args_array(char **splitted, t_stack *stack_a);

/*
 *	Algorithm
 */

void	ft_init_sort(t_stack *stack_a, t_stack *stack_b);
void	ft_chunk_sort(t_stack *stack_a, t_stack *stack_b, int chunk_size);

/*
 *	Sort Utils and helpers
 */

int		ft_is_sorted(t_stack *stack_a);
int		ft_get_optimal_chunk_size(int total);
int		ft_find_min_num(t_stack *stack);
int		ft_find_max_num(t_stack *stack);
int		ft_get_index_num(t_stack *stack, int num);
int		ft_find_next_min_num(t_stack *stack, int min);
int		ft_find_next_max_num(t_stack *stack, int max);
void	ft_move_min_num_to_top(t_stack *stack, char c);
void	ft_move_max_num_to_top(t_stack *stack, char c);
void	ft_move_num_to_top(t_stack *stack, int num, char c);
void	ft_move_top_and_push_to_a(t_stack *a, t_stack *b, int first, int sec);

/*
 *	Exit Utils
 */

void	ft_error(t_stack *stack_a, t_stack *stack_b);
void	ft_free_all_stacks(t_stack *stack_a, t_stack *stack_b);
void	ft_free_splitted(char **splitted);

/*
 *	Instructions
 */

void	ft_print_instructions(char *action);
void	ft_do_swap(t_stack *stack, char c);
void	ft_do_rotate(t_stack *stack, char c);
void	ft_do_reverse_rotate(t_stack *stack, char c);
void	ft_do_pa(t_stack *stack_a, t_stack *stack_b);
void	ft_do_pb(t_stack *stack_a, t_stack *stack_b);

// -------------- Bonus (Checker) ---------------
/*
 *	Bonus
 */

void	ft_error_gnl(t_stack *stack_a, t_stack *stack_b);
void	ft_init_checker(t_stack *stack_a, t_stack *stack_b);
void	ft_handle_action(char *action, t_stack *stack_a, t_stack *stack_b);
void	ft_do_swap_bonus(t_stack *stack);
void	ft_do_rotate_bonus(t_stack *stack);
void	ft_do_reverse_rotate_bonus(t_stack *stack);
void	ft_do_pa_bonus(t_stack *stack_a, t_stack *stack_b);
void	ft_do_pb_bonus(t_stack *stack_a, t_stack *stack_b);

#endif
