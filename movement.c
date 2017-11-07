#include "fractol.h"

int 	mouse_funct(int button, int x, int y, t_fract *fr)
{
	if (button == 4)
	{
		fr->zoom *= 1.1;
		fr->move_x += (x - SCR_W / 2) / (SCR_W * 2.5) / fr->zoom;
		fr->move_y += (y - SCR_H / 2) / (SCR_H * 2.5) / fr->zoom;
	}
	(button == 5) ? fr->zoom /= 1.1 : 0;
	redraw(fr);
	return (0);
}

int 	mouse_movement(int x, int y, t_fract *fr)
{
	if (fr->move == 1)
	{
		fr->x_move = 0.00008 * (x - (SCR_W / 2));
		fr->y_move = 0.00008 * (y - (SCR_H / 2));
		redraw(fr);
	}
	return (1);
}

int 	ft_mouse_hook(void)
{
	exit(77);
}

int		change_col(t_fract *fr)
{
	if (fr->color == 2 && (fr->r > 10 && fr->r < 245))
		fr->r += 10;
	else
		fr->r -= 10;
	if (fr->color == 3 && (fr->g > 10 && fr->g < 245))
		fr->g += 10;
	else
		fr->g -= 10;
	if (fr->color == 4 && (fr->b > 10 && fr->b < 245))
		fr->b += 10;
	else
		fr->b -= 10;
	return (0);
}

int 		key_hook(int key, t_fract *fr)
{
	printf("%d\n", key);
	(key == 53) ? exit(0) : 0;					//esc
	(key == 36) ? fr->move = 1 : 0;
	(key == 126) ? fr->move_y += 0.1 : 0;		//arrow up
	(key == 125) ? fr->move_y -= 0.1 : 0;		//arrow down
	(key == 123) ? fr->move_x += 0.1 : 0;		//arrow right
	(key == 124) ? fr->move_x -= 0.1 : 0;		//arrow left
	(key == 69) ? fr->max_iter += 10 : 0;		//+ right
	(key == 78) ? fr->max_iter -= 10 : 0;		//- right
	(key == 1) ? fr->psycho = 1 : 0;			//s main
	(key == 83) ? ((fr->color = 2) && (change_col(fr))) : 0;			//1 right
	(key == 84) ? ((fr->color = 3) && (change_col(fr))) : 0;			//2 right
	(key == 85) ? ((fr->color = 4) && (change_col(fr))) : 0;			//3 right
	(key == 82) ? ((fr->color = 1) && (init_col(fr))) : 0;			//0 right
	(key == 82) ? fr->psycho = 0 : 0;			//0 right
	// (key == 36) ? fr->move = 0 : 0;
	redraw(fr);
	return (0);
}
