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

int main()
{
    t_fract *fr;
    
    int y = 0;
    int x;
    int i;
    int color;
    int maxIterations = 300;
    fr = (t_fract *)malloc(sizeof(t_fract));
    fr->mlx = mlx_init();
	  fr->win = mlx_new_window(fr->mlx, SCR_W, SCR_H, "Julia Set");
    fr->image = mlx_new_image(fr->mlx, 1000, 600);
    fr->num[0] = -0.7;      //0  double cRe; 
    fr->num[1] = 0.27015;   //1  double cIm;
    fr->num[6] = 1;
    fr->num[7] = 0;
    fr->num[8] = 0;

    while (y < SCR_H)
    {
      x = 0;
      while (x < SCR_W)
      {
        fr->num[2] = 1.5 * (x - w / 2) / (0.5 * fr->num[6] * w) + fr->num[7];
        fr->num[3] = (y - h / 2) / (0.5 * fr->num[6] * h) + fr->num[8];
        i = 0;
        while (i < maxIterations)
        {
          fr->num[4] = fr->num[2];
          fr->num[5] = fr->num[3];
          fr->num[2] = fr->num[4] * fr->num[4] - fr->num[5] * fr->num[5] + fr->num[0];
          fr->num[3] = 2 * fr->num[4] * fr->num[5] + fr->num[1];
          if((fr->num[2] * fr->num[2] + fr->num[3] * fr->num[3]) > 4) 
            break;
          i++;
        }
        color = mlx_get_color_value(fr->mlx, (i % 255));
        mlx_pixel_put(fr->mlx, fr->win, x, y, color);
        x++;
      }
      y++;
    }
	mlx_key_hook(fr->win, my_key_funct, 0);
	mlx_hook(fr->win, 17, 0L, ft_mouse_hook, 0);
	mlx_loop(fr->mlx);
  return 0;
}