/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   second.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daleksan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 19:42:56 by daleksan          #+#    #+#             */
/*   Updated: 2017/11/09 18:34:47 by daleksan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	usage(void)
{
	ft_printf("You can use to transform all Fractals:\n");
	ft_printf("\033[35;1mMouse wheel\033[0m to zoom in / zoom out\n");
	ft_printf("\033[35;1mMouse left button\033[0m");
	ft_printf(" to start / cancel changing map\n");
	ft_printf("\033[35;1m+\033[0m or \033[35;1m-\033[0m");
	ft_printf(" to change number of iterations\n");
	ft_printf("\033[35;1m1\033[0m / \033[35;1m2\033[0m / \033[35;1m3\033[0m");
	ft_printf(" on the right to plus colors\n");
	ft_printf("\033[35;1m4\033[0m / \033[35;1m5\033[0m / \033[35;1m6\033[0m");
	ft_printf(" on the right to minus colors\n");
	ft_printf("\033[35;1ms\033[0m to change mode to 'psycho'\n");
	ft_printf("\033[35;1mSpace\033[0m to make fractol one beautiful color\n");
	ft_printf("\033[35;1mArrows\033[0m to move the image\n");
	ft_printf("\033[35;1m0\033[0m on the right to cancel ");
	ft_printf("\033[4mall\033[0m changes\n\n");
	ft_printf("\033[36;1mHave fun! :)\033[0m\n");
}

int		check_parametr(char *str)
{
	if ((ft_strcmp(str, "1") != 0) && (ft_strcmp(str, "2") != 0) &&
		(ft_strcmp(str, "3") != 0))
		menu(0);
	return (0);
}

void	redraw(t_fract *fr)
{
	fr->img = mlx_new_image(fr->mlx, SCR_W, SCR_H);
	fr->pxl = mlx_get_data_addr(fr->img, &fr->bpp, &fr->line, &fr->ed);
	(fr->num == 1) ? julia_set(fr) : 0;
	(fr->num == 2) ? mandelbrot_set(fr) : 0;
	(fr->num == 3) ? burningship_set(fr) : 0;
	mlx_put_image_to_window(fr->mlx, fr->win, fr->img, 0, 0);
	mlx_destroy_image(fr->mlx, fr->img);
	mlx_loop(fr->mlx);
}

int		pxl_put(t_fract *fr)
{
	long int i;

	if (fr->psycho == 1)
	{
		i = fr->y * SCR_W * 4 + fr->x * 4;
		fr->pxl[i] = fr->i * fr->b * fr->color;
		fr->pxl[i + 1] = fr->i * fr->g * fr->color;
		fr->pxl[i + 2] = fr->i * fr->r * fr->color;
	}
	else if (fr->nice == 1 && fr->num == 1)
		pxlput_jul(fr);
	else if (fr->nice == 1 && fr->num == 3)
		pxlput_burn(fr);
	else if (fr->nice == 1 && fr->num == 2)
		pxlput_mandel(fr);
	else
	{
		i = fr->y * SCR_W * 4 + fr->x * 4;
		fr->pxl[i] = fr->i * 4 % fr->b * fr->color;
		fr->pxl[i + 1] = fr->i * 4 % fr->g * fr->color;
		fr->pxl[i + 2] = fr->i * 4 % fr->r * fr->color;
	}
	return (0);
}
