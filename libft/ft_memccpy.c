/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hryu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 20:03:01 by hryu              #+#    #+#             */
/*   Updated: 2019/08/04 20:32:22 by hryu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** this copies bytes from string src to string dst.
** If the character c (as converted to an unsigned char)
** occurs in the string src, the copy stops and a pointer to the btye
** after the copy of c in the string dst is returned.
** Otherwise, n bytes are copied, and a NULL pointer is returned.
*/

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*cpdst;
	unsigned char	*cpsrc;
	size_t			i;

	i = 0;
	cpdst = (unsigned char *)dst;
	cpsrc = (unsigned char *)src;
	while (i < n)
	{
		cpdst[i] = cpsrc[i];
		if ((unsigned char)c == cpsrc[i])
		{
			return (&dst[i + 1]);
		}
		i++;
	}
	return (NULL);
}
