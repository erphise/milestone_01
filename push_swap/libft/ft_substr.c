/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugutierr <ugutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/12 15:33:41 by ugutierr          #+#    #+#             */
/*   Updated: 2026/04/14 14:22:39 by ugutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*p;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (ft_strlen(s) < start)
		len = 0;
	else if (ft_strlen(s + start) < len)
		len = ft_strlen(s + start);
	p = malloc(sizeof(char) * (len + 1));
	if (!p)
		return (NULL);
	while (s[i] && j < len)
	{
		if (start <= i)
		{
			p[j] = s[i];
			j++;
		}
		i++;
	}
	p[j] = '\0';
	return (p);
}
//
//#include <stdio.h>
//int	main(void)
//{
//	char *s = ft_substr("hola", 2, 10);
//	printf("%s\n", s);
//	free(s);
//	return (0);
//}
