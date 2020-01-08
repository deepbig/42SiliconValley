/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hryu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 19:35:08 by hryu              #+#    #+#             */
/*   Updated: 2019/08/25 00:42:55 by hryu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/*
** Allocates (with malloc) and returns a "fresh" substring
** from the string given as argument. The substring begins
** at index start and is of size len.
** If start and len aren't refering to a valid substring,
** the behavior is undefined.
** If the allocation fails, the function returns NULL.
*/

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*c;
	int		i;

	i = 0;
	c = (char *)malloc(sizeof(char) * (len + 1));
	if (!s || !c)
		return (NULL);
	while (len--)
	{
		c[i] = s[start];
		i++;
		start++;
	}
	c[i] = '\0';
	return (c);
}
/*
** I can use ft_strncpy:
** c = ft_strncpy(c, ((char *)s + start), len);
*/

/*
** test:
** #include <stdio.h>
**int		main(void)
**{
**	char *str;
**
**	str = "Holly Jesus";
**	printf("%s", ft_strsub(str, 6, 4));
**	return (0);
**}
*/
