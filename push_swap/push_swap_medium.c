/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_medium.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: berhugue <berhugue@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 17:04:14 by ugutierr          #+#    #+#             */
/*   Updated: 2026/05/10 12:44:00 by berhugue         ###   ########.fr       */
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

void	get_chunks(t_node **a, t_node **b, t_env *env, bool print)
{
	int	min;
	int	max;
	int	pushed;
	int	chunk_size;

	chunk_size = ft_sqrt(env->len);
	min = 0;
	max = chunk_size;
	pushed = 0;
	while (*a)
	{
		if (min <= (*a)->index && (*a)->index < max)
		{
			pb(a, b, env, print);
			pushed++;
		}
		else
			ra(a, env, print);
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

void	push_chunks(t_node **a, t_node **b, t_env *env, bool print)
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
				rb(b, env, print);
		}
		else
		{
			while ((*b)->index != max)
				rrb(b, env, print);
		}
		pa(a, b, env, print);
	}
}

void	push_swap_medium(t_node **a, t_node **b, t_env *env, bool print)
{
	get_chunks(a, b, env, print);
	push_chunks(a, b, env, print);
}
