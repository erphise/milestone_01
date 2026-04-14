/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_lower_hex.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: berhugue <berhugue@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 22:46:59 by berhugue          #+#    #+#             */
/*   Updated: 2026/04/08 00:05:52 by berhugue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_lower_hex(unsigned int n)
{
	if (n == 0)
		return (ft_print_char('0'));
	ft_putnum_hex(n, 0);
	return (ft_ptrlen(n));
}
