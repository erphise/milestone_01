/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugutierr <ugutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/12 19:18:57 by ugutierr          #+#    #+#             */
/*   Updated: 2026/04/12 19:49:04 by ugutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		f(i, s + i);
		i++;
	}
}
//
//void	func(unsigned int i, char *c)
//{
//	(void)i;
//	*c = ft_toupper(*c);
//}
//#include <stdio.h>
//int	main(void)
//{
//	char	s[] = "Hola";
//	ft_striteri(s, *func);
//	printf("%s\n", s);
//}
