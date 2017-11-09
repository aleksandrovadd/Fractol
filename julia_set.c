/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_set.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daleksan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 19:37:47 by daleksan          #+#    #+#             */
/*   Updated: 2017/11/09 18:07:05 by daleksan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int				pxlput_jul(t_fract *fr)
{
	long int	i;

	i = fr->y * SCR_W * 4 + fr->x * 4;
	fr->pxl[i] = fr->i * 4 % 255 * fr->color;
	fr->pxl[i + 2] = fr->i * 4 % 10 * fr->color;
	fr->max_iter = 220;
	return (0);
}

void			print_pixel(t_fract *fr)
{
	fr->i = 0;
	while (fr->i < fr->max_iter)
	{
		fr->old_re = fr->new_re;
		fr->old_im = fr->new_im;
		fr->new_re = fr->old_re * fr->old_re - fr->old_im * fr->old_im
		+ fr->c_re + fr->x_move;
		fr->new_im = 2 * fr->old_re * fr->old_im + fr->c_im + fr->y_move;
		if ((fr->new_re * fr->new_re + fr->new_im * fr->new_im) > 4)
			break ;
		fr->i++;
	}
	if (fr->i < fr->max_iter)
		pxl_put(fr);
}

void			julia_set(t_fract *fr)
{
	fr->c_re = -0.7;
	fr->c_im = 0.27015;
	fr->y = 0;
	while (fr->y < SCR_H)
	{
		fr->x = 0;
		while (fr->x < SCR_W)
		{
			fr->new_re = 1.5 * (fr->x - SCR_W / 2) / (0.5 * fr->zoom * SCR_W)
			+ fr->move_x;
			fr->new_im = (fr->y - SCR_H / 2) / (0.5 * fr->zoom * SCR_H)
			+ fr->move_y;
			print_pixel(fr);
			fr->x++;
		}
		fr->y++;
	}
}
