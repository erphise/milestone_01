/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_simple.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: berhugue <berhugue@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 10:41:06 by ugutierr          #+#    #+#             */
/*   Updated: 2026/05/09 16:27:07 by berhugue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_min(t_node **stack, int exclude)
{
	t_node	*head;
	int		min;
	int		found;

	head = *stack;
	found = 0;
	while (head)
	{
		if (head->index != exclude)
		{
			if (!found || head->index < min)
			{
				min = head->index;
				found = 1;
			}
		}
		head = head->next;
	}
	return (min);
}

void	sort_3(t_node **a, t_env *env)
{
	int	first;
	int	second;
	int	third;

	if (is_sorted(a))
		return ;
	first = (*a)->index;
	second = (*a)->next->index;
	third = (*a)->next->next->index;
	if (first > second && second < third && first < third)
		sa(a, env, true);
	else if (first > second && second > third)
	{
		sa(a, env, true);
		rra(a, env, true);
	}
	else if (first > second && second < third && first > third)
		ra(a, env, true);
	else if (first < second && second > third && first < third)
	{
		sa(a, env, true);
		ra(a, env, true);
	}
	else if (first < second && second > third && first > third)
		rra(a, env, true);
}

void	move_min_top(t_node **a, t_env *env)
{
	int	min;
	int	distance;
	int	size;
	int	i;

	min = get_min(a, -1);
	distance = get_distance(a, min);
	size = ft_nodesize(*a);
	i = 0;
	if (distance <= size / 2)
	{
		while (i < distance)
		{
			ra(a, env, true);
			i++;
		}
	}
	else
	{
		while (i < size - distance)
		{
			rra(a, env, true);
			i++;
		}
	}
}

void	sort_simple(t_node **a, t_node **b, t_env *env)
{
	int	size;

	if (is_sorted(a))
		return ;
	size = ft_nodesize(*a);
	while (size > 3)
	{
		move_min_top(a, env);
		pb(a, b, env, true);
		size--;
	}
	sort_3(a, env);
	while (*b)
		pa(a, b, env, true);
}

void	push_swap_simple(t_node **a, t_node **b, t_env *env)
{
	int	size;

	size = ft_nodesize(*a);
	if (is_sorted(a) || size <= 1)
		return ;
	if (size == 2)
	{
		if ((*a)->index > (*a)->next->index)
			sa(a, env, true);
	}
	else if (size == 3)
		sort_3(a, env);
	else
		sort_simple(a, b, env);
}
