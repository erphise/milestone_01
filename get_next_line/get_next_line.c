/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: berhugue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 22:58:38 by berhugue          #+#    #+#             */
/*   Updated: 2026/04/14 10:56:01 by berhugue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	free_memory(char **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
	}
}

static int	read_from_file(int fd, char **buffer)
{
	char	*read_buf;
	char	*tmp;
	ssize_t	bytes_read;

	read_buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
	bytes_read = read(fd, read_buf, BUFFER_SIZE);
	if (bytes_read < 0)
	{
		free_memory(buffer);
		return (free(read_buf), bytes_read);
	}
	if (bytes_read == 0)
		return (free(read_buf), bytes_read);
	read_buf[bytes_read] = '\0';
	if (*buffer)
	{
		tmp = ft_strjoin(*buffer, read_buf);
		if (!tmp)
			return (free_memory(buffer), free(read_buf), -1);
		free_memory(buffer);
		*buffer = tmp;
	}
	else
		*buffer = ft_strdup(read_buf);
	return (free(read_buf), bytes_read);
}

static char	*extract_line(char **buffer)
{
	size_t	i;
	char	*line;
	char	*new_buffer;

	if (!*buffer)
		return (NULL);
	i = 0;
	while ((*buffer)[i] && (*buffer)[i] != VAR)
		i++;
	if ((*buffer)[i] == VAR)
		i++;
	line = ft_strndup(*buffer, i);
	if (!line)
		return (NULL);
	new_buffer = ft_strdup(*buffer + i);
	free_memory(buffer);
	*buffer = new_buffer;
	if (!*buffer || !**buffer)
		free_memory(buffer);
	return (line);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*buffer;
	ssize_t		bytes_read;

	bytes_read = 1;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (free_memory(&buffer), NULL);
	while (1)
	{
		if (!buffer || !ft_strchr(buffer, VAR))
		{
			bytes_read = read_from_file(fd, &buffer);
			if (bytes_read <= 0)
				break ;
		}
		else
			break ;
	}
	if ((bytes_read == 0 && (!buffer || *buffer == '\0')) || bytes_read < 0)
	{
		free_memory(&buffer);
		return (NULL);
	}
	line = extract_line(&buffer);
	return (line);
}
#include <stdio.h>

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("test.txt", O_RDONLY);
	if (fd < 0)
		return (1);

	while ((line = get_next_line(fd)))
	{
		printf("%s\n", line);
		free(line);
	}
	close(fd);
	return (0);
}