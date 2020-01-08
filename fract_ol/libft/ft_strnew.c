/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hryu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 13:40:59 by hryu              #+#    #+#             */
/*   Updated: 2019/08/20 21:15:29 by hryu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

/*
** Allocates malloc and return a fresh string ending with '\0'.
** each char of the string is initialiezd at '\0'/
** If the allocation fails the function return NULL.
** return: the string allocated and initialized to 0.
*/

char	*ft_strnew(size_t size)
{
	char	*str;
	size_t	i;

	i = 0;
	str = (char *)malloc(sizeof(char) * size + 1);
	if (!str)
		return (NULL);
	ft_bzero(str, size + 1);
	return (str);
}

/*
** or you can use bzero
** ft_bzero(str, size + 1);
*/
