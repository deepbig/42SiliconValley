/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hryu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 20:51:20 by hryu              #+#    #+#             */
/*   Updated: 2019/08/08 12:57:19 by hryu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** This locates the first occurrence of c (converted to an unsigned char)
** in string s.
** returns a pointer to the byte located,
** or NULL if no such byte exists within n bytes.
** strchr stops when it hits a null char,
** memchr does not.
*/

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t		i;
	const char	*cps;

	i = 0;
	cps = (const char *)s;
	while (i < n)
	{
		if (*(cps + i) == (char)c)
			return ((void *)cps + i);
		i++;
	}
	return (NULL);
}
