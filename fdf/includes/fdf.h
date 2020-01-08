/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hryu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 14:07:59 by hryu              #+#    #+#             */
/*   Updated: 2019/09/03 23:41:38 by hryu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/includes/libft.h"
# include "../libft/includes/get_next_line.h"
# include <math.h>
# include <stdlib.h>
# include "../minilibx_macos/mlx.h"
# include <fcntl.h>

/*
** void perror(const char *s);
** void strerror(int errnum);
*/

# include <stdio.h>
# include <string.h>

/*
** size of window
*/

# define WIDTH 1000
# define HEIGHT 1000

/*
** color for integer (mlx_pixel_put color value)
*/

# define RED 65536
# define GREEN 256
# define BLUE 1

typedef	struct		s_img
{
	int				*data;
	int				bpp;
	int				size_line;
	int				endian;
}					t_img;

typedef struct		s_prt
{
	int				x_to_print;
	int				y_to_print;
	int				x_start;
	int				y_start;
	int				x_end;
	int				y_end;
	int				x_orig;
	int				y_orig;
}					t_prt;

typedef struct		s_fdf
{
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;
	t_img			image;
	t_prt			print;
	int				map_width;
	int				map_height;
	int				**map_alti;
	int				zoom;

	int				move_x;
	int				move_y;
	int				move_top;
	int				color_red;
	int				color_green;
	int				color_blue;
	int				isometric;
	double			angle_x;
	double			angle_y;
}					t_fdf;

/*
** error handler and leaks management.
*/

void				ft_perror(char *s);

/*
** setup all t_fdf values.
*/

void				setup_values_fdf(t_fdf *fdf, char *file);
int					setup_map_width(char *line);
void				setup_map_height(t_fdf *fdf, char *file);
void				setup_map_alti(t_fdf *fdf, char *file, int i, int j);
void				setup_key_fdf(t_fdf *fdf);

/*
** setup image
*/

int					setup_image(t_fdf *fdf);
void				set_end_point(t_fdf *fdf, int x, int y, int check);
void				setup_line(t_fdf *fdf, int x, int y, int check);
void				draw_image(t_fdf *fdf);
void				draw_line(t_fdf *fdf, double x, double y);

#endif
