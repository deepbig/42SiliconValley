/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hryu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 13:53:07 by hryu              #+#    #+#             */
/*   Updated: 2019/08/09 14:36:16 by hryu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

/*
** Takes a parameter a link's pointer address and
** frees the memory of the link's content using
** function DEL given as a parameter,
** then frees the link's memory using free.
** The memory of next must not be freed unster any circumstance.
** The pointer to the link that was just freed must be set to NULL
** (similar to the function ft_memdel).
*/

void	ft_lstdelone(t_list **alst, void (*del)(void *, size_t))
{
	del((*alst)->content, (*alst)->content_size);
	free(*alst);
	*alst = NULL;
}

/*
** #include <stdio.h>
**int		main(void)
**{
**	t_list	*test;
**
**	test = ft_lstnew("TestTestYes!", 12);
**	printf("%s, %zu", test->content, test->content_size);
**	void (*del)(void *, size_t) = &ft_bzero;
**	ft_lstdelone(&test, ft_bzero);
**	printf("%s, %zu", test->content, test->content_size);
**	return (0);
**}
*/
