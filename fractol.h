#ifndef FRACTOL_H
# define FRACTOL_H
# include <math.h>
# include "mlx.h"
# include "libft/libft.h"
# include "ft_printf/src/ft_printf.h"
# include "get_next_line.h"
# define SCR_W 1600
# define SCR_H 1200

typedef struct 		s_fract
{
	void			*mlx;
	void			*win;
	void  			*img;
	char			*pxl;
	int				color;
	int 			max_iter;

	double			c_re; 
	double			c_im;
	double			new_re;
	double			new_im;
	double			old_re;
	double			old_im;
	double			zoom;
	double			move_x;
	double			move_y;

	int				x;
	int				y;
	int				i;
}					t_fract;

int 				mandelbrot_set(t_fract *fr);
int					julia_set(t_fract *fr);
int 				ft_mouse_hook(void);
int					my_key_funct(int keycode, void *param);

#endif
