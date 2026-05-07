/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugutierr <ugutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/12 17:12:16 by ugutierr          #+#    #+#             */
/*   Updated: 2026/04/14 14:39:02 by ugutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**create_arr(char const *s, char c)
{
	size_t	len;
	size_t	i;
	char	**p;

	len = 1;
	i = 0;
	while (s[i])
	{
		if (s[i] != c && (!i || s[i - 1] == c))
			len ++;
		i++;
	}
	p = malloc(sizeof(char *) * len);
	if (!p)
		return (NULL);
	p[len - 1] = NULL;
	return (p);
}

static void	*free_all(char **p, char **pi)
{
	while (p <= --pi)
		free(*pi);
	free(p);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	char	**p;

	p = create_arr(s, c);
	if (!p)
		return (NULL);
	i = 0;
	j = 0;
	while (s[j])
	{
		if (s[j] != c && (!j || s[j - 1] == c) && ft_strchr(s + j, c))
			p[i++] = ft_substr(s, j, ft_strchr(s + j, c) - s - j);
		else if (s[j] != c && (!j || s[j - 1] == c))
			p[i++] = ft_substr(s, j, ft_strlen(s + j));
		if (i && !p[i - 1])
			return (free_all(p, p + i - 1));
		j++;
	}
	return (p);
}
//#include <stdio.h>
//int	main(void)
//{
//	char	**s = ft_split("------hola", '-');
//	while (*s)
//	{
//		printf("%s\n", *s);
//		s++;
//	}
//}
