/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hryu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 14:43:53 by hryu              #+#    #+#             */
/*   Updated: 2019/08/09 18:05:41 by hryu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Iterates the list LST and applies the function f to each link.
*/

void	ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	while (lst)
	{
		f(lst);
		lst = lst->next;
	}
}
/*
**void	testfunction(t_list *elem)
**{
**	elem->content = elem->content + 1;
**}
**#include <stdio.h>
**int		main(void)
**{
**	t_list	*begin;
**	size_t	i;
**	size_t	j;
**
**	i = 1;
**	j = 2;
**	begin = ft_lstnew(&i, sizeof(size_t));
**	begin->next = ft_lstnew(&j, sizeof(size_t));
**	printf("%zd begin", (size_t)begin->content);
**	printf("\n%zu begin->next", (size_t)begin->next->content);
**
**	ft_lstiter(begin, testfunction);
**	printf("\n%zu begin", (size_t)begin->content);
**	printf("\n%zu begin->next", (size_t)begin->next->content);
**	return (0);
**}
*/
