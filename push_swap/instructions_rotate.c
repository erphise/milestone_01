/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_rotate.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: berhugue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 19:22:40 by berhugue          #+#    #+#             */
/*   Updated: 2026/05/03 18:44:12 by ugutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rotate(t_node **stack)
{
	t_node	*head;
	t_node	*tail;

	if (ft_nodesize(*stack) < 2)
		return (-1);
	head = *stack;
	tail = ft_nodelast(head);
	*stack = head->next;
	head->next = NULL;
	tail->next = head;
	return (0);
}

int	ra(t_node **stack_a, t_env *env, bool print)
{
	if (rotate(stack_a) == -1)
		return (-1);
	if (print)
		ft_putendl_fd("ra", 1);
	env->ra++;
	return (0);
}

int	rb(t_node **stack_b, t_env *env, bool print)
{
	if (rotate(stack_b) == -1)
		return (-1);
	if (print)
		ft_putendl_fd("rb", 1);
	env->rb++;
	return (0);
}

int	rr(t_node **stack_a, t_node **stack_b, t_env *env, bool print)
{
	if ((ft_nodesize(*stack_a) < 2) || (ft_nodesize(*stack_b) < 2))
		return (-1);
	rotate(stack_a);
	rotate(stack_b);
	if (print)
		ft_putendl_fd("rr", 1);
	env->rr++;
	return (0);
}
