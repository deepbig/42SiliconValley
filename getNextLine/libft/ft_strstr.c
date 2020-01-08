/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hryu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 17:01:59 by hryu              #+#    #+#             */
/*   Updated: 2019/08/08 19:37:46 by hryu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** if needle is an empty string, haystack is returned.
** if needle occurs nowhere in haystack, NULL is returned.
** strstr() locates the first occurrence of the null-terminated string
*/

char	*ft_strstr(const char *haystack, const char *needle)
{
	int		i;
	int		j;
	int		count;

	i = 0;
	count = ft_strlen(needle);
	if (!needle[0])
		return ((char *)haystack);
	while (haystack[i])
	{
		j = 0;
		while (needle[j] && haystack[i + j] == needle[j])
			j++;
		if (!needle[j])
			return ((char *)&haystack[i]);
		i++;
	}
	return (NULL);
}
