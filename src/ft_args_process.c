/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_args_process.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 01:15:16 by migarrid          #+#    #+#             */
/*   Updated: 2025/03/29 03:21:20 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static char	*ft_strjoin_free(char *s1, char *s2)
{
	char	*tmp;

	tmp = ft_strjoin(s1, s2);
	if (!tmp)
	{
		free(s1);
		return (NULL);
	}
	free(s1);
	return (tmp);
}

static int	ft_init_array_size(char **splitted)
{
	int	size;

	size = 0;
	while (splitted[size])
		size++;
	return (size);
}

char	**ft_args_process(int ac, char **av, t_stack *stack_a)
{
	int		i;
	char	*args;
	char	**splitted;

	i = 1;
	args = ft_calloc(1, sizeof(char));
	if (!args)
		return (NULL);
	while (i < ac)
	{
		args = ft_strjoin_free(args, av[i]);
		if (!args)
			return (NULL);
		i++;
	}
	splitted = ft_split(args, ' ');
	free(args);
	if (!splitted)
		return (NULL);
	stack_a->size = ft_intit_array_size(splitted);
	stack_a->max_size = ft_intit_array_size(splitted);
	return (splitted);
}
