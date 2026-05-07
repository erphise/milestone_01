/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugutierr <ugutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 18:59:24 by ugutierr          #+#    #+#             */
/*   Updated: 2026/05/03 18:59:50 by ugutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_nodesize(t_node *head)
{
	size_t	i;
	t_node	*tmp;

	tmp = head;
	i = 0;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

t_node	*ft_nodelast(t_node *head)
{
	t_node	*tmp;

	tmp = head;
	if (!head)
		return (NULL);
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}

void	ft_nodeclear(t_node **lst)
{
	t_node	*p;
	t_node	*tmp;

	p = *lst;
	while (p)
	{
		tmp = p->next;
		free(p);
		p = tmp;
	}
	*lst = NULL;
}

void	ft_nodeadd_back(t_node **node, t_node *new)
{
	if (!node)
		return ;
	if (!*node)
		*node = new;
	else
		ft_nodelast(*node)->next = new;
}

t_node	*ft_nodenew(int value, int index)
{
	t_node	*p;

	p = malloc(sizeof(t_node));
	if (!p)
		return (NULL);
	p->value = value;
	p->index = index;
	p->next = NULL;
	return (p);
}
