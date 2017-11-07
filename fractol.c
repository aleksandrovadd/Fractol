#include "fractol.h"

int			init_col(t_fract *fr)
{
	fr->r = 1;
	fr->g = 51;
	fr->b = 255;
	fr->psycho = 0;
	fr->color = 1;
	fr->max_iter = 300;
	fr->zoom = 1;
	fr->move_x = 0;
	fr->move_y = 0;
	fr->pause = 0;
	fr->move = 0;
	return (0);
}


int		menu(int i)			//get next line?
{
	ft_printf("Menu:\n");
	ft_printf("1 - Julia Set\n");
	ft_printf("2 - Mandelbrot Set\n");
	ft_printf("3 - something Set\n");
	ft_printf("Usage: ./fractol [Set number]\n");
	exit(i);
}

void	choose_set(char *str, t_fract *fr)
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
		ft_printf("Something third :)\n");
	}
	else
		menu(0); 
}

int 	init_fr(char *str, t_fract *fr)
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
	mlx_hook(fr->win, 6, 1L << 6, mouse_movement, fr);
	mlx_put_image_to_window(fr->mlx, fr->win, fr->img, 0, 0);
	mlx_destroy_image(fr->mlx, fr->img);
	mlx_loop(fr->mlx);
	return (0);

}

int 	main(int ac, char **av)
{
	t_fract *fr;

	if (ac < 2 || ac > 2)
		menu(0);
	fr = (t_fract *)malloc(sizeof(t_fract));
	init_fr(av[1], fr);
	return (0);
}