/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugutierr <ugutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/12 13:18:04 by ugutierr          #+#    #+#             */
/*   Updated: 2026/04/14 14:35:53 by ugutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f'
		|| c == '\r');
}

int	ft_atoi(const char *nptr)
{
	int	total;
	int	sign;

	sign = 1;
	total = 0;
	while (ft_isspace(*nptr))
		nptr++;
	if (*nptr == '-')
		sign = -1;
	if (*nptr == '-' || *nptr == '+')
		nptr++;
	while ('0' <= *nptr && *nptr <= '9')
	{
		total *= 10;
		total += *nptr - '0';
		nptr++;
	}
	return (sign * total);
}
//
//#include <stdio.h>
//int	main(void)
//{
//	printf("%i\n", ft_atoi("   -435"));
//	return (0);
//}
