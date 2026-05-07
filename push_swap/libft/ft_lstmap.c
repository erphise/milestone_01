/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _ft_lstmap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugutierr <ugutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 23:18:04 by ugutierr          #+#    #+#             */
/*   Updated: 2026/04/15 09:50:42 by ugutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*l;
	t_list	*p;
	void	*tmp;

	l = NULL;
	while (lst)
	{
		tmp = f(lst->content);
		p = ft_lstnew(tmp);
		if (!p)
		{
			del(tmp);
			ft_lstclear(&l, del);
			return (NULL);
		}
		ft_lstadd_back(&l, p);
		lst = lst->next;
	}
	return (l);
}
//#include <stdio.h>
//void	*f(void *s)
//{
//	return (s + 1);
//}
//
//void	g(void *s)
//{
//	printf("%s\n", (char *)s);
//}
//
//void	del(void *c)
//{
//	(void)c;
//}
//
//int	main(void)
//{
//	t_list	*l;
//
//	l = ft_lstnew("hola");
//	l->next = ft_lstnew("adios");
//	ft_lstiter(ft_lstmap(l, f, del), g);
//}
