/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hryu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 20:15:00 by hryu              #+#    #+#             */
/*   Updated: 2019/08/03 20:24:19 by hryu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** this function test for any pringting char, including space.
** value of the arg must represetable as an unsigned char.
** whether the passed character is printable.
** printable character is a character that is not a control character.
*/

int		ft_isprint(int c)
{
	return (c >= 32 && c <= 126);
}
