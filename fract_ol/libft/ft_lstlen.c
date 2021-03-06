/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hryu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 13:26:12 by hryu              #+#    #+#             */
/*   Updated: 2019/08/10 13:39:19 by hryu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

int		ft_lstlen(t_list *lst)
{
	int		i;

	i = 1;
	while (lst->next)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}
