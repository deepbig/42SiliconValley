/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hryu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 21:10:41 by hryu              #+#    #+#             */
/*   Updated: 2019/08/05 14:08:59 by hryu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** This compares byte string s1 against byte string s2.
** Both strings are assumed to be n bytes long.
** Returns (treated as unsigned char value)
*/

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*cps1;
	unsigned char	*cps2;

	i = 0;
	cps1 = (unsigned char *)s1;
	cps2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while (i < n)
	{
		if (cps1[i] != cps2[i])
			return (cps1[i] - cps2[i]);
		i++;
	}
	return (cps1[i - 1] - cps2[i - 1]);
}
