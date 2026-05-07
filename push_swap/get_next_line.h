/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugutierr <ugutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 15:46:31 by ugutierr          #+#    #+#             */
/*   Updated: 2026/05/03 18:20:11 by ugutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"
# if BUFFER_SIZE < 1
#  undef BUFFER_SIZE
# endif
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif
# define SEP '\n'

char	*get_next_line(int fd);
char	*get_buf(char buf[BUFFER_SIZE]);
void	clean_buf(char buf[BUFFER_SIZE], char *p, size_t n);
char	*addstr(char *s, char buf[BUFFER_SIZE], size_t len);
//char	*ft_memchr(char *buf, char c, size_t n);
char	*manage_error(char *s, char buf[BUFFER_SIZE], size_t n);

#endif
