/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hryu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 14:02:58 by hryu              #+#    #+#             */
/*   Updated: 2019/08/28 14:56:03 by hryu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		checkline(char **str, char **line, int reader, char *temp)
{
	char	*max;
	size_t	size;

	size = ft_strlen(*str);
	if (reader < BUFF_SIZE && !size)
	{
		ft_strdel(str);
		return (0);
	}
	if (NULL == (max = ft_strchr((*str), '\n')))
		max = (*str) + size;
	if (NULL == (*line = ft_strsub(*str, 0, max - (*str))))
	{
		ft_strdel(str);
		return (-1);
	}
	if (*max == '\0')
		temp = NULL;
	else if ((temp = ft_strsub(*str, max - (*str) + 1, size - (max - (*str)) - 1)) == NULL)
	{
		ft_strdel(str);
		return (-1);
	}
	ft_strdel(str);
	*str = temp;
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	char			buf[BUFF_SIZE + 1];
	static char		*str[4096];
	int				reader;
	char			*temp;

	if (fd < 0 || read(fd, buf, 0) < 0 || line == NULL)
		return (-1);
	if (!str[fd])
		str[fd] = ft_strnew(0);
	while ((reader = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[reader] = '\0';
		if (!(temp = ft_strjoin(str[fd], buf)))
		{
			ft_strdel(&str[fd]);
			return (-1);
		}
		ft_strdel(&str[fd]);
		str[fd] = temp;
		if (ft_strchr(buf, '\n'))
			break ;
	}
	if (reader < 0)
		return (-1);
	return (checkline(&str[fd], line, reader, temp));
}
