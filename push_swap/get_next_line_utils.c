/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugutierr <ugutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 10:12:38 by ugutierr          #+#    #+#             */
/*   Updated: 2026/05/03 18:04:57 by ugutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*manage_error(char *s, char buf[BUFFER_SIZE], size_t n)
{
	clean_buf(buf, buf, 0);
	if (n == 0 && s && *s)
		return (s);
	if (s)
		free(s);
	return (NULL);
}

char	*get_buf(char buf[BUFFER_SIZE])
{
	size_t	len;
	size_t	i;
	size_t	j;
	char	*p;

	len = 0;
	i = 0;
	while (i < BUFFER_SIZE && !buf[i])
		i++;
	while (i + len < BUFFER_SIZE && buf[i + len] && buf[i + len] != SEP)
		len++;
	if (i + len < BUFFER_SIZE && buf[i + len] == SEP)
		len++;
	p = malloc(sizeof(char) * (len + 1));
	if (!p)
		return (NULL);
	p[len] = '\0';
	j = -1;
	while (++j < len)
		p[j] = buf[i + j];
	if (i + len - 1 < BUFFER_SIZE && buf[i + len - 1] == SEP)
		clean_buf(buf, buf + i + len - 1, BUFFER_SIZE);
	return (p);
}

void	clean_buf(char buf[BUFFER_SIZE], char *p, size_t n)
{
	while (p && buf <= p)
	{
		*p = 0;
		p--;
	}
	if (!p)
		n = 0;
	while (n < BUFFER_SIZE)
	{
		buf[n] = 0;
		n++;
	}
}

char	*addstr(char *s, char buf[BUFFER_SIZE], size_t len)
{
	char	*p;
	size_t	i;
	size_t	j;
	size_t	slen;

	if (!s)
		return (NULL);
	slen = 0;
	while (s[slen])
		slen++;
	p = malloc(sizeof(char) * (slen + len + 1));
	if (!p)
	{
		free(s);
		return (NULL);
	}
	i = -1;
	while (s[++i])
		p[i] = s[i];
	j = -1;
	while (++j < len)
		p[i++] = buf[j];
	p[i] = '\0';
	free(s);
	return (p);
}
//
//char	*ft_memchr(char *buf, char c, size_t n)
//{
//	size_t	i;
//
//	i = 0;
//	while (i < n && buf[i] != c)
//		i++;
//	if (i == n)
//		return (NULL);
//	return (buf + i);
//}
