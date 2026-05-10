/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugutierr <ugutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 13:45:35 by ugutierr          #+#    #+#             */
/*   Updated: 2026/05/10 11:50:33 by ugutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	parse_input(t_node **n, t_env **env, int argc, char **argv)
{
	t_list	*l;

	if (!is_valid_input(argc, argv))
		return (0);
	if (not_params(argc, argv))
		return (0);
	l = create_list(argc, argv);
	if (!l)
		return (0);
	if (exist_dups(l))
	{
		ft_lstclear(&l, free);
		return (0);
	}
	*env = init_env(l, argc, argv);
	if (!*env)
	{
		ft_lstclear(&l, free);
		return (0);
	}
	if (!lst_to_node(&l, n))
		return (ft_lstclear(&l, free), 0);
	return (1);
}

t_list	*create_list(int ac, char **av)
{
	t_list	*l;
	int		i;

	l = NULL;
	i = 0;
	while (++i < ac)
	{
		if (is_keyword(av[i]))
			continue ;
		if (!addnbrs(&l, av[i]))
		{
			ft_lstclear(&l, free);
			return (NULL);
		}
	}
	return (l);
}

long	ft_atol(const char *nptr)
{
	long	total;
	int		sign;

	sign = 1;
	total = 0L;
	while (ft_isspace(*nptr))
		nptr++;
	if (*nptr == '-')
		sign = -1;
	if (*nptr == '-' || *nptr == '+')
		nptr++;
	while ('0' <= *nptr && *nptr <= '9')
	{
		total *= 10;
		total += *nptr - '0';
		if (!is_int(total))
			return (INT_MAX + 1L);
		nptr++;
	}
	return (sign * total);
}

int	addnbrs(t_list **l, char *s)
{
	size_t	i;
	long	n;
	int		*nptr;
	t_list	*tmp;

	i = -1;
	while (s[++i])
	{
		if (ft_isspace(s[i]) || (i && !ft_isspace(s[i - 1])))
			continue ;
		n = ft_atol(s + i);
		if (!is_int(n))
			return (0);
		nptr = malloc(sizeof(int));
		if (!nptr)
			return (0);
		*nptr = n;
		tmp = ft_lstnew(nptr);
		if (!tmp)
			return (free(nptr), 0);
		ft_lstadd_back(l, tmp);
	}
	return (1);
}
