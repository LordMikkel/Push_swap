/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_args_parser.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 02:35:24 by migarrid          #+#    #+#             */
/*   Updated: 2025/03/29 14:20:42 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	ft_is_duplicated(int *array, int size)
{
}

int	*ft_args_parser(char **splitted, t_stack *stack_a)
{
	int	i;
	int	*array;

	i = 0;
	array = ft_calloc((stack_a->size + 1), sizeof(int));
	if (!array)
		return (NULL);
	while (splitted[i])
	{
		array[i] = ft_atoi(splitted[i]);
		if (array[i] > INT_MAX || array[i] < INT_MIN)
			return (free(array), NULL);
		i++;
	}
	if (ft_is_duplicated(array, stack_a->size))
		return (free(array), NULL);
	i = 0;
	while (splitted[i])
		free(splitted[i++]);
	free(splitted);
	return (array);
}
