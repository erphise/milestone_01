/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_simple.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: berhugue <berhugue@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 10:41:06 by ugutierr          #+#    #+#             */
/*   Updated: 2026/05/10 12:45:04 by berhugue         ###   ########.fr       */
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

void	sort_3(t_node **a, t_env *env, bool print)
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
		sa(a, env, print);
	else if (first > second && second > third)
	{
		sa(a, env, print);
		rra(a, env, print);
	}
	else if (first > second && second < third && first > third)
		ra(a, env, print);
	else if (first < second && second > third && first < third)
	{
		sa(a, env, print);
		ra(a, env, print);
	}
	else if (first < second && second > third && first > third)
		rra(a, env, print);
}

void	move_min_top(t_node **a, t_env *env, bool print)
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
			ra(a, env, print);
			i++;
		}
	}
	else
	{
		while (i < size - distance)
		{
			rra(a, env, print);
			i++;
		}
	}
}

void	sort_simple(t_node **a, t_node **b, t_env *env, bool print)
{
	int	size;

	if (is_sorted(a))
		return ;
	size = ft_nodesize(*a);
	while (size > 3)
	{
		move_min_top(a, env, print);
		pb(a, b, env, print);
		size--;
	}
	sort_3(a, env, print);
	while (*b)
		pa(a, b, env, print);
}

void	push_swap_simple(t_node **a, t_node **b, t_env *env, bool print)
{
	int	size;

	size = ft_nodesize(*a);
	if (is_sorted(a) || size <= 1)
		return ;
	if (size == 2)
	{
		if ((*a)->index > (*a)->next->index)
			sa(a, env, print);
	}
	else if (size == 3)
		sort_3(a, env, print);
	else
		sort_simple(a, b, env, print);
}
