/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hryu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 12:56:27 by hryu              #+#    #+#             */
/*   Updated: 2019/08/08 17:51:41 by hryu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strclr(char *s)
{
	if (s)
		ft_bzero(s, ft_strlen(s));
}
/*
** or this is the easiler version of ft_strlr.
** void	ft_strclr2(char *s)
** {
**	if (s)
**		ft_bzero(s, ft_strlen(s));
** }
**
**#include <stdio.h>
**
** int		main(void)
**	{
**		char *str;
**
**		str = "Oh YEAh";
**		printf("%s\n", str);
**		ft_strclr2(str);
**		printf("%c", str[0]);
**		return (0);
**	}
*/
