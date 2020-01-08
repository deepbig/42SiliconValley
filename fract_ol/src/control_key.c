/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_key.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hryu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 00:09:54 by hryu              #+#    #+#             */
/*   Updated: 2019/11/15 02:41:56 by hryu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		move(int key, t_fractol *fractol)
{
	t_complex	delta;

	delta = init_complex(IS_ABS(fractol->max.re - fractol->min.re),
			IS_ABS(fractol->max.im - fractol->min.im));
	if (key == ARROW_LEFT)
	{
		fractol->min.re -= delta.re * 0.05;
		fractol->max.re -= delta.re * 0.05;
	}
	else if (key == ARROW_RIGHT)
	{
		fractol->min.re += delta.re * 0.05;
		fractol->max.re += delta.re * 0.05;
	}
	else if (key == ARROW_UP)
	{
		fractol->min.im += delta.im * 0.05;
		fractol->max.im += delta.im * 0.05;
	}
	else if (key == ARROW_DOWN)
	{
		fractol->min.im -= delta.im * 0.05;
		fractol->max.im -= delta.im * 0.05;
	}
	draw_fractol(fractol);
}

static void		change_max_iteration(int key, t_fractol *fractol)
{
	if (key == NUM_PAD_PLUS)
		fractol->max_iteration = (int)(fractol->max_iteration * 1.05);
	if (key == NUM_PAD_MINUS)
		fractol->max_iteration = (int)(fractol->max_iteration * 0.95);
	draw_fractol(fractol);
}

int				ft_close(void *param)
{
	(void)param;
	exit(0);
}

void			terminate(char *s)
{
	ft_putendl_fd(s, 2);
	exit(0);
}

int				key_press(int key, t_fractol *fractol)
{
	if (key == MAIN_PAD_ESC)
		exit(0);
	else if (key == MAIN_PAD_R)
	{
		set_defaults(fractol);
		draw_fractol(fractol);
	}
	else if (key == NUM_PAD_MINUS || key == NUM_PAD_PLUS)
		change_max_iteration(key, fractol);
	else if (key == ARROW_LEFT || key == ARROW_RIGHT
				|| key == ARROW_UP || key == ARROW_DOWN)
		move(key, fractol);
	else if (key == MAIN_PAD_SPACE)
		fractol->is_julia_fixed = !fractol->is_julia_fixed;
	else if (key == MAIN_PAD_C)
		change_color_shift(fractol);
	return (0);
}
