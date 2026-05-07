/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugutierr <ugutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 10:39:54 by ugutierr          #+#    #+#             */
/*   Updated: 2026/05/05 19:37:07 by ugutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_node(t_node *n)
{
	while (n)
	{
		printf("%i, %i\n", n->index, n->value);
		n = n->next;
	}
}

int	main(int argc, char **argv)
{
	t_env	*env;
	t_node	*l;

	if (!parse_input(&l, &env, argc, argv))
		ft_error("Error\n");
//	print_node(l);
	push_swap(&l, env);
	if (env->bench && !print_bench(env))
	{
		free(env);
		ft_nodeclear(&l);
		ft_error("Error\n");
	}
	ft_nodeclear(&l);
	free(env);
	return (0);
}
