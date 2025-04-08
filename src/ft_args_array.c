/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_args_parser.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 02:35:24 by migarrid          #+#    #+#             */
/*   Updated: 2025/04/06 22:40:43 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	ft_is_duplicated(int *array, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (array[i] == array[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	*ft_args_array(char **splitted, t_stack *stack_a)
{
	int		i;
	long	num;
	int		*array;

	i = 0;
	array = ft_calloc((stack_a->size + 1), sizeof(int));
	if (!array)
		return (NULL);
	while (splitted[i])
	{
		num = ft_atol(splitted[i]);
		if (num > INT_MAX || num < INT_MIN)
			return (free(array), NULL);
		array[i] = (int)num;
		i++;
	}
	if (ft_is_duplicated(array, stack_a->size))
		return (free(array), NULL);
	return (array);
}
