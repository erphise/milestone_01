/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugutierr <ugutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/12 18:08:21 by ugutierr          #+#    #+#             */
/*   Updated: 2026/04/14 14:46:48 by ugutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*pos_itoa(int n)
{
	char	*p1;
	char	*p2;
	char	*p3;

	if (n < 10)
	{
		p1 = ft_calloc(2, sizeof(char));
		if (!p1)
			return (NULL);
		*p1 = n + '0';
		return (p1);
	}
	p1 = pos_itoa(n / 10);
	if (!p1)
		return (NULL);
	p2 = pos_itoa(n % 10);
	if (!p2)
	{
		free(p1);
		return (NULL);
	}
	p3 = ft_strjoin(p1, p2);
	free(p1);
	free(p2);
	return (p3);
}

char	*ft_itoa(int n)
{
	char	*p1;
	char	*p2;

	if (n == INT_MIN)
		return (ft_strdup("-2147483648"));
	if (n < 0)
	{
		p1 = pos_itoa(-n);
		if (!p1)
			return (NULL);
		p2 = ft_strjoin("-", p1);
		free(p1);
		return (p2);
	}
	return (pos_itoa(n));
}
//#include <stdio.h>
//int	main(void)
//{
//	printf("%s\n", ft_itoa(-42));
//}
