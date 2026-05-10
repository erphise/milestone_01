/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: berhugue <berhugue@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 10:39:54 by ugutierr          #+#    #+#             */
/*   Updated: 2026/05/10 13:32:57 by berhugue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//void	print_node(t_node *n)
//{
//	while (n)
//	{
//		printf("%i, %i\n", n->index, n->value);
//		n = n->next;
//	}
//}

int	main(int argc, char **argv)
{
	t_env	*env;
	t_node	*l;

	if (!parse_input(&l, &env, argc, argv))
		ft_error("Error");
	push_swap(&l, env, true);
	if (env->bench && !print_bench(env))
	{
		free(env);
		ft_nodeclear(&l);
		ft_error("Error");
	}
	ft_nodeclear(&l);
	free(env);
	return (0);
}
