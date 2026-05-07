/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugutierr <ugutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/12 16:33:25 by ugutierr          #+#    #+#             */
/*   Updated: 2026/04/14 10:29:43 by ugutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char const	*start;
	char const	*end;
	size_t		len;

	len = ft_strlen(s1);
	start = s1;
	while (start < s1 + len && ft_strchr(set, *start))
		start++;
	end = s1 + len;
	while (s1 <= end && ft_strchr(set, *end))
		end--;
	if (end < s1 || start > s1 + len)
		end = start - 1;
	return (ft_substr(s1, start - s1, end - start + 1));
}
//#include <stdio.h>
//int	main(void)
//{
//	char	*s = ft_strtrim("-----++++hola", "+-");
//	printf("%s\n", s);
//	free(s);
//	return (0);
//}
