/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: berhugue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 19:02:18 by berhugue          #+#    #+#             */
/*   Updated: 2026/02/04 19:02:22 by berhugue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *elem)
{
	if (!lst || !elem)
		return ;
	elem->next = NULL;
	if (!*lst)
		*lst = elem;
	else
		ft_lstlast(*lst)->next = elem;
}
