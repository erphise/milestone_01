/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugutierr <ugutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/11 18:07:42 by ugutierr          #+#    #+#             */
/*   Updated: 2026/04/12 12:02:54 by ugutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	while (n--)
		((unsigned char *)str)[n] = (unsigned char)c;
	return (str);
}
//#include <stdio.h>
//int	main(void)
//{
//	char s[] = "hola";
//	char c = 'c';
//	printf("%s\n", (char *)ft_memset(s, c, 4));
//	return (0);
//}
