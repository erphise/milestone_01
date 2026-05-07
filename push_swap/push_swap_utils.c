/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugutierr <ugutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 13:41:06 by ugutierr          #+#    #+#             */
/*   Updated: 2026/04/26 17:34:41 by ugutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strcmp(char *s1, char *s2)
{
	return (ft_strncmp(s1, s2, ft_strlen(s1) + 1));
}

int	ft_isspace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f'
		|| c == '\r');
}

int	is_keyword(char *s)
{
	return (!ft_strcmp(s, "--bench") || !ft_strcmp(s, "--adaptive")
		|| !ft_strcmp(s, "--medium") || !ft_strcmp(s, "--simple")
		|| !ft_strcmp(s, "--complex"));
}

int	is_int(long n)
{
	return (INT_MIN <= n && n <= INT_MAX);
}

t_strat	which_strat(char *s)
{
	if (!ft_strcmp(s, "--adaptive"))
		return (ADAPTIVE);
	if (!ft_strcmp(s, "--simple"))
		return (SIMPLE);
	if (!ft_strcmp(s, "--medium"))
		return (MEDIUM);
	if (!ft_strcmp(s, "--complex"))
		return (COMPLEX);
	return (INVALID);
}
