/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hryu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 18:06:37 by hryu              #+#    #+#             */
/*   Updated: 2019/08/09 18:43:55 by hryu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

/*
** Iterates a list LST and applies the function F to each link
** to create a "fresh" list (malloc)
** resulting from the successive application of F.
** If allocation fails, return NULL.
*/

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*tmp;
	t_list	*begin;

	if (!lst)
		return (NULL);
	if (!(tmp = ft_lstnew(NULL, 0)))
		return (NULL);
	tmp = f(lst);
	begin = tmp;
	while (lst->next)
	{
		lst = lst->next;
		tmp->next = f(lst);
		tmp = tmp->next;
	}
	return (begin);
}

/*
** Order is matter!
** tmp = tmp->next then tmp = f(lst) generate segfault.
*/
/*
**t_list		*uf_testmap(t_list *elem)
**{
**	t_list	*new;
**	char	*content;
**	size_t	i;
**
**	content = ft_strdup((char *)(elem->content));
**	i = 0;
**	while (i < ft_strlen(content))
**	{
**		content[i] += 1;
**		++i;
**	}
**	new = ft_lstnew((void const *) content, 5);
**	free(content);
**	return (new);
**}
*/
