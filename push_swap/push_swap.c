/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: berhugue <berhugue@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 15:54:10 by ugutierr          #+#    #+#             */
/*   Updated: 2026/05/10 12:46:03 by berhugue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_node **stack_a, t_env *env, bool print)
{
	t_node	*stack_b;

	stack_b = NULL;
	if (env->strat == SIMPLE)
		push_swap_simple(stack_a, &stack_b, env, print);
	if (env->strat == MEDIUM)
		push_swap_medium(stack_a, &stack_b, env, print);
	if (env->strat == COMPLEX)
		push_swap_complex(stack_a, &stack_b, env, print);
}
