/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_push.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: berhugue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 19:22:17 by berhugue          #+#    #+#             */
/*   Updated: 2026/05/03 18:35:11 by ugutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push(t_node **stack_to, t_node **stack_from)
{
	t_node	*tmp;
	t_node	*head_to;
	t_node	*head_from;

	if (ft_nodesize(*stack_from) == 0)
		return (-1);
	head_to = *stack_to;
	head_from = *stack_from;
	tmp = head_from;
	head_from = head_from->next;
	*stack_from = head_from;
	if (!head_to)
	{
		head_to = tmp;
		head_to->next = NULL;
		*stack_to = head_to;
	}
	else
	{
		tmp->next = head_to;
		*stack_to = tmp;
	}
	return (0);
}

int	pa(t_node **stack_a, t_node **stack_b, t_env *env, bool print)
{
	if (push(stack_a, stack_b) == -1)
		return (-1);
	if (print)
		ft_putendl_fd("pa", 1);
	env->pa++;
	return (0);
}

int	pb(t_node **stack_a, t_node **stack_b, t_env *env, bool print)
{
	if (push(stack_b, stack_a) == -1)
		return (-1);
	if (print)
		ft_putendl_fd("pb", 1);
	env->pb++;
	return (0);
}
