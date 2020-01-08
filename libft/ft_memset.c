/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hryu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 20:38:00 by hryu              #+#    #+#             */
/*   Updated: 2019/08/21 14:15:32 by hryu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** this writes len bytes of value c (converted to an unsigned char)
** to the string b.
** int myInt;
** unsigned char myChar;
** myChar = (unsigned char)myInt;
*/

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*str;

	i = 0;
	str = (unsigned char *)b;
	while (i < len)
		str[i++] = (unsigned char)c;
	return (b);
}
