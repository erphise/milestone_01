/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_medium.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugutierr <ugutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 17:04:14 by ugutierr          #+#    #+#             */
/*   Updated: 2026/05/03 18:52:39 by ugutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_sqrt(unsigned long n)
{
	unsigned int	i;

	i = 0;
	while (i * i < n)
		i++;
	if (i * i == n)
		return (i);
	return (i - 1);
}

void	get_chunks(t_node **a, t_node **b, int chunk_size, t_env *env)
{
	int	min;
	int	max;
	int	pushed;

	min = 0;
	max = chunk_size;
	pushed = 0;
	while (*a)
	{
		if (min <= (*a)->index && (*a)->index < max)
		{
			pb(a, b, env, true);
			pushed++;
		}
		else
			ra(a, env, true);
		if (pushed == chunk_size)
		{
			min += chunk_size;
			max += chunk_size;
			pushed = 0;
		}
	}
}

int	get_position(t_node *a, int index)
{
	int	pos;

	pos = 0;
	while (a)
	{
		if (a->index == index)
			return (pos);
		pos++;
		a = a->next;
	}
	return (-1);
}

void	push_chunks(t_node **a, t_node **b, t_env *env)
{
	int	max;
	int	pos;

	while (*b)
	{
		max = ft_nodesize(*b) - 1;
		pos = get_position(*b, max);
		if (pos < max / 2)
		{
			while ((*b)->index != max)
				rb(b, env, true);
		}
		else
		{
			while ((*b)->index != max)
				rrb(b, env, true);
		}
		pa(a, b, env, true);
	}
}

void	push_swap_medium(t_node **a, t_node **b, t_env *env)
{
	int	chunk_size;

	chunk_size = ft_sqrt(env->len);
	get_chunks(a, b, chunk_size, env);
	push_chunks(a, b, env);
}
