/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hryu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 20:38:52 by hryu              #+#    #+#             */
/*   Updated: 2019/08/20 21:23:00 by hryu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

/*
** Allocate (malloc) and return a "fresh" link.
** The variable CONTENT and CONTENT_SIZE of the new link are
** initialized by COPY of the parameters of the function.
** If the parameter CONTENT is NULL, the variable CONTENT is
** initialized to NULL and the size is initialized to 0
** even if the parameter content_size isn't.
** the variable next is initialized to NULL.
** If allocation fails, the function rturn NULL.
*/

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*tmp;

	if (!(tmp = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	if (content == NULL)
	{
		tmp->content = NULL;
		tmp->content_size = 0;
	}
	else
	{
		if (!(tmp->content = (void *)malloc(content_size)))
			return (NULL);
		ft_memcpy(tmp->content, content, content_size);
		tmp->content_size = content_size;
	}
	tmp->next = NULL;
	return (tmp);
}

/*
** #include <stdio.h>
**
**int main(void)
**{
**	char str[] = "hello";
**	size_t size = 5;
**	t_list	*tes;
**
**	tes = ft_lstnew(str, size);
**	printf("%s, %zd", tes->content, tes->content_size);
**	return(0);
**}
*/
