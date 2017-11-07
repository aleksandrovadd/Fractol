#include "fractol.h"

void            redraw(t_fract *fr)
{
    fr->img = mlx_new_image(fr->mlx, SCR_W, SCR_H);
    fr->pxl = mlx_get_data_addr(fr->img, &fr->bpp, &fr->line, &fr->ed);
    (fr->num == 1) ? julia_set(fr) : 0;
    (fr->num == 2) ? mandelbrot_set(fr) : 0;
    // (fr->num == 3) ? put_burning_ship(fr) : 0;
    mlx_put_image_to_window(fr->mlx, fr->win, fr->img, 0, 0);
    mlx_destroy_image(fr->mlx, fr->img);
    mlx_loop(fr->mlx);
}