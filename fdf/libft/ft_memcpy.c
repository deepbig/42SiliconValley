/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hryu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 19:16:27 by hryu              #+#    #+#             */
/*   Updated: 2019/08/20 21:43:22 by hryu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** this copies n bytes from memory area src to dst.
** If dst and src overlap, behavior is undefined.
** Applications in overlap should use memmove(3) instead.
*/

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*cpdst;
	unsigned char	*cpsrc;

	cpdst = (unsigned char *)dst;
	cpsrc = (unsigned char *)src;
	if (!cpdst && !cpsrc)
		return (NULL);
	while (n-- > 0)
	{
		*(cpdst++) = *(cpsrc++);
	}
	return (dst);
}
