/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: berhugue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 22:45:31 by berhugue          #+#    #+#             */
/*   Updated: 2026/04/07 22:45:37 by berhugue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "ft_libft/libft.h"
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

// Principal
int		ft_printf(char const *s, ...);

// Conversions
int		ft_print_char(char c);
int		ft_print_str(char *s);
int		ft_print_ptr(void *p);
int		ft_print_int(int n);
int		ft_print_unsigned(unsigned int n);
int		ft_print_lower_hex(unsigned int n);
int		ft_print_upper_hex(unsigned int n);

// Auxiliars
int		ft_check_char(va_list *args, char c);
int		ft_ptrlen(unsigned long long num);
void	ft_putnum_hex(unsigned long num, int uppercase);

#endif