/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bench.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugutierr <ugutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 16:30:40 by ugutierr          #+#    #+#             */
/*   Updated: 2026/04/26 18:08:10 by ugutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

unsigned long	calc_total_ops(t_env *env)
{
	return (env->sa + env->sb + env->ss + env->pa + env->pb
		+ env->ra + env->rb + env->rr + env->rra + env->rrb + env->rrr);
}

char	*calc_complexity(t_env *env)
{
	if (env->strat == SIMPLE)
		return ("O(n^2)");
	if (env->strat == MEDIUM)
		return ("O(n\xE2\x88\x9An)");
	return ("O(nlog(n))");
}

char	*printable_strat(t_env *env)
{
	if (env->real_strat == ADAPTIVE)
		return (ft_strjoin("Adaptive / ", calc_complexity(env)));
	if (env->real_strat == SIMPLE)
		return (ft_strjoin("Simple / ", calc_complexity(env)));
	if (env->real_strat == MEDIUM)
		return (ft_strjoin("Medium / ", calc_complexity(env)));
	return (ft_strjoin("Complex / ", calc_complexity(env)));
}

int	print_bench(t_env *env)
{
	ft_putstr_fd("[bench] disorder: ", 2);
	if (!print_percentage(env->disorder))
		return (0);
	ft_putstr_fd("[bench] strategy: ", 2);
	ft_putendl_fd(printable_strat(env), 2);
	ft_putstr_fd("[bench] total_ops: ", 2);
	if (!print_op("", calc_total_ops(env)))
		return (0);
	if (!print_ops(env))
		return (0);
	ft_putstr_fd("\n", 2);
	return (1);
}
