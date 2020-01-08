/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hryu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 18:48:44 by hryu              #+#    #+#             */
/*   Updated: 2019/08/06 19:33:24 by hryu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

/*
** ft_strnew(size_t) this will create a new string using malloc.
*/

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	index;
	int				i;
	char			*c;

	index = 0;
	i = 0;
	if (!s || !f)
		return (NULL);
	c = ft_strnew((size_t)ft_strlen(s));
	if (!c)
		return (NULL);
	while (s[i])
	{
		c[i] = f(i, s[i]);
		i++;
	}
	return (c);
}

/*
** Test:
** #include <stdio.h>
** char	print_index(unsigned int i, char s)
** {
** 	s -= 32;
**	printf("Index: %d, char: %c\n", i, s);
**	return (s);
** }
** int		main(void)
** {
**	char *s;
**	s = "test is fun fun";
**	ft_strmapi(s, print_index);
**	printf("%s", s);
**	return (0);
** }
*/
