/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_image.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hryu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 21:14:48 by hryu              #+#    #+#             */
/*   Updated: 2019/09/03 23:27:46 by hryu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** mlx_key_hook (void *win_ptr, int (*funct_ptr)(), void *param);
**  => mlx_key_hook(fdf->win_ptr, setup_image, fdf);
** This function should return int.
*/

int		ft_color(t_fdf *fdf)
{
	int		color;
	int		x;
	int		y;
	int		t;

	color = 0;
	x = fdf->print.x_orig;
	y = fdf->print.y_orig;
	t = fdf->map_alti[y][x];
	t >= 10 ? color = RED * 221 + GREEN * 77 + BLUE * 67 : color;
	t >= 8 && t < 10 ? color = RED * 221 + GREEN * 77 + BLUE * 67 : color;
	t >= 6 && t < 8 ? color = RED * 157 + GREEN * 55 + BLUE * 68 : color;
	t >= 4 && t < 6 ? color = RED * 254 + GREEN * 132 + BLUE * 42 : color;
	t >= 2 && t < 4 ? color = RED * 252 + GREEN * 118 + BLUE * 106 : color;
	t > 0 && t < 2 ? color = RED * 200 + GREEN * 62 + BLUE * 115 : color;
	t == 0 ? color = RED * 141 + GREEN * 148 + BLUE * 64 : color;
	t >= -2 && t < 0 ? color = RED * 253 + GREEN * 214 + BLUE * 94 : color;
	t >= -4 && t < -2 ? color = RED * 45 + GREEN * 92 + BLUE * 158 : color;
	t < -4 ? color = RED * 217 + GREEN * 159 + BLUE * 60 : color;
	return (color);
}

void	draw_lines(t_fdf *fdf, double x_s, double y_s)
{
	double	z;
	double	x_z;
	double	y_z;
	int		i;

	x_s = fdf->print.x_start;
	y_s = fdf->print.y_start;
	x_z = fdf->print.x_end - fdf->print.x_start;
	y_z = fdf->print.y_end - fdf->print.y_start;
	z = pow(x_z, 2) + pow(y_z, 2);
	x_z = x_z / z;
	y_z = y_z / z;
	while (z > 0)
	{
		if (x_s > 0 && x_s < WIDTH && y_s > 0 && y_s < HEIGHT)
		{
			i = (int)x_s + (int)y_s * WIDTH;
			fdf->image.data[i] = ft_color(fdf);
		}
		x_s += x_z;
		y_s += y_z;
		z--;
	}
}

void	set_end_point(t_fdf *fdf, int x, int y, int check)
{
	if (check == 1)
	{
		fdf->print.x_end = fdf->angle_x * \
			((fdf->print.x_to_print + 1) - fdf->print.y_to_print) * \
			fdf->zoom + (WIDTH / 2) + fdf->move_x;
		fdf->print.y_end = fdf->angle_y * \
			((fdf->print.x_to_print + 1) + fdf->print.y_to_print) * \
			fdf->zoom - fdf->map_alti[y][x + 1] * \
			fdf->move_top + (HEIGHT / 2) + fdf->move_y;
	}
	if (check == 2)
	{
		fdf->print.x_end = fdf->angle_x * \
			(fdf->print.x_to_print - (fdf->print.y_to_print + 1)) * \
			fdf->zoom + (WIDTH / 2) + fdf->move_x;
		fdf->print.y_end = fdf->angle_y * \
			(fdf->print.x_to_print + (fdf->print.y_to_print + 1)) * \
			fdf->zoom - fdf->map_alti[y + 1][x] * \
			fdf->move_top + (HEIGHT / 2) + fdf->move_y;
	}
}

void	setup_line(t_fdf *fdf, int x, int y, int check)
{
	double	x_s;
	double	y_s;

	fdf->print.x_orig = x;
	fdf->print.y_orig = y;
	fdf->print.x_to_print = x - fdf->map_width / 2;
	fdf->print.y_to_print = y - fdf->map_height / 2;
	fdf->print.x_start = fdf->angle_x \
		* (fdf->print.x_to_print - fdf->print.y_to_print) \
		* fdf->zoom + (WIDTH / 2) + fdf->move_x;
	fdf->print.y_start = fdf->angle_y \
		* (fdf->print.x_to_print + fdf->print.y_to_print) \
		* fdf->zoom - fdf->map_alti[y][x] \
		* fdf->move_top + (HEIGHT / 2) + fdf->move_y;
	set_end_point(fdf, x, y, check);
	x_s = fdf->print.x_start;
	y_s = fdf->print.y_start;
	draw_lines(fdf, x_s, y_s);
}

/*
** getting the image's char pointer: mlx_get_data_addr.
** mlx_get_data_addr(img_ptr, &bpp, &size_line, &endian);
** YOU DON'T NEED TO initialize them, it will do it for you.
**
** displaying the image: mlx_put_image_to window.
*/

int		setup_image(t_fdf *fdf)
{
	int		x;
	int		y;

	fdf->img_ptr = mlx_new_image(fdf->mlx_ptr, WIDTH, HEIGHT);
	fdf->image.data = (int *)mlx_get_data_addr(fdf->img_ptr, \
			&fdf->image.bpp, &fdf->image.size_line, &fdf->image.endian);
	y = -1;
	while (++y < fdf->map_height)
	{
		x = -1;
		while (++x < fdf->map_width)
		{
			if (x + 1 < fdf->map_width)
				setup_line(fdf, x, y, 1);
			if (y + 1 < fdf->map_height)
				setup_line(fdf, x, y, 2);
		}
	}
	mlx_put_image_to_window(fdf->mlx_ptr, fdf->win_ptr, fdf->img_ptr, 0, 0);
	mlx_destroy_image(fdf->mlx_ptr, fdf->img_ptr);
	return (0);
}

/*
** file to image does not work in this way.
** fdf->img_ptr = mlx_xpm_file_to_image(fdf->mlx_ptr, filename, \
** 	fdf->(*map_alti), fdf->(*map_alti));
*/
