/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_args_split_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 02:21:57 by migarrid          #+#    #+#             */
/*   Updated: 2025/04/12 02:21:59 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static char	*ft_strjoin_space_free(char *s1, char *s2)
{
	char	*t1;
	char	*t2;

	t1 = ft_strjoin(s1, s2);
	if (!t1)
	{
		free(s1);
		return (NULL);
	}
	free(s1);
	t2 = ft_strjoin(t1, " ");
	if (!t2)
	{
		free(t1);
		return (NULL);
	}
	free(t1);
	return (t2);
}

static int	ft_init_array_size(char **splitted)
{
	int	size;

	size = 0;
	while (splitted[size])
		size++;
	return (size);
}

char	**ft_args_split(int ac, char **av, t_stack *stack_a)
{
	int		i;
	char	*args;
	char	**splitted;

	i = 1;
	args = ft_strdup(" ");
	if (!args)
		return (NULL);
	while (i < ac)
	{
		args = ft_strjoin_space_free(args, av[i]);
		if (!args)
			return (NULL);
		i++;
	}
	splitted = ft_split(args, ' ');
	free(args);
	i = 0;
	if (!splitted)
		return (NULL);
	stack_a->size = ft_init_array_size(splitted);
	return (splitted);
}
