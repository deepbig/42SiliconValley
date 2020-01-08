/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_t_fdf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hryu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 01:01:07 by hryu              #+#    #+#             */
/*   Updated: 2019/09/03 23:41:53 by hryu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		setup_map_width(char *line)
{
	int		len;
	int		i;

	len = 0;
	i = 0;
	while (line[i] != '\0')
	{
		if (ft_isdigit(line[i]))
		{
			len += 1;
			while (ft_isdigit(line[i]))
				i++;
		}
		else if (line[i] != ' ' && line[i] != '-')
			ft_perror("width error: setup_map_width");
		if (line[i] != '\0')
			i++;
	}
	return (len);
}

void	setup_map_height(t_fdf *fdf, char *file)
{
	int		fd;
	char	*line;
	int		height;
	int		width;
	int		check_valid;

	if ((fd = open(file, O_RDONLY)) == -1)
		ft_perror("fd error: fd is not valid!");
	height = 0;
	while (get_next_line(fd, &line) == 1)
	{
		height++;
		width = setup_map_width(line);
		if (height == 1)
			check_valid = width;
		else if (check_valid != width)
			ft_perror("error: width length isn't equal!");
		else
			free(line);
	}
	fdf->map_height = height;
	fdf->map_width = width;
	close(fd);
}

void	setup_map_alti(t_fdf *fdf, char *file, int i, int j)
{
	char	**values;
	int		count;
	int		fd;
	char	*line;

	if ((fd = open(file, O_RDONLY)) == -1)
		ft_perror("fd error: fd is not valid!");
	while (get_next_line(fd, &line) == 1)
	{
		if (!(fdf->map_alti[i] = (int *)malloc(sizeof(int) * fdf->map_width)))
			ft_perror("malloc error: setup_map_nbr");
		values = ft_strsplit(line, ' ');
		count = -1;
		while (values[++count] != 0)
			fdf->map_alti[i][j++] = ft_atoi(values[count]);
		if (j != count)
			ft_perror("width error: setup_map_nbr");
		j = 0;
		i++;
		free(line);
	}
	if (i != fdf->map_height)
		ft_perror("height error: setup_map_nbr");
	close(fd);
}

void	setup_key_fdf(t_fdf *fdf)
{
	fdf->move_x = 0;
	fdf->move_y = 0;
	fdf->move_top = 3;
	fdf->angle_x = 0.6;
	fdf->angle_y = 0.45;
	fdf->zoom = WIDTH / (fdf->map_width + 10);
}

/*
** Because of the norm error, I process height and width together.
** setup_map_height assigns map height and width.
*/

void	setup_values_fdf(t_fdf *fdf, char *file)
{
	int		i;
	int		j;

	setup_map_height(fdf, file);
	if (!(fdf->map_alti = (int **)malloc(sizeof(int *) * fdf->map_height)))
		ft_perror("malloc error: setup_values_fdf");
	i = 0;
	j = 0;
	setup_map_alti(fdf, file, i, j);
	setup_key_fdf(fdf);
}
