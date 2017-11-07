#ifndef FRACTOL_H
# define FRACTOL_H
# include <math.h>
# include "mlx.h"
# include "libft/libft.h"
# include "ft_printf/src/ft_printf.h"
# include "get_next_line.h"
# define SCR_W 1600
# define SCR_H 1200
# define UP_KEY 126		//up
# define R_KEY 124		//right
# define D_KEY 125		//down
# define L_KEY 123		//left
# define ZOOM_IN 4
# define ZOOM_OUT 5

typedef struct 		s_fract
{
	void			*mlx;
	void			*win;
	void  			*img;
	char			*pxl;
	int				color;
	int 			max_iter;
	int				num;
	int				psycho;

	double			c_re; 
	double			c_im;
	double			new_re;
	double			new_im;
	double			old_re;
	double			old_im;
	double			zoom;
	double			move_x;
	double			move_y;
	double			pause;
	double			x_move;
	double			y_move;

	int				x;
	int				y;
	int				i;

	int				r;
	int				g;
	int				b;

	int				bpp;
	int				line;
	int				ed;
	int				move;
}					t_fract;

void				mandelbrot_set(t_fract *fr);
void				julia_set(t_fract *fr);
int 				ft_mouse_hook(void);
int 				key_hook(int key, t_fract *fr);
int					change_col(t_fract *fr);
int					init_col(t_fract *fr);
int 				mouse_movement(int x, int y, t_fract *fr);
int					mouse_funct(int button, int x, int y, t_fract *fr);
void	            redraw(t_fract *fr);
int 				mouse_movement(int x, int y, t_fract *fr);

#endif
