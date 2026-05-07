/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugutierr <ugutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/12 13:45:40 by ugutierr          #+#    #+#             */
/*   Updated: 2026/04/12 15:40:29 by ugutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*p;

	len = ft_strlen(s);
	p = malloc(sizeof(char) * (len + 1));
	if (!p)
		return (NULL);
	return (ft_memcpy(p, s, len + 1));
}
//
//#include <stdio.h>
//int	main(void)
//{
//	printf("%s\n", ft_strdup("hola"));
//	return (0);
//}
