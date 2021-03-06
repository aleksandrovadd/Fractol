/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot_set.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daleksan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 19:39:41 by daleksan          #+#    #+#             */
/*   Updated: 2017/11/09 18:07:59 by daleksan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int				pxlput_mandel(t_fract *fr)
{
	long int	i;

	i = fr->y * SCR_W * 4 + fr->x * 4;
	fr->pxl[i + 1] = fr->i * 4 % 255 * fr->color;
	return (0);
}

void			print_mandel_pixel(t_fract *fr)
{
	fr->i = 0;
	while (fr->i < fr->max_iter)
	{
		fr->old_re = fr->new_re + fr->x_move / 3;
		fr->old_im = fr->new_im + fr->y_move * 3;
		fr->new_re = fr->old_re * fr->old_re - fr->old_im * fr->old_im
		+ fr->c_re;
		fr->new_im = 2 * fr->old_re * fr->old_im + fr->c_im;
		if ((fr->new_re * fr->new_re + fr->new_im * fr->new_im) > 4)
			break ;
		fr->i++;
	}
	if (fr->i < fr->max_iter)
		pxl_put(fr);
}

void			mandelbrot_set(t_fract *fr)
{
	fr->y = 0;
	while (fr->y < SCR_H)
	{
		fr->x = 0;
		while (fr->x < SCR_W)
		{
			fr->c_re = 1.5 * (fr->x - SCR_W / 2) / (0.5 * fr->zoom * SCR_W)
			+ fr->move_x;
			fr->c_im = (fr->y - SCR_H / 2) / (0.5 * fr->zoom * SCR_H)
			+ fr->move_y;
			fr->new_re = 0;
			fr->new_im = 0;
			fr->old_re = 0;
			fr->old_im = 0;
			print_mandel_pixel(fr);
			fr->x++;
		}
		fr->y++;
	}
}
