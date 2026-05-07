/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_reverse_rotate.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: berhugue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 19:22:31 by berhugue          #+#    #+#             */
/*   Updated: 2026/05/03 18:39:55 by ugutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	reverse_rotate(t_node **stack)
{
	t_node	*head;
	t_node	*tail;

	if (ft_nodesize(*stack) < 2)
		return (-1);
	head = *stack;
	tail = ft_nodelast(head);
	while (head)
	{
		if (head->next->next == NULL)
		{
			head->next = NULL;
			break ;
		}
		head = head->next;
	}
	tail->next = *stack;
	*stack = tail;
	return (0);
}

int	rra(t_node **stack_a, t_env *env, bool print)
{
	if (reverse_rotate(stack_a) == -1)
		return (-1);
	if (print)
		ft_putendl_fd("rra", 1);
	env->rra++;
	return (0);
}

int	rrb(t_node **stack_b, t_env *env, bool print)
{
	if (reverse_rotate(stack_b) == -1)
		return (-1);
	if (print)
		ft_putendl_fd("rrb", 1);
	env->rrb++;
	return (0);
}

int	rrr(t_node **stack_a, t_node **stack_b, t_env *env, bool print)
{
	if ((ft_nodesize(*stack_a) < 2) || (ft_nodesize(*stack_b) < 2))
		return (-1);
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	if (print)
		ft_putendl_fd("rrr", 1);
	env->rrr++;
	return (0);
}
