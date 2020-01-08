/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hryu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 17:48:03 by hryu              #+#    #+#             */
/*   Updated: 2019/08/08 20:06:35 by hryu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

/*
** Applies the function f to each character of the string given as
** argument to create a "fresh" new string (malloc) resulting
** from the successive application of f;
*/

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*c;
	int		i;

	i = 0;
	if (!f || !s)
		return (NULL);
	c = ft_strnew(ft_strlen(s));
	if (!c)
		return (NULL);
	while (*(s + i))
	{
		c[i] = f(s[i]);
		i++;
	}
	return (c);
}

/*
** test
** #include <stdio.h>
** char  strchange(char c)
**{
**	c += 32;
**	return (c);
** }
** int main()
** {
**	char const *ptr;
**	char	(*f)(char);
**
**	f = strchange;
**	ptr = "HOW";
**	ptr = ft_strmap(ptr, f);
**	printf("%s", ptr);
**	return (0);
**}
*/
