/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbehra <gbehra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 09:31:17 by gbehra            #+#    #+#             */
/*   Updated: 2024/11/13 10:18:55 by gbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*tmp;
	size_t			total_size;
	size_t			i;

	total_size = nmemb * size;
	i = 0;
	tmp = malloc(total_size);
	if (nmemb != 0 && total_size / nmemb != size)
		return (NULL);
	if (!tmp)
		return (NULL);
	while (i < total_size)
	{
		tmp[i] = 0;
		i++;
	}
	return ((void *)tmp);
}
