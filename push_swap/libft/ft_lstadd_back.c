/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _ft_lstadd_back.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugutierr <ugutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 18:45:35 by ugutierr          #+#    #+#             */
/*   Updated: 2026/04/15 00:00:07 by ugutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (!lst)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	ft_lstlast(*lst)->next = new;
}
//#include <stdio.h>
//int	main(void)
//{
//	t_list	*l;
//
//	l = NULL;
//	ft_lstadd_back(&l, ft_lstnew("hola"));
//	ft_lstadd_back(&l, ft_lstnew("adios"));
//	ft_lstadd_back(&l, ft_lstnew("1"));
//	ft_lstadd_back(&l, ft_lstnew("2"));
//	ft_lstadd_back(&l, ft_lstnew("3"));
//	while (l)
//	{
//		printf("%s\n", (char *)l->content);
//		l = l->next;
//	}
//}
