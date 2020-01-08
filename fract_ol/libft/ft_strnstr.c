/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hryu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 17:24:22 by hryu              #+#    #+#             */
/*   Updated: 2019/08/08 17:42:12 by hryu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** strnstr() - where not more than len char are searched.
** char that appear after a '\0' char are not searched.
** IF Len is >= &haystack[i], it print.
** Otherwise, it will return NULL.
*/

#include "libft.h"

char	*ft_strnstr(const char *hay, const char *nee, size_t len)
{
	size_t	i;
	size_t	j;
	int		count;

	i = 0;
	count = ft_strlen(nee);
	if (!ft_strlen(nee))
		return ((char *)hay);
	while (hay[i] && (size_t)i < len)
	{
		if (hay[i] == nee[0])
		{
			count = i;
			j = 1;
			while (nee[j] && hay[count + j] && hay[count + j] == nee[j]
					&& (size_t)(j + count) < len)
				j++;
			if (nee[j] == '\0')
				return ((char *)hay + count);
		}
		i++;
	}
	return (NULL);
}
