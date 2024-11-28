/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbehra <gbehra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 11:38:47 by gbehra            #+#    #+#             */
/*   Updated: 2024/11/13 07:21:09 by gbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*g;
	const unsigned char	*e;

	g = s;
	e = g + n;
	while (g < e)
	{
		if (*g == (unsigned char)c)
		{
			return ((void *)g);
		}
		g++;
	}
	return ((void *)0);
}
