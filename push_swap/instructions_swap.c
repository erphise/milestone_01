/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_swap.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: berhugue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 19:22:25 by berhugue          #+#    #+#             */
/*   Updated: 2026/05/03 18:47:57 by ugutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap(t_node **stack)
{
	t_node	*head;
	t_node	*next;
	int		tmp_val;
	int		tmp_index;

	if (ft_nodesize(*stack) < 2)
		return (-1);
	head = *stack;
	next = head->next;
	if (!head && !next)
		ft_error("Error");
	tmp_val = head->value;
	tmp_index = head->index;
	head->value = next->value;
	head->index = next->index;
	next->value = tmp_val;
	next->index = tmp_index;
	return (0);
}

int	sa(t_node **stack_a, t_env *env, bool print)
{
	if (swap(stack_a) == -1)
		return (-1);
	if (print)
		ft_putendl_fd("sa", 1);
	env->sa++;
	return (0);
}

int	sb(t_node **stack_b, t_env *env, bool print)
{
	if (swap(stack_b) == -1)
		return (-1);
	if (print)
		ft_putendl_fd("sb", 1);
	env->sb++;
	return (0);
}

int	ss(t_node **stack_a, t_node **stack_b, t_env *env, bool print)
{
	if ((ft_nodesize(*stack_a) < 2) || (ft_nodesize(*stack_b) < 2))
		return (-1);
	swap(stack_a);
	swap(stack_b);
	if (print)
		ft_putendl_fd("ss", 1);
	env->ss++;
	return (0);
}
