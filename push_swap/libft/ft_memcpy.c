/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugutierr <ugutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/11 18:19:26 by ugutierr          #+#    #+#             */
/*   Updated: 2026/04/14 14:31:01 by ugutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	if (dest == src)
		return (dest);
	while (n--)
		((char *)dest)[n] = ((char *)src)[n];
	return (dest);
}
//
//#include <stdio.h>
//int	main(void)
//{
//	char	s[10];
//	char	t[] = "hola";
//	printf("%s\n", (char *)ft_memcpy(s, t, 5));;
//}
