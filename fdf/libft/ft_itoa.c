/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hryu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 21:05:03 by hryu              #+#    #+#             */
/*   Updated: 2019/08/10 13:15:32 by hryu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_itoa(int n)
{
	char			*str;
	int				i;
	unsigned int	cpn;

	i = ft_intlen(n);
	cpn = n;
	if (n < 0)
	{
		i++;
		cpn = -n;
	}
	if (!(str = ft_strnew(i)))
		return (NULL);
	str[i] = '\0';
	if (cpn == 0)
		str[--i] = '0';
	while (cpn != 0)
	{
		str[--i] = cpn % 10 + '0';
		cpn /= 10;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}
