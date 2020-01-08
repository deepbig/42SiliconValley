/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hryu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 00:59:12 by hryu              #+#    #+#             */
/*   Updated: 2019/11/15 03:03:34 by hryu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

t_image		*init_image(void *mlx)
{
	t_image		*image;

	if (!(image = (t_image *)ft_memalloc(sizeof(t_image))))
		terminate("Error: image initializing failed.");
	if (!(image->image = mlx_new_image(mlx, WIDTH, HEIGHT)))
		terminate("Error: image initializing failed.");
	image->data_addr = mlx_get_data_addr(
		image->image,
		&(image->bits_per_pixel),
		&(image->size_line),
		&(image->endian));
	return (image);
}

t_complex	init_complex(double re, double im)
{
	t_complex	complex;

	complex.re = re;
	complex.im = im;
	return (complex);
}

void		set_defaults(t_fractol *fractol)
{
	fractol->max_iteration = 50;
	fractol->min = init_complex(-2.0, -2.0);
	fractol->max.re = 2.0;
	fractol->max.im = fractol->min.im
		+ (fractol->max.re - fractol->min.re) * HEIGHT / WIDTH;
	fractol->k = init_complex(-0.4, 0.6);
	fractol->color_shift = 2;
}
