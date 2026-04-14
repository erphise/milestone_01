/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_upper_hex.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: berhugue <berhugue@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 22:47:14 by berhugue          #+#    #+#             */
/*   Updated: 2026/04/07 22:47:14 by berhugue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_upper_hex(unsigned int n)
{
	if (n == 0)
		return (ft_print_char('0'));
	ft_putnum_hex(n, 1);
	return (ft_ptrlen(n));
}
