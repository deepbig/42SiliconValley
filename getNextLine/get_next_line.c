/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hryu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 14:02:58 by hryu              #+#    #+#             */
/*   Updated: 2019/08/25 01:04:28 by hryu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		checkline(char **str, char **line, int reader, char *temp)
{
	int		i;

	i = -1;
	if (reader < BUFF_SIZE && !ft_strlen(*str))
	{
		ft_strdel(str);
		return (0);
	}
	while ((*str)[++i] != '\n' && (*str)[i])
		;
	if (!(*line = ft_strsub(*str, 0, i)))
	{
		ft_strdel(str);
		return (-1);
	}
	if (!(*str)[i])
		temp = NULL;
	else if (!(temp = ft_strsub(*str, i + 1, ft_strlen(*str) - i - 1)))
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

/*
**#include <fcntl.h>
**
**int		main(int argc, char **argv)
**{
**	int		fd;
**	char	*line;
**
**	if (argc == 1)
**		fd = 0;
**	else if (argc == 2)
**		fd = open(argv[1], O_RDONLY);
**	else
**		return (2);
**	while (get_next_line(fd, &line) == 1)
**	{
**		ft_putendl(line);
**		free(line);
**	}
**	if (argc == 2)
**		close(fd);
**	system("leaks gnl");
**	return (0);
**}
*/
