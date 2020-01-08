/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hryu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 12:36:09 by hryu              #+#    #+#             */
/*   Updated: 2019/08/06 17:47:15 by hryu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

/*
** How to test whether it worked or not?
** malloc returns a null pointer on failure.
*/

void	*ft_memalloc(size_t size)
{
	void	*ptr;

	ptr = malloc(size);
	if (!(ptr = malloc(size)))
		return (NULL);
	ft_bzero(ptr, size);
	return (ptr);
}

/*
** test:
** #include <memory.h>
** #include <stdio.h>
** #include <string.h>
**
** int main ()
** {
**	size_t	i;
**	void	*a;
**	size_t	b;
**
**	i = 3;
**	a = ft_memalloc(i);
**	b = (size_t)a;
**	printf("%zu", b);
**	return(0);
** }
*/
