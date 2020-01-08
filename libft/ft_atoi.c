/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hryu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 18:47:29 by hryu              #+#    #+#             */
/*   Updated: 2019/08/10 13:15:42 by hryu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int		nb;
	int		sign;
	int		i;

	i = 0;
	nb = 0;
	sign = 1;
	while (str[i] && (str[i] == '\f' || str[i] == '\t' || str[i] == '\n' ||
	str[i] == ' ' || str[i] == '\v' || str[i] == '\r'))
		i++;
	if (!(str[i]))
		return (0);
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
		nb = nb * 10 + (str[i++] - '0');
	return (nb * sign);
}
