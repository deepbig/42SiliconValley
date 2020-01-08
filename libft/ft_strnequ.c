/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hryu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 19:19:45 by hryu              #+#    #+#             */
/*   Updated: 2019/08/06 19:28:28 by hryu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	if (!s1 || !s2)
		return (0);
	return (ft_strncmp(s1, s2, n) ? 0 : 1);
}

/*
** test:
** #include <stdio.h>
** int main(void)
** {
** 	char const *s1;
**	char const *s2;
**	size_t		i;
**
**	s1 = "WOW";
**	s2 = "HHT";
**	i = 1;
**	printf("%d", ft_strnequ(s1, s2, i));
**	return(0);
** }
*/
