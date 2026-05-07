/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugutierr <ugutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 11:27:36 by ugutierr          #+#    #+#             */
/*   Updated: 2026/04/22 17:34:57 by ugutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
//#include <stdio.h>

//void	print_buf(char *buf);

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE];
	ssize_t		n;
	char		*p;
	char		*s;

	if (ft_memchr(buf, SEP, BUFFER_SIZE))
		return (get_buf(buf));
	s = get_buf(buf);
	n = read(fd, buf, BUFFER_SIZE);
	while (s && n == BUFFER_SIZE && !ft_memchr(buf, SEP, n))
	{
		s = addstr(s, buf, BUFFER_SIZE);
		n = read(fd, buf, BUFFER_SIZE);
	}
	if (!s || n <= 0)
		return (manage_error(s, buf, n));
	p = ft_memchr(buf, SEP, n);
	if (p)
		s = addstr(s, buf, p - buf + 1);
	else
		s = addstr(s, buf, n);
	clean_buf(buf, p, n);
	return (s);
}
//
//void	print_buf(char *buf)
//{
//	size_t	i;
//	char	c;
//
//	c = '.';
//	i = -1;
//	write(1, "%", 1);
//	while (++i < BUFFER_SIZE)
//	{
//		if (!buf[i])
//			write(1, &c, 1);
//		else if (buf[i] == '\n')
//			write(1, "\\n", 2);
//		else
//			write(1, buf + i, 1);
//	}
//	write(1, "%\n", 2);
//}
//#include <stdio.h>
//#include <fcntl.h>
//int	main(int argc, char **argv)
//{
//	if (argc != 2)
//		return (1);
//	int	fd = open(argv[1], O_RDONLY);
//	char	*s;
//
//	s = get_next_line(fd);
//	while (s)
//	{
//		printf("%s", s);
//		free(s);
//		s = get_next_line(fd);
//	}
//	close(fd);
//	return (0);
//}
