/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugutierr <ugutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/11 18:40:40 by ugutierr          #+#    #+#             */
/*   Updated: 2026/04/12 23:27:03 by ugutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t n)
{
	size_t	len;

	len = ft_strlen(src);
	if (len < n)
		(void)ft_memcpy(dest, src, len + 1);
	else if (n)
	{
		(void)ft_memcpy(dest, src, n - 1);
		dest[n - 1] = '\0';
	}
	return (len);
}
//#include <stdio.h>
//int	main(void)
//{
//	char	d[100];
//	(void)ft_strlcpy(d, "lorem", 0);
//	printf("%s\n", d);
//}
