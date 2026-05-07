/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugutierr <ugutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 17:31:12 by ugutierr          #+#    #+#             */
/*   Updated: 2026/04/26 18:06:23 by ugutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	print_percentage(double x)
{
	char	*tmp;

	tmp = ft_itoa((int)(100 * x));
	if (!tmp)
		return (0);
	ft_putstr_fd(tmp, 2);
	free(tmp);
	ft_putstr_fd(".", 2);
	x = 100 * x - (int)(100 * x);
	tmp = ft_itoa((int)(100 * x));
	if (!tmp)
		return (0);
	ft_putstr_fd(tmp, 2);
	free(tmp);
	ft_putstr_fd("%\n", 2);
	return (1);
}

int	print_op(char *s, unsigned long n)
{
	char	*tmp;

	ft_putstr_fd(s, 2);
	tmp = ft_itoa(n);
	if (!tmp)
		return (0);
	ft_putstr_fd(tmp, 2);
	free(tmp);
	return (1);
}

int	print_ops(t_env *env)
{
	ft_putstr_fd("\n[bench]", 2);
	if (!print_op(" sa: ", env->sa))
		return (0);
	if (!print_op(" sb: ", env->sb))
		return (0);
	if (!print_op(" ss: ", env->ss))
		return (0);
	if (!print_op(" pa: ", env->pa))
		return (0);
	if (!print_op(" pb: ", env->pb))
		return (0);
	ft_putstr_fd("\n[bench]", 2);
	if (!print_op(" ra: ", env->ra))
		return (0);
	if (!print_op(" rb: ", env->rb))
		return (0);
	if (!print_op(" rr: ", env->rr))
		return (0);
	if (!print_op(" rra: ", env->rra))
		return (0);
	if (!print_op(" rrb: ", env->rrb))
		return (0);
	if (!print_op(" rrr: ", env->rrr))
		return (0);
	return (1);
}
