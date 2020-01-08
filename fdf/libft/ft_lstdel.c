/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hryu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 14:43:34 by hryu              #+#    #+#             */
/*   Updated: 2019/08/10 13:50:04 by hryu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

/*
** Takes as a parameter the adress of a pointer to a link and
** free the memory of this link and every successors of that link
** using the function del and free.
** Finally the pointer to the link that was just freed must be NULL.
** Understanding **alst means storing address of t_list *alst.
** therefore, *alst = actual address of alst.
*/

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*t1;
	t_list	*t2;

	t1 = *alst;
	while (t1)
	{
		t2 = t1->next;
		del(t1->content, t1->content_size);
		free(t1);
		t1 = t2;
	}
	*alst = NULL;
}

/*
**#include <stdio.h>
**
**int		main(void)
**{
**	t_list	*begin;
**	size_t	v;
**
**	v = 1;
**	begin = ft_lstnew(&v, sizeof(void *));
**	begin->next = ft_lstnew(&v, sizeof(void *));
**	begin->next->next = ft_lstnew(&v, sizeof(void *));
**	if (begin != NULL)
**		printf("1.It is not Null!");
**	ft_lstdel(&begin, ft_lstdel_f);
**	if (begin != NULL)
**		printf("2.It is not Null!");
**	return (0);
**}
*/
