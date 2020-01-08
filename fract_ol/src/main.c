/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hryu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 19:37:52 by hryu              #+#    #+#             */
/*   Updated: 2019/11/15 03:24:39 by hryu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static int			(*get_formula(char *name)) (t_fractol *fractol)
{
	size_t				i;
	int					(*formula)(t_fractol *fractol);
	static t_formula	formulas[] = {
		{ "Mandelbrot", &iterate_mandelbrot },
		{ "Julia", &iterate_julia },
		{ "Tricorn", &iterate_tricorn }
	};

	i = 0;
	formula = NULL;
	while (i < (sizeof(formulas) / sizeof(t_formula)))
	{
		if (ft_strequ(name, formulas[i].name))
			formula = formulas[i].formula;
		i++;
	}
	return (formula);
}

t_fractol			*init_fractol(char *name, void *mlx)
{
	t_fractol			*fractol;

	if (!(fractol = (t_fractol *)ft_memalloc(sizeof(t_fractol))))
		terminate("ERROR: Failed to initialize fractol");
	fractol->mlx = mlx;
	if (!(fractol->window = mlx_new_window(mlx, WIDTH, HEIGHT, name)))
		terminate("ERROR: Failed to initialize window");
	fractol->image = init_image(mlx);
	set_defaults(fractol);
	fractol->is_julia_fixed = true;
	if (!(fractol->formula = get_formula(name)))
		terminate("ERROR: Fractol name not found");
	mlx_hook(fractol->window, 2, 0, key_press, fractol);
	mlx_hook(fractol->window, 17, 0, close, fractol);
	mlx_hook(fractol->window, 4, 0, zoom, fractol);
	if (ft_strequ(name, "Julia"))
		mlx_hook(fractol->window, 6, 0, julia_motion, fractol);
	return (fractol);
}

void				start(int number, char **names)
{
	t_fractol			*fractols[8];
	void				*mlx;
	int					i;

	i = 0;
	mlx = mlx_init();
	while (i < number)
	{
		fractols[i] = init_fractol(names[i], mlx);
		draw_fractol(fractols[i]);
		i++;
	}
	mlx_loop(mlx);
}

void				print_help(void)
{
	ft_putendl("Usage: ./fractol [names]");
	ft_putendl("  Mandelbrot");
	ft_putendl("  Julia");
	ft_putendl("  Tricorn");
}

int					main(int argc, char **argv)
{
	int					i;

	if (argc >= 2)
	{
		i = 1;
		while (i < argc)
		{
			if (!get_formula(argv[i]))
				break ;
			i++;
		}
		if (i == argc)
			start(argc - 1, &argv[1]);
	}
	print_help();
	return (0);
}
