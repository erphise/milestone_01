/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: berhugue <berhugue@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 22:46:54 by berhugue          #+#    #+#             */
/*   Updated: 2026/04/08 00:01:07 by berhugue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_int(int n)
{
	char	*num_str;
	int		len;

	num_str = ft_itoa(n);
	if (!num_str)
		return (0);
	len = ft_strlen(num_str);
	ft_print_str(num_str);
	free(num_str);
	return (len);
}
