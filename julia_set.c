#include "fractol.h"

int	pxl_put_ju(t_fract *fr)
{
	long int i;

	i = fr->y * 1600 * 4 + fr->x * 4;
	fr->pxl[i + 1] = fr->i % 255;
	return (0);
}

void		initiate_julia(t_fract *fr)
{
	int		bpp;
	int		line;
	int		ed;

	fr->win = mlx_new_window(fr->mlx, SCR_W, SCR_H, "Julia Set");
	fr->pxl = mlx_get_data_addr(fr->img, &bpp, &line, &ed);
	fr->c_re = -0.7;
	fr->c_im = 0.27015;
}

void	print_pixel(t_fract *fr)
{
	fr->i = 0;
	while (fr->i < fr->max_iter)
	{
		fr->old_re = fr->new_re;
		fr->old_im = fr->new_im;
		fr->new_re = fr->old_re * fr->old_re - fr->old_im * fr->old_im + fr->c_re;
		fr->new_im = 2 * fr->old_re * fr->old_im + fr->c_im;
		if((fr->new_re * fr->new_re + fr->new_im * fr->new_im) > 4) 
			break;
		fr->i++;
	}
	if (fr->i < fr->max_iter)
		pxl_put_ju(fr);
}

int			julia_set(t_fract *fr)
{
	initiate_julia(fr);
	fr->y = 0;
	while (fr->y < SCR_H)
	{
		fr->x = 0;
		while (fr->x < SCR_W)
		{
			fr->new_re = 1.5 * (fr->x - SCR_W / 2) / (0.5 * fr->zoom * SCR_W) + fr->move_x;
			fr->new_im = (fr->y - SCR_H / 2) / (0.5 * fr->zoom * SCR_H) + fr->move_y;
			print_pixel(fr);
			fr->x++;
		}
		fr->y++;
	}
	mlx_put_image_to_window(fr->mlx, fr->win, fr->img, 0, 0);
	mlx_key_hook(fr->win, my_key_funct, 0);
	mlx_hook(fr->win, 17, 0L, ft_mouse_hook, 0);
	mlx_loop(fr->mlx);
	return (0);
}