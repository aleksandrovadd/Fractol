/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daleksan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 14:50:25 by daleksan          #+#    #+#             */
/*   Updated: 2017/11/08 19:34:51 by daleksan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			init_col(t_fract *fr)
{
	fr->r = 1;
	fr->g = 61;
	fr->b = 251;
	fr->psycho = 0;
	fr->color = 1;
	fr->max_iter = 40;
	fr->zoom = 1;
	fr->move_x = 0;
	fr->move_y = 0;
	fr->pause = 0;
	fr->move = 0;
	fr->blue = 0;
	return (0);
}

int			menu(int i)
{
	ft_printf("Menu:\n");
	ft_printf("1 - Julia Set\n");
	ft_printf("2 - Mandelbrot Set\n");
	ft_printf("3 - Birningship Set\n");
	ft_printf("Usage: ./fractol [Set number]\n");
	exit(i);
}

void		choose_set(char *str, t_fract *fr)
{
	if (ft_strcmp(str, "1") == 0)
	{
		fr->num = 1;
		julia_set(fr);
	}
	else if (ft_strcmp(str, "2") == 0)
	{
		fr->num = 2;
		mandelbrot_set(fr);
	}
	else if (ft_strcmp(str, "3") == 0)
	{
		fr->num = 3;
		burningship_set(fr);
	}
	else
		menu(0);
}

int			init_fr(char *str, t_fract *fr)
{
	fr->mlx = mlx_init();
	fr->win = mlx_new_window(fr->mlx, SCR_W, SCR_H, "Fract`ol 42");
	fr->img = mlx_new_image(fr->mlx, SCR_W, SCR_H);
	fr->pxl = mlx_get_data_addr(fr->img, &fr->bpp, &fr->line, &fr->ed);
	init_col(fr);
	mlx_hook(fr->win, 2, 5, key_hook, fr);
	mlx_mouse_hook(fr->win, mouse_funct, fr);
	mlx_hook(fr->win, 17, 0L, ft_mouse_hook, 0);
	choose_set(str, fr);
	usage();
	mlx_hook(fr->win, 6, 1L << 6, mouse_movement, fr);
	mlx_put_image_to_window(fr->mlx, fr->win, fr->img, 0, 0);
	mlx_destroy_image(fr->mlx, fr->img);
	mlx_loop(fr->mlx);
	return (0);
}

int			main(int ac, char **av)
{
	t_fract	*fr;

	if (ac < 2 || ac > 2)
		menu(0);
	fr = (t_fract *)malloc(sizeof(t_fract));
	init_fr(av[1], fr);
	return (0);
}
