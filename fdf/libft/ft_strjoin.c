/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hryu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 20:21:09 by hryu              #+#    #+#             */
/*   Updated: 2019/08/25 00:45:47 by hryu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Allocates (with malloc) and return a "fresh" string ending with '\0',
** result of the concatenation of s1 and s2.
** if the allocation fails the funtion return NULL.
** use ft_strcat?
*/

#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	j = 0;
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (!str)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j])
		str[i++] = s2[j++];
	str[i] = '\0';
	return (str);
}

/*
** test:
** #include <stdio.h>
** int		main(void)
** {
**	char const *s1;
**	char const *s2;
**
**	s1 = "Please";
**	s2 = "HOLLY";
**	printf("%s", ft_strjoin(s1, s2));
**	return (0);
**}
*/
