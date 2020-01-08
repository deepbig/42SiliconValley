/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hryu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 19:05:38 by hryu              #+#    #+#             */
/*   Updated: 2019/08/08 20:29:12 by hryu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Lexicographical comparison between s1 and s2.
** If the 2 string are identical the funtion returns 1, or 0 otherwise.
*/

int		ft_strequ(char const *s1, char const *s2)
{
	if (!s1 || !s2)
		return (0);
	return (ft_strcmp(s1, s2) ? 0 : 1);
}

/*
** original way to do:
**	int		i;
**
**	i = 0;
**	if (!s1 && !s2)
**		return (1);
**	if (!s1 || !s2)
**		return (0);
**	while (s1[i])
** {
**		if (s1[i] != s2[i])
**			return (0);
**		i++;
**	}
**	return (1);
*/
