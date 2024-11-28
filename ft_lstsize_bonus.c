/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbehra <gbehra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 15:25:31 by gbehra            #+#    #+#             */
/*   Updated: 2024/11/12 17:36:08 by gbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*cpy;
	int		i;

	cpy = lst;
	i = 0;
	if (lst == NULL)
		return (0);
	while (cpy)
	{
		cpy = cpy->next;
		i++;
	}
	return (i);
}
