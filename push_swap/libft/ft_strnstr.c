/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugutierr <ugutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/12 13:05:16 by ugutierr          #+#    #+#             */
/*   Updated: 2026/04/12 13:17:54 by ugutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s, const char *needle, size_t len)
{
	if (!*needle)
		return ((char *)s);
	if (!len || !*s)
		return (NULL);
	if (*needle == *s && s + 1 == ft_strnstr(s + 1, needle + 1, len - 1))
		return ((char *)s);
	return (ft_strnstr(s + 1, needle, len - 1));
}
//#include <stdio.h>
//int	main(void)
//{
//	printf("%s\n", ft_strnstr("holaquetal", "que", 8));
//	return (0);
//}
