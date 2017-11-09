/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daleksan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 19:35:02 by daleksan          #+#    #+#             */
/*   Updated: 2017/11/09 18:35:15 by daleksan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include <math.h>
# include "mlx.h"
# include "libft/libft.h"
# include "ft_printf/src/ft_printf.h"
# define SCR_W 1200
# define SCR_H 800
# define UP_KEY 126
# define R_KEY 124
# define D_KEY 125
# define L_KEY 123
# define ZOOM_IN 4
# define ZOOM_OUT 5

typedef struct		s_fract
{
	void			*mlx;
	void			*win;
	void			*img;
	char			*pxl;
	int				color;
	int				max_iter;
	int				num;
	int				psycho;
	int				nice;

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
int					pxlput_mandel(t_fract *fr);
void				julia_set(t_fract *fr);
int					pxlput_jul(t_fract *fr);
int					ft_mouse_hook(void);
int					key_hook(int key, t_fract *fr);
int					change_col(t_fract *fr);
int					init_col(t_fract *fr);
int					mouse_movement(int x, int y, t_fract *fr);
int					mouse_funct(int button, int x, int y, t_fract *fr);
void				redraw(t_fract *fr);
void				burningship_set(t_fract *fr);
int					pxlput_burn(t_fract *fr);
int					pxl_put(t_fract *fr);
void				usage(void);
int					menu(int i);
int					check_parametr(char *str);

#endif
