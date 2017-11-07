#include "fractol.h"

int	pxl_put_man(t_fract *fr)
{
	long int i;

	if (fr->psycho == 1)
	{
		i = fr->y * 1600 * 4 + fr->x * 4;
		fr->pxl[i] = fr->i * fr->b * fr->color;				//blue
		fr->pxl[i + 1] = fr->i * fr->g * fr->color;			//green
		fr->pxl[i + 2] = fr->i * fr->r * fr->color;			//red
	}
	else
	{
		i = fr->y * 1600 * 4 + fr->x * 4;
		fr->pxl[i] = fr->i % fr->b * fr->color;				//blue
		fr->pxl[i + 1] = fr->i % fr->g * fr->color;			//green
		fr->pxl[i + 2] = fr->i % fr->r * fr->color;			//red
	}
	return (0);
}

void	print_mandel_pixel(t_fract *fr)
{
	fr->i = 0;
	while (fr->i < fr->max_iter)
	{
		fr->old_re = fr->new_re;
		fr->old_im = fr->new_im;
		fr->new_re = fr->old_re * fr->old_re - fr->old_im * fr->old_im + fr->c_re + fr->x_move;
		fr->new_im = 2 * fr->old_re * fr->old_im + fr->c_im + fr->y_move;
		if ((fr->new_re * fr->new_re + fr->new_im * fr->new_im) > 4) 
			break;
		fr->i++;
	}
	if (fr->i < fr->max_iter)
		pxl_put_man(fr);
}

void	 mandelbrot_set(t_fract *fr)
{
	fr->y = 0;
	while (fr->y < SCR_H)
	{
		fr->x = 0;
		while (fr->x < SCR_W)
		{
			fr->c_re = 1.5 * (fr->x - SCR_W / 2) / (0.5 * fr->zoom * SCR_W) + fr->move_x;
			fr->c_im = (fr->y - SCR_H / 2) / (0.5 * fr->zoom * SCR_H) + fr->move_y;
			fr->new_re = fr->new_im = fr->old_re = fr->old_im = 0;
			print_mandel_pixel(fr);
			fr->x++;
		}
		fr->y++;
	}
}
