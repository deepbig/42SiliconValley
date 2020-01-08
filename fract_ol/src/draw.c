/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hryu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 00:48:34 by hryu              #+#    #+#             */
/*   Updated: 2019/11/15 03:26:27 by hryu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void		put_pixel(t_fractol *fractol, int x, int y, t_color color)
{
	int	i;

	i = (x * fractol->image->bits_per_pixel / 8)
		+ (y * fractol->image->size_line);
	fractol->image->data_addr[i] = color.channel[3];
	fractol->image->data_addr[++i] = color.channel[2];
	fractol->image->data_addr[++i] = color.channel[1];
	fractol->image->data_addr[++i] = color.channel[0];
}

static void		draw_fractal_part(t_fractol *fractol)
{
	int			y;
	int			x;
	t_color		color;

	y = fractol->start_line;
	while (y < fractol->finish_line)
	{
		fractol->c.im = fractol->max.im - y * fractol->factor.im;
		x = 0;
		while (x < WIDTH)
		{
			fractol->c.re = fractol->min.re + x * fractol->factor.re;
			color = get_color(fractol->formula(fractol), fractol);
			put_pixel(fractol, x, y, color);
			x++;
		}
		y++;
	}
}

void			change_color_shift(t_fractol *fractol)
{
	fractol->color_shift = (fractol->color_shift + 1) % 3;
	draw_fractol(fractol);
}

t_color			get_color(int iteration, t_fractol *fractol)
{
	t_color		color;
	double		t;

	t = (double)iteration / fractol->max_iteration;
	color.channel[0] = 0;
	color.channel[(0 + fractol->color_shift) % 3 + 1] =
		(int8_t)(9 * (1 - t) * pow(t, 3) * 255);
	color.channel[(1 + fractol->color_shift) % 3 + 1] =
		(int8_t)(15 * pow((1 - t), 2) * pow(t, 2) * 255);
	color.channel[(2 + fractol->color_shift) % 3 + 1] =
		(int8_t)(8.5 * pow((1 - t), 3) * t * 255);
	return (color);
}

void			draw_fractol(t_fractol *fractol)
{
	pthread_t	threads[THREADS];
	t_fractol	fractols[THREADS];
	int			i;

	fractol->factor = init_complex(
		(fractol->max.re - fractol->min.re) / (WIDTH - 1),
		(fractol->max.im - fractol->min.im) / (HEIGHT - 1));
	i = 0;
	while (i < THREADS)
	{
		fractols[i] = *fractol;
		fractols[i].start_line = i * (HEIGHT / THREADS);
		fractols[i].finish_line = (i + 1) * (HEIGHT / THREADS);
		if (pthread_create(&threads[i], NULL,
			(void *(*)(void *))draw_fractal_part, (void *)&fractols[i]))
			terminate("Error: thread does not works... ");
		i++;
	}
	while (i-- > 0)
		if (pthread_join(threads[i], NULL))
			terminate("Error: Thread does not works...");
	mlx_put_image_to_window(fractol->mlx, fractol->window,
		fractol->image->image, 0, 0);
}
