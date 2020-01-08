/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hryu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 19:38:29 by hryu              #+#    #+#             */
/*   Updated: 2019/11/15 04:03:59 by hryu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libft/includes/libft.h"
# include <math.h>
# include <stdlib.h>
# include "../minilibx_macos/mlx.h"
# include <fcntl.h>
# include <stdint.h>
# include <unistd.h>
# include <pthread.h>

# define WIDTH			1000
# define HEIGHT			1000

# define THREADS		1000000

# define MOUSE_SCROLL_UP	4
# define MOUSE_SCROLL_DOWN	5

# define ARROW_UP			126
# define ARROW_DOWN			125
# define ARROW_LEFT			123
# define ARROW_RIGHT		124

# define NUM_PAD_PLUS		69
# define NUM_PAD_MINUS		78

# define MAIN_PAD_ESC		53
# define MAIN_PAD_SPACE		49
# define MAIN_PAD_C			8
# define MAIN_PAD_H			4
# define MAIN_PAD_R			15

# define IS_ABS(X) (((X) < 0) ? (-(X)) : (X))

typedef enum
{
	false,
	true
}	t_bool;

typedef	struct		s_color
{
	int8_t			channel[4];
}					t_color;

typedef struct		s_complex
{
	double			re;
	double			im;
}					t_complex;

typedef struct		s_image
{
	void			*image;
	char			*data_addr;
	int				bits_per_pixel;
	int				size_line;
	int				endian;
}					t_image;

typedef struct		s_fractol
{
	void			*mlx;
	void			*window;
	t_image			*image;
	int				max_iteration;
	t_complex		min;
	t_complex		max;
	t_complex		factor;
	t_complex		c;
	t_complex		k;
	t_bool			is_julia_fixed;
	int				start_line;
	int				finish_line;
	int				color_shift;
	int				(*formula)(struct s_fractol *fractol);
}					t_fractol;

typedef struct		s_formula
{
	char			*name;
	int				(*formula)(t_fractol *fractol);
}					t_formula;

/*
** re — real part
** im — imaginary part
*/

/*
** Image:
** image          — image identifier
** data_addr      — image
** bits_per_pixel — depth of image
** size_line      — number of bytes used to store one line of image
** endian         — little or big endian
**
** Fract'ol
** mlx            — connection identifier
** window         — window identifier
** image          — information about image
** max_iteration  — maximum iteration
** min            — minimum real and imaginary parts of complex numbers
** max            — maximum real and imaginary parts of complex numbers
** factor         — dependency between complex numbers and pixels
** c              — complex number
** k              — constant complex number (only for Julia)
** is_julia_fixed — flag that reports Julia is fixed or is not
** start_line     — start line of fractal part (needed for multi-threading)
** finish_line    — finish line of fractal part (needed for multi-threading)
** color_shift    — shift of color channels
** formula        — fractal formula
** is_help        — flag that reports help screen is displayed or is not
**
** formula:
** name    — name of fractal
** formula — formula of fractal
**
** color:
** channel — alpha, red, green, blue color channels
*/

/*
** Init
*/
t_image				*init_image(void *mlx);
t_complex			init_complex(double re, double im);
void				set_defaults(t_fractol *fractol);

/*
** Draw
*/
void				draw_fractol(t_fractol *fractol);
void				draw_help(t_fractol *fractol);

/*
** Fractals
*/
int					iterate_mandelbrot(t_fractol *fractol);
int					iterate_julia(t_fractol *fractol);
int					iterate_tricorn(t_fractol *fractol);

/*
** Color
*/
t_color				get_color(int iteration, t_fractol *fractol);
void				change_color_shift(t_fractol *fractol);
/*
** Controls
*/
int					ft_close(void *param);
int					key_press(int key, t_fractol *fractol);
int					zoom(int button, int x, int y, t_fractol *fractol);
int					julia_motion(int x, int y, t_fractol *fractol);

/*
** Print
*/
void				print_help(void);

/*
** Utils
*/
void				terminate(char *s);

#endif
