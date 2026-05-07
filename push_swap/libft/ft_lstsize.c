/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _ft_lstsize.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugutierr <ugutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 18:38:22 by ugutierr          #+#    #+#             */
/*   Updated: 2026/04/14 23:58:26 by ugutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	len;

	len = 0;
	while (lst)
	{
		lst = lst->next;
		len++;
	}
	return (len);
}
//#include <stdio.h>
//int	main(void)
//{
//	t_list	*l;
//
//	l = ft_lstadd_back("hola");
//	l->next = ft_lstnew("adios");
//	printf("%i\n", ft_lstsize(l));
//}
