/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugutierr <ugutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/11 18:23:30 by ugutierr          #+#    #+#             */
/*   Updated: 2026/04/14 14:31:24 by ugutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (dest >= src)
		return (ft_memcpy(dest, src, n));
	i = 0;
	while (i++ < n)
		((char *)dest)[i - 1] = ((char *)src)[i - 1];
	return (dest);
}
//
//#include <stdio.h>
//int	main(void)
//{
//	char	s[] = "hola que tal estamos";
//
//	printf("%s\n", (char *)ft_memmove(s, s + 5, 10));
//	return (0);
//}
