/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugutierr <ugutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 17:31:37 by ugutierr          #+#    #+#             */
/*   Updated: 2026/05/03 19:25:51 by ugutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_lst(t_node **a, t_node **b, char *op, t_env *env)
{
	if (!ft_strncmp(op, "sa\n", 3UL))
		sa(a, env, false);
	else if (!ft_strncmp(op, "sb\n", 3UL))
		sb(b, env, false);
	else if (!ft_strncmp(op, "ss\n", 3UL))
		ss(a, b, env, false);
	else if (!ft_strncmp(op, "pa\n", 3UL))
		pa(a, b, env, false);
	else if (!ft_strncmp(op, "pb\n", 3UL))
		pb(a, b, env, false);
	else if (!ft_strncmp(op, "ra\n", 3UL))
		ra(a, env, false);
	else if (!ft_strncmp(op, "rb\n", 3UL))
		rb(b, env, false);
	else if (!ft_strncmp(op, "rr\n", 3UL))
		rr(a, b, env, false);
	else if (!ft_strncmp(op, "rra\n", 4UL))
		rra(a, env, false);
	else if (!ft_strncmp(op, "rrb\n", 4UL))
		rrb(b, env, false);
	else if (!ft_strncmp(op, "rrr\n", 4UL))
		rrr(a, b, env, false);
	else
		ft_error("Error\n");
}

void	read_ops(t_node **a, t_env *env)
{
	char	*op;
	t_node	*b;

	b = NULL;
	op = get_next_line(STDIN_FILENO);
	while (op)
	{
		move_lst(a, &b, op, env);
		free(op);
		op = get_next_line(STDIN_FILENO);
	}
}

int	is_ordered(t_node *l)
{
	while (l)
	{
		if (l->next && l->index + 1 != l->next->index)
			return (0);
		l = l->next;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_env	*env;
	t_node	*l;

	if (!parse_input(&l, &env, argc, argv))
		ft_error("Error\n");
	read_ops(&l, env);
	if (is_ordered(l))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free(env);
	ft_nodeclear(&l);
	return (0);
}
