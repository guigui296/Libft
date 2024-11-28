/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbehra <gbehra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 21:06:30 by gbehra            #+#    #+#             */
/*   Updated: 2024/11/13 07:20:51 by gbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nbrnb(int n)
{
	int	l;

	l = 0;
	if (n < 0)
		l++;
	if (n == 0)
		l = 1;
	while (n != 0)
	{
		l++;
		n = n / 10;
	}
	return (l);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		lg;
	long	nb;

	nb = n;
	lg = ft_nbrnb(n);
	str = (char *)malloc(lg + 1);
	if (!str)
		return (NULL);
	str[lg] = '\0';
	if (nb < 0)
	{
		str[0] = '-';
		nb = -nb;
	}
	while (--lg >= 0 && str[lg] != '-')
	{
		str[lg] = (nb % 10) + '0';
		nb /= 10;
	}
	return (str);
}
