/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugutierr <ugutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/11 19:52:40 by ugutierr          #+#    #+#             */
/*   Updated: 2026/04/12 23:33:25 by ugutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, char c)
{
	size_t	len;

	len = ft_strlen(str);
	while (len + 1 && str[len] != c)
		len--;
	if (str[len] == c)
		return ((char *)(str + len));
	return (NULL);
}
//#include <stdio.h>
//#include<string.h>
//int	main(void)
//{
//	char *s = "holaquetal";
//	char a = 'a';
//	printf("%s, %s\n", strrchr(s, a), ft_strrchr(s, a));
//	return (0);
//}
