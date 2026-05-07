/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_simple.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: berhugue <berhugue@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 17:43:03 by berhugue          #+#    #+#             */
/*   Updated: 2026/05/07 18:36:30 by berhugue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_min(t_node **stack, int val)
{
	t_node	*head;
	int		min;

	head = *stack;
	min = head->index;
	while (head->next)
	{
		head = head->next;
		if ((head->index < min) && head->index != val)
			min = head->index;
	}
	return (min);
}

void	sort_3(t_node **a, t_env *env)
{
	t_node	*head;
	int		min;
	int		next_min;

	head = *a;
	min = get_min(a, -1);
	next_min = get_min(a, min);
	if (is_sorted(a))
		return ;
	if (head->index == min && head->next->index != next_min)
	{
		ra(a, env, true);
		sa(a, env, true);
		rra(a, env, true);
	}
	else if (head->index == next_min)
	{
		if (head->next->index == min)
			sa(a, env, true);
		else
			rra(a, env, true);
	}
	else
	{
		if (head->next->index == min)
			ra(a, env, true);
		else
		{
			sa(a, env, true);
			rra(a, env, true);
		}
	}
}

void	sort_4(t_node **a, t_node **b, t_env *env)
{
	int	distance;

	if (is_sorted(a))
		return ;
	distance = get_distance(a, get_min(a, -1));
	if (distance == 1)
		ra(a, env, true);
	else if (distance == 2)
	{
		ra(a, env, true);
		ra(a, env, true);
	}
	else if (distance == 3)
		rra(a, env, true);
	if (is_sorted(a))
		return ;
	pb(a, b, env, true);
	sort_3(a, env);
	pa(a, b, env, true);
}

void	sort_5(t_node **a, t_node **b, t_env *env)
{
	int	distance;

	distance = get_distance(a, get_min(a, -1));
	if (distance == 1)
		ra(a, env, true);
	else if (distance == 2)
	{
		ra(a, env, true);
		ra(a, env, true);
	}
	else if (distance == 3)
	{
		rra(a, env, true);
		rra(a, env, true);
	}
	else if (distance == 4)
		rra(a, env, true);
	if (is_sorted(a))
		return ;
	pb(a, b, env, true);
	sort_4(a, b, env);
	pa(a, b, env, true);
}

void	push_swap_simple(t_node **a, t_node **b, t_env *env)
{
	int	size;

	if (is_sorted(a) || ft_nodesize(*a) == 0
		|| ft_nodesize(*a) == 1)
		return ;
	size = ft_nodesize(*a);
	if (size == 2)
		sa(a, env, true);
	else if (size == 3)
		sort_3(a, env);
	else if (size == 4)
		sort_4(a, b, env);
	else if (size == 5)
		sort_5(a, b, env);
}
