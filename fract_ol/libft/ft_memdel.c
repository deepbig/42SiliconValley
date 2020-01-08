/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hryu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 13:05:37 by hryu              #+#    #+#             */
/*   Updated: 2019/08/09 14:33:58 by hryu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

/*
** takes as a parameter the address of a memory area
** that needs to be freed with free(),
** then puts the pointer to NULL.
*/

void	ft_memdel(void **ap)
{
	if (ap && *ap)
	{
		free(*ap);
		*ap = NULL;
	}
}

/*
** test:
**
** #include <stdio.h>
** int		main(void)
** {
**	char	c;
**	void	*ap;
**	void	**ap2;
**
**	c = 'b';
**	ap = &c;
**	ap2 = &ap;
**	ft_memdel(ap2);
**	printf("%c", c);
**	return (0);
** }
*/
