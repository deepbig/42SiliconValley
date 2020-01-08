/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hryu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 19:22:51 by hryu              #+#    #+#             */
/*   Updated: 2019/08/03 21:28:42 by hryu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** the value of the argument must be representable as an
** unsigned char or the value of EOF.
*/

int		ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}
