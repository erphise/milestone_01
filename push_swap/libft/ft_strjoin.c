/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugutierr <ugutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/12 16:20:15 by ugutierr          #+#    #+#             */
/*   Updated: 2026/04/12 16:33:03 by ugutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*p;
	size_t	len1;
	size_t	len2;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	p = malloc(sizeof(char) * (len1 + len2 + 1));
	if (!p)
		return (NULL);
	(void)ft_strlcpy(p, s1, len1 + 1);
	(void)ft_strlcat(p, s2, len1 + len2 + 1);
	return (p);
}
//#include <stdio.h>
//int	main(void)
//{
//	char	*s = ft_strjoin("hola", "adios");
//	printf("%s\n", s);
//	free(s);
//	return (0);
//}
