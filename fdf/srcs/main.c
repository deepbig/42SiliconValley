/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hryu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 22:21:28 by hryu              #+#    #+#             */
/*   Updated: 2019/09/03 23:41:01 by hryu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** mlx_init() return (void *)new_mlx(mlx_ptr_t) which contains NULL values in:
** 		new_mlx->win_list, new_mlx->img_list, new_mlx->loop_hook,
**		new_mlx->loop_hook_data, new_mlx->main_loop_active (this is 0).
** 	new_mlx-> appid = [code for run application] and mew_mlx->font.
**
** after init...
** mlx_new_window(mlx_ptr_t (mlx_ptr, int pixel_x, int pixel_y, char *title)
** this return (void *)newwin);
** this function creates: mlx_win_list_t *newwin, and NSString *str.
** this provides basic setup for window.
**
** after window...
** mlx_loop(mlx_ptr_t *mlx_ptr). This simply ask MacOS on the one hand to
** draw what I asked MacOS to draw, to open the window, to manage the events,
** 		ex) moves the mouse, clicks or use the keyboard.
*/

int		deal_key(int keycode, t_fdf *fdf)
{
	if (keycode == 53)
		exit(0);
	else if (keycode == 15)
		setup_key_fdf(fdf);
	else if (keycode == 125)
		fdf->move_y++;
	else if (keycode == 126)
		fdf->move_y--;
	else if (keycode == 123)
		fdf->move_x--;
	else if (keycode == 124)
		fdf->move_x++;
	else if (keycode == 34)
		fdf->zoom++;
	else if (keycode == 31)
		fdf->zoom--;
	else if (keycode == 4)
		fdf->move_top++;
	else if (keycode == 37)
		fdf->move_top--;
	else if (keycode == 13)
		fdf->angle_y *= 0.5;
	else if (keycode == 2)
		fdf->angle_y *= 1.5;
	return (0);
}

void	ft_perror(char *s)
{
	ft_putendl(s);
	exit(0);
}

/*
** mlx_hook is for handle key presses.
** mlx_hook (void *win_ptr, int x_event, int x_mask, int (*funct), void *param)
** 	x_event = 2 is for key press, x_event = 3 is for key release.
**	x_mask is ignored on macOS.
*/

int		main(int argc, char **argv)
{
	t_fdf	*fdf;

	if (argc != 2)
	{
		ft_putendl("Usage: ./fdf ./maps/<select_one_file>");
		return (-1);
	}
	if (NULL == (fdf = (t_fdf *)malloc(sizeof(t_fdf))))
		return (-1);
	setup_values_fdf(fdf, argv[1]);
	fdf->mlx_ptr = mlx_init();
	fdf->win_ptr = mlx_new_window(fdf->mlx_ptr, WIDTH, HEIGHT, "mlx 42");
	mlx_hook(fdf->win_ptr, 2, 0, deal_key, fdf);
	mlx_loop_hook(fdf->mlx_ptr, setup_image, fdf);
	mlx_loop(fdf->mlx_ptr);
	return (0);
}

/*
** Before pixel_put...
** int	mlx_key_hook(void *win_ptr, int (*funct_ptr)(), void *param);
** 	identifier of window, pointer function your own that will be called
** 	by mlx_loop when user press keyboard, and last unknown for mlx which
**	simply given as param to your function.
**	the function should
**
** int	mlx_pixel_put(void *mlx_ptr, void *win_ptr, int x, int y, int color);
** 	identifier of the connection, window, and coordinates of pixel, and RGB.
*/
