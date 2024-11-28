/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbehra <gbehra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 19:56:55 by gbehra            #+#    #+#             */
/*   Updated: 2024/11/13 07:21:57 by gbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nbrword(const char *str, char sep)
{
	int	nbr;

	nbr = 0;
	while (*str)
	{
		while (*str == sep)
			str++;
		if (*str)
		{
			nbr++;
			while (*str && *str != sep)
				str++;
		}
	}
	return (nbr);
}

static char	*ft_sub(const char *str, int l)
{
	char	*word;
	int		i;

	word = malloc(sizeof(char) * (l + 1));
	i = 0;
	if (!word)
		return (NULL);
	while (i < l)
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

static int	ft_word_len_add(char **res, const char *s, char c, int i)
{
	int	len;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	res[i] = ft_sub(s, len);
	if (!res[i])
		return (0);
	return (len);
}

static void	*ft_free_split(char	**res, size_t o)
{
	while (o > 0)
	{
		o--;
		free(res[o]);
	}
	free(res);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		i;
	int		len;

	i = 0;
	if (!s)
		return (NULL);
	res = malloc(sizeof(char *) * (ft_nbrword(s, c) + 1));
	if (!res)
		return (NULL);
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			len = ft_word_len_add(res, s, c, i);
			if (!len)
				return (ft_free_split(res, i));
			i++;
			s += len;
		}
	}
	res[i] = NULL;
	return (res);
}
