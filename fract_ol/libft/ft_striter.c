/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hryu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 13:13:22 by hryu              #+#    #+#             */
/*   Updated: 2019/08/06 19:34:04 by hryu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_striter(char *s, void (*f)(char *))
{
	int		i;

	i = 0;
	if (!s || !f)
		return ;
	while (s[i])
	{
		f(&s[i++]);
	}
}

/*
** Test:
** #include <unistd.h>
** #include <stdio.h>
** void	printChar(char *c)
** {
** 	printf("%s\n", c);
** }
**
** int		main(void)
** {
**	char	*s;
**
**	s = "OOH YEEAH";
**	ft_striter(s, printChar);
**	return (0);
** }
*/
