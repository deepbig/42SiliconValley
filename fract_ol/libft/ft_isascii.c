/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hryu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 19:57:11 by hryu              #+#    #+#             */
/*   Updated: 2019/08/03 20:09:43 by hryu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** isascii tests for an ASCII char,
** which is any char between 0 and octal 0177 inclusive.
** in the range 0 to 127.
*/

int		ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}
