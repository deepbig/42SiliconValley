/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hryu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 14:43:44 by hryu              #+#    #+#             */
/*   Updated: 2019/08/09 17:48:06 by hryu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Adds the element NEW at the beginning of the list.
** alst is the addrss of a pointer to the first link of a list.
** new_node->next = (*head_ref); <- Make next of new node as head.
** (head_ref) = new_node; <- Move the head to point to the new node.
*/

void	ft_lstadd(t_list **alst, t_list *new)
{
	new->next = *alst;
	*alst = new;
}

/*
**#include <stdio.h>
**int		main(void)
**{
**	t_list	*begin;
**	t_list	*add;
**	t_list	*tmp;
**	size_t	v;
**	size_t	c;
**
**	v = 1;
**	c = 2;
**	begin = ft_lstnew(&v, sizeof(size_t));
**	tmp = begin;
**	add = ft_lstnew(&v, sizeof(size_t));
**	ft_lstadd(&begin, add);
**	if (begin != add)
**		printf("Error1");
**	if (begin->next != tmp)
**		printf("Error2");
**	return (0);
**}
*/
