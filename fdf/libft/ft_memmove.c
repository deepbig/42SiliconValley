/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hryu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 20:36:58 by hryu              #+#    #+#             */
/*   Updated: 2019/08/09 21:34:38 by hryu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** This copies len bytes from string src to string dst.
** The two strings may overlap.
** returns the original value of dst.
** IF src < dst: copy from len to backwords.
*/

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*cpdst;
	unsigned char	*cpsrc;

	cpsrc = (unsigned char *)src;
	cpdst = (unsigned char *)dst;
	i = 0;
	if (!cpsrc && !cpdst)
		return (NULL);
	if (cpsrc < cpdst)
	{
		while (i++ < len)
		{
			*(cpdst + len - i) = *(cpsrc + len - i);
		}
	}
	else
		while (len-- > 0)
		{
			*(cpdst++) = *(cpsrc++);
		}
	return (dst);
}
/*
**	if (!cpsrc[0] || !len)
**		return (dst);
*/
