/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hryu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 13:49:35 by hryu              #+#    #+#             */
/*   Updated: 2019/08/21 14:18:22 by hryu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

/*
** takes as a parameter the address of a string that need to be freed.
** then sets its pointer to NULL.
*/

void	ft_strdel(char **as)
{
	if (!as || !*as)
		return ;
	free(*as);
	*as = NULL;
}

/*
** Test:
** #include <stdio.h>
** int		main(void)
** {
** 	char	**str;
**	int		i;
**	int		j;
**	i = 0;
**	j = 0;
**	str[0] = "this is test.";
**	ft_strdel(str);
**	printf("%s", str[0]);
**	return (0);
** }
*/
