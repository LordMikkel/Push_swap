/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_args_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 18:38:16 by migarrid          #+#    #+#             */
/*   Updated: 2025/03/26 18:42:19 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"


void ft_check_args(int ac, char **av)
{
	int	i;

	i = 0;
	while(i < ac)
	{
		if (av[i][0] == '\0')
			ft_error(NULL, NULL, NULL);
		i++;
	}
	i = 0;
	while ( i < ac)
	{
		if (ft_is_only_spaces(av[i]))
			ft_error(NULL, NULL, NULL);
		ft_are_args_valid(av[i]);
		i++;
	}
}
