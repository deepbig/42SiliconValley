/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hryu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 20:41:15 by hryu              #+#    #+#             */
/*   Updated: 2019/08/10 13:17:36 by hryu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Allocates (with malloc) and returns a copy of the stirng
** given as argument without whitespaces
** at the biggining or at the end of the string.
** Will be considered as whitespaces: ' ', '\n', and '\t'.
** If "s" has no whitespaces at the begiining or at the end,
** the function returns a copy of s.
** If the allocation fails the funciton returns NULL.
*/

#include "libft.h"
#include <stdlib.h>

char	*ft_strtrim(char const *s)
{
	char	*c;
	int		len;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	len = 0;
	while (s[i] && (s[i] == ' ' || s[i] == '\n' || s[i] == '\t'))
		i++;
	len = ft_strlen(s + i) - 1;
	while (s[i] &&
			(s[i + len] == ' ' || s[i + len] == '\n' || s[i + len] == '\t'))
		len--;
	if (!(c = ft_strnew(len + 1)))
		return (NULL);
	ft_strncpy(c, (s + i), (len + 1));
	return (c);
}
