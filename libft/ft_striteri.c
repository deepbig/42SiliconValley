/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hryu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 14:18:54 by hryu              #+#    #+#             */
/*   Updated: 2019/08/06 19:31:27 by hryu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int		i;

	i = 0;
	if (!s || !f)
		return ;
	while (*(s + i))
	{
		f(i, (s + i));
		i++;
	}
}

/*
** Test:
** #include <stdio.h>
** void	print_index(unsigned int i, char *s)
** {
** 	printf("Index: %d, char: %s\n", i, s);
** }
**
** int		main(void)
** {
** 	char	*s;
**
** 	s = "test is fun";
**	ft_striteri(s, print_index);
**	return (0);
** }
*/
