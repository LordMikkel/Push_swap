/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_args_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 18:38:16 by migarrid          #+#    #+#             */
/*   Updated: 2025/04/11 00:51:05 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	ft_is_sign(char c)
{
	if (c == '+' || c == '-')
		return (1);
	return (0);
}

static int	ft_chars_valid(char *av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		if (!ft_isdigit(av[i]) && !ft_is_sign(av[i]) && av[i] != ' ')
			return (0);
		if (ft_is_sign(av[i]))
		{
			if (!ft_isdigit(av[i + 1]))
				return (0);
			if (i > 0 && av[i - 1] != ' ')
				return (0);
		}
		i++;
	}
	return (1);
}

static int	ft_is_only_space(char *av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		if (av[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

int	ft_args_check(int ac, char **av)
{
	int	i;

	if (ac < 2)
		exit(EXIT_FAILURE);
	i = 1;
	while (i < ac)
	{
		if (av[i][0] == '\0' || ft_is_only_space(av[i]))
			return (0);
		if (!ft_chars_valid(av[i]))
			return (0);
		i++;
	}
	return (1);
}
