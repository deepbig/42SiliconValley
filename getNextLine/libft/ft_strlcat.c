/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hryu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 21:37:11 by hryu              #+#    #+#             */
/*   Updated: 2019/08/08 12:32:22 by hryu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** if dstsize < i + j --> output string has been truncated.
** dstsize - i - one >= j
*/

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t		i;
	size_t		j;
	size_t		len;

	i = ft_strlen(dst);
	j = ft_strlen(src);
	len = 0;
	if (dstsize <= i)
		len = j + dstsize;
	else
		len = j + i;
	j = 0;
	while (src[j] && i + 1 < dstsize)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (len);
}
