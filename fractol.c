#include "fractol.h"

int		my_key_funct(int keycode, void *param)
{

	if (keycode == 53)
		exit((int)param);
	return (0);
}

int 	ft_mouse_hook(void)
{
	exit(77);
}

int		menu(int i)			//get next line?
{
	ft_printf("Menu:\n");
	ft_printf("1 - Julia Set\n");
	ft_printf("2 - Mandelbrot Set\n");
	ft_printf("3 - something Set\n");
	ft_printf("Usage: ./fractol [set number]\n");
	exit(i);
}

void	choose_set(char *str, t_fract *fr)
{
	if (ft_strcmp(str, "1") == 0)
		julia_set(fr);
	else if (ft_strcmp(str, "2") == 0)
		mandelbrot_set(fr);
	else if (ft_strcmp(str, "3") == 0)
		ft_printf("Something third :)\n");
	else
		menu(0); 
}

void	init_fr(t_fract *fr)
{
	fr->mlx = mlx_init();
	fr->img = mlx_new_image(fr->mlx, SCR_W, SCR_H);
	fr->color = 0;
	fr->max_iter = 300;
	fr->zoom = 1;
	fr->move_x = 0;
	fr->move_y = 0;
}

int 	main(int ac, char **av)
{
	t_fract *fr;

	if (ac < 2 || ac > 2)
		menu(0);
	fr = (t_fract *)malloc(sizeof(t_fract));
	init_fr(fr);
	choose_set(av[1], fr);
	return 0;
}