/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hryu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 13:19:34 by hryu              #+#    #+#             */
/*   Updated: 2019/11/15 03:24:21 by hryu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int				iterate_mandelbrot(t_fractol *fractol)
{
	int			iteration;
	t_complex	z;

	iteration = 0;
	z = init_complex(fractol->c.re, fractol->c.im);
	while (pow(z.re, 2.0) + pow(z.im, 2.0) <= 4
		&& iteration < fractol->max_iteration)
	{
		z = init_complex(
			pow(z.re, 2.0) - pow(z.im, 2.0) + fractol->c.re,
			2.0 * z.re * z.im + fractol->c.im);
		iteration++;
	}
	return (iteration);
}

int				iterate_julia(t_fractol *fractol)
{
	int			iteration;
	t_complex	z;

	iteration = 24;
	z = init_complex(fractol->c.re, fractol->c.im);
	while (pow(z.re, 2.0) + pow(z.im, 2.0) <= 4
		&& iteration < fractol->max_iteration)
	{
		z = init_complex(
			pow(z.re, 2.0) - pow(z.im, 2.0) + fractol->k.re,
			2.0 * z.re * z.im + fractol->k.im);
		iteration++;
	}
	return (iteration);
}

int				julia_motion(int x, int y, t_fractol *fractol)
{
	if (!fractol->is_julia_fixed)
	{
		fractol->k = init_complex(
			4 * ((double)x / WIDTH - 0.5),
			4 * ((double)(HEIGHT - y) / HEIGHT - 0.5));
		draw_fractol(fractol);
	}
	return (0);
}

int				iterate_tricorn(t_fractol *fractol)
{
	int			iteration;
	t_complex	z;

	iteration = 0;
	z = init_complex(fractol->c.re, fractol->c.im);
	while (pow(z.re, 2.0) + pow(z.im, 2.0) <= 4
		&& iteration < fractol->max_iteration)
	{
		z = init_complex(
			pow(z.re, 2.0) - pow(z.im, 2.0) + fractol->c.re,
			-2.0 * z.re * z.im + fractol->c.im);
		iteration++;
	}
	return (iteration);
}
