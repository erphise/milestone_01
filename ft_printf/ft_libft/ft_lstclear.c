/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: berhugue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 19:02:30 by berhugue          #+#    #+#             */
/*   Updated: 2026/02/04 19:02:32 by berhugue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>	// free

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*prev;
	t_list	*node;

	if (!lst || !del)
		return ;
	node = *lst;
	while (node)
	{
		prev = node;
		node = node->next;
		del(prev->content);
		free(prev);
	}
	*lst = NULL;
}
