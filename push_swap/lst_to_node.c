/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize_lst.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugutierr <ugutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 12:11:00 by ugutierr          #+#    #+#             */
/*   Updated: 2026/05/03 14:59:07 by ugutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_index(t_list *l, t_list *p)
{
	int	index;

	index = 0;
	while (l)
	{
		if (*(int *)p->content > *(int *)l->content)
			index++;
		l = l->next;
	}
	return (index);
}

int	lst_to_node(t_list **l, t_node **n)
{
	t_node	*tmp;
	t_node	*node;
	t_list	*p;

	node = NULL;
	p = *l;
	while (p)
	{
		tmp = ft_nodenew(*(int *)p->content, get_index(*l, p));
		if (!tmp)
		{
			ft_nodeclear(&node);
			return (0);
		}
		ft_nodeadd_back(&node, tmp);
		p = p->next;
	}
	ft_lstclear(l, free);
	*n = node;
	return (1);
}
