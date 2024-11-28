/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbehra <gbehra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 08:30:54 by gbehra            #+#    #+#             */
/*   Updated: 2024/11/12 18:02:29 by gbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*new_str;
	size_t	strt;
	size_t	end;

	if (!s1 || !set)
		return (NULL);
	end = ft_strlen(s1) - 1;
	strt = 0;
	while (s1[strt] && ft_strchr(set, s1[strt]))
		strt++;
	while (s1[end] && ft_strchr(set, s1[end]))
		end--;
	new_str = ft_substr(s1, strt, end - strt + 1);
	return (new_str);
}
