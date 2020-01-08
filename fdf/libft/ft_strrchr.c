/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hryu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 16:42:48 by hryu              #+#    #+#             */
/*   Updated: 2019/08/03 21:25:06 by hryu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** strrchr is located in the last occurrence of char in str.
*/

char	*ft_strrchr(const char *s, int c)
{
	int		count;

	count = 0;
	while (s[count])
		count++;
	while (count != -1 && s[count] != (char)c)
		count--;
	if (count == -1)
		return (NULL);
	return ((char *)&s[count]);
}
