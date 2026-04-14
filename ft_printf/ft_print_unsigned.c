/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: berhugue <berhugue@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 22:47:10 by berhugue          #+#    #+#             */
/*   Updated: 2026/04/07 22:47:10 by berhugue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_unsigned(unsigned int n)
{
	char	buffer[11];
	int		len;
	int		i;

	i = 10;
	buffer[i] = '\0';
	if (n == 0)
		buffer[--i] = '0';
	else
	{
		while (n > 0)
		{
			buffer[--i] = (n % 10) + '0';
			n /= 10;
		}
	}
	len = ft_print_str(&buffer[i]);
	return (len);
}
