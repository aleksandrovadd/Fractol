/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daleksan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 19:41:42 by daleksan          #+#    #+#             */
/*   Updated: 2017/11/08 19:42:36 by daleksan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		mouse_funct(int button, int x, int y, t_fract *fr)
{
	if (button == 4)
	{
		fr->zoom *= 1.1;
		fr->move_x += (x - SCR_W / 2) / (SCR_W * 2.5) / fr->zoom;
		fr->move_y += (y - SCR_H / 2) / (SCR_H * 2.5) / fr->zoom;
	}
	(button == 5) ? fr->zoom /= 1.1 : 0;
	if (button == 1 && fr->move == 0)
		fr->move = 1;
	else if (button == 1)
		fr->move = 0;
	redraw(fr);
	return (0);
}

int		mouse_movement(int x, int y, t_fract *fr)
{
	if (fr->move == 1)
	{
		fr->x_move = (x - 0) * (1.0 - (-1.0)) / (1200 - 0) + (-1);
		fr->y_move = (y - 0) * (0.2 - (-0.2)) / (800 - 0) + (-0.2);
		redraw(fr);
	}
	return (1);
}

int		ft_mouse_hook(void)
{
	exit(77);
}

int		change_col(t_fract *fr)
{
	if (fr->color == 2 && (fr->r >= 1 && fr->r < 255))
		fr->r += 10;
	if (fr->color == 5 && (fr->r > 10 && fr->r < 255))
		fr->r -= 10;
	if (fr->color == 3 && (fr->g >= 1 && fr->g < 255))
		fr->g += 10;
	if (fr->color == 6 && (fr->g > 10 && fr->g < 255))
		fr->g -= 10;
	if (fr->color == 4 && (fr->b >= 1 && fr->b < 255))
		fr->b += 10;
	if (fr->color == 7 && (fr->b > 10 && fr->b < 255))
		fr->b -= 10;
	return (0);
}

int		key_hook(int key, t_fract *fr)
{
	(key == 53) ? exit(0) : 0;
	(key == 49) ? fr->nice = 1 : 0;
	(key == 126) ? fr->move_y += 0.1 : 0;
	(key == 125) ? fr->move_y -= 0.1 : 0;
	(key == 123) ? fr->move_x += 0.1 : 0;
	(key == 124) ? fr->move_x -= 0.1 : 0;
	(key == 69) ? fr->max_iter += 5 : 0;
	(key == 78) ? fr->max_iter -= 5 : 0;
	(key == 1) ? fr->psycho = 1 : 0;
	(key == 83) ? ((fr->color = 2) && (change_col(fr))) : 0;
	(key == 84) ? ((fr->color = 3) && (change_col(fr))) : 0;
	(key == 85) ? ((fr->color = 4) && (change_col(fr))) : 0;
	(key == 86) ? ((fr->color = 5) && (change_col(fr))) : 0;
	(key == 87) ? ((fr->color = 6) && (change_col(fr))) : 0;
	(key == 88) ? ((fr->color = 7) && (change_col(fr))) : 0;
	(key == 82) ? ((fr->color = 1) && (init_col(fr))) : 0;
	(key == 82) ? fr->psycho = 0 : 0;
	redraw(fr);
	return (0);
}
