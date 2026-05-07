/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugutierr <ugutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/12 19:03:58 by ugutierr          #+#    #+#             */
/*   Updated: 2026/04/14 14:02:19 by ugutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*p;
	size_t	i;

	i = 0;
	p = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!p)
		return (NULL);
	while (s[i])
	{
		p[i] = f(i, s[i]);
		i++;
	}
	p[i] = '\0';
	return (p);
}
//char	func(unsigned int a, char  b)
//{
//	(void)a;
//	return (ft_toupper(b));
//}
//#include <stdio.h>
//int	main(void)
//{
//	char	*s = ft_strmapi("Hola", *func);
//	printf("%s\n", s);
//	free(s);
//}
