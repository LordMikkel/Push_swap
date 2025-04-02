/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_instructions_printer.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 21:42:16 by migarrid          #+#    #+#             */
/*   Updated: 2025/04/02 17:57:21 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	ft_print_finish(char **last)
{
	ft_printf("%s\n", *last);
	*last = NULL;
}

static void	ft_print_opt(char *opt, char **last)
{
	ft_printf("%s\n", opt);
	*last = NULL;
}

static void	ft_print_update_last(char **last, char *action)
{
	ft_printf("%s\n", *last);
	*last = action;
}

void	ft_print_instructions(char *action)
{
	static char	*last;

	if (!action)
		return (ft_print_finish(&last));
	if (!last)
		last = action;
	else
	{
		if ((!ft_strcmp(last, "sa") && !ft_strcmp(action, "sb"))
			|| (!ft_strcmp(last, "sb") && !ft_strcmp(action, "sa")))
			return (ft_print_opt("ss", &last));
		else if ((!ft_strcmp(last, "ra") && !ft_strcmp(action, "rb"))
			|| (!ft_strcmp(last, "rb") && !ft_strcmp(action, "ra")))
			return (ft_print_opt("rr", &last));
		else if ((!ft_strcmp(last, "rra") && !ft_strcmp(action, "rrb"))
			|| (!ft_strcmp(last, "rrb") && !ft_strcmp(action, "rra")))
			return (ft_print_opt("rrr", &last));
		else
			return (ft_print_update_last(&last, action));
	}
}
