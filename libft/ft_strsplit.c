/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hryu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 21:08:24 by hryu              #+#    #+#             */
/*   Updated: 2019/08/10 13:43:28 by hryu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/*
** Allocate (with malloc) and returns an array of "fresh" string
** (all ending with '\0', including the array itself)
** obtained by spliting s using the character c as a delimiter.
** If the allocation fails the function returns NULL.
** Example: ft_strsplit("*hello*fellow***students*", '*')
** return: ["hello", "hellow", "students"].
*/

char			**ft_strsplit(char const *s, char c)
{
	char	**str;
	int		i;
	int		len;
	int		j;

	if (!s || !(str = (char **)malloc(sizeof(*str) * (ft_arrlen(s, c) + 1))))
		return (NULL);
	i = 0;
	j = 0;
	while (i < ft_arrlen(s, c))
	{
		if (!(str[i] = ft_strnew(ft_splitlen(s, j, c) + 1)))
			str[i] = NULL;
		while (s[j] == c)
			j++;
		len = 0;
		while (s[j] != c && s[j])
			str[i][len++] = s[j++];
		str[i][len] = '\0';
		i++;
	}
	str[i] = 0;
	return (str);
}
