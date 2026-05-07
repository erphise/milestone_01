/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugutierr <ugutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 13:38:10 by ugutierr          #+#    #+#             */
/*   Updated: 2026/05/03 10:56:52 by ugutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_env	*init_env(t_list *l, int ac, char **av)
{
	t_env	*env;

	env = malloc(sizeof(t_env));
	if (!env)
		return (NULL);
	env->sa = 0;
	env->sb = 0;
	env->ss = 0;
	env->pa = 0;
	env->pb = 0;
	env->ra = 0;
	env->rb = 0;
	env->rr = 0;
	env->rra = 0;
	env->rrb = 0;
	env->rrr = 0;
	env->bench = benchmode(ac, av);
	env->disorder = calc_disorder(l);
	env->real_strat = calc_real_strat(ac, av);
	env->strat = calc_strat(env);
	env->len = ft_lstsize(l);
	if (env->real_strat == INVALID)
		return (free(env), NULL);
	return (env);
}

t_strat	calc_strat(t_env *env)
{
	if (env->real_strat != ADAPTIVE)
		return (env->real_strat);
	if (env->disorder < 0.2)
		return (SIMPLE);
	if (env->disorder >= 0.5)
		return (COMPLEX);
	return (MEDIUM);
}

t_strat	calc_real_strat(int ac, char **av)
{
	t_strat	s;

	s = INVALID;
	while (--ac)
	{
		if (!is_keyword(av[ac]) || !ft_strcmp(av[ac], "--bench"))
			continue ;
		if (s != INVALID && s != which_strat(av[ac]))
			return (INVALID);
		s = which_strat(av[ac]);
	}
	if (s == INVALID)
		return (ADAPTIVE);
	return (s);
}

double	calc_disorder(t_list *l)
{
	long	mistakes;
	long	total_pairs;
	t_list	*p;
	t_list	*s;

	mistakes = 0;
	total_pairs = 0;
	p = l;
	while (p)
	{
		s = p->next;
		while (s)
		{
			total_pairs++;
			if (*(int *)p->content > *(int *)s->content)
				mistakes++;
			s = s->next;
		}
		p = p->next;
	}
	return ((double)mistakes / total_pairs);
}

int	benchmode(int ac, char **av)
{
	while (--ac)
	{
		if (!ft_strcmp(av[ac], "--bench"))
			return (1);
	}
	return (0);
}
