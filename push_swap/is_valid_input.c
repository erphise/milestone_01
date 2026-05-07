/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugutierr <ugutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 13:47:20 by ugutierr          #+#    #+#             */
/*   Updated: 2026/04/26 13:48:28 by ugutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_valid_str(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (!ft_isdigit(s[i]) && !ft_isspace(s[i])
			&& !(s[i] == '-' && (!i || ft_isspace(s[i - 1]))
				&& ft_isdigit(s[i + 1])))
			return (0);
		s++;
	}
	return (1);
}

int	is_valid_input(int ac, char **av)
{
	while (--ac)
	{
		if (is_keyword(av[ac]))
			continue ;
		if (!is_valid_str(av[ac]))
			return (0);
	}
	return (1);
}

int	not_params(int ac, char **av)
{
	while (--ac)
	{
		if (!is_keyword(av[ac]))
			return (0);
	}
	return (1);
}

int	exist_dups(t_list *l)
{
	t_list	*p;

	while (l)
	{
		p = l->next;
		while (p)
		{
			if (*(int *)p->content == *(int *)l->content)
				return (1);
			p = p->next;
		}
		l = l->next;
	}
	return (0);
}
