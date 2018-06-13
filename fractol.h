/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvigne <bvigne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 16:21:11 by bvigne            #+#    #+#             */
/*   Updated: 2018/03/19 16:35:01 by bvigne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <math.h>
# include "libft/libft.h"
# include <mlx.h>

# define WIDTH 1280
# define LENGTH 720
# define MDL 18
# define JUL 19
# define TRI 20
# define USAGE "usage: ./fractol #type\n1 -> Mandelbrot\n2 -> Julia\n3 -> XXX"
# define ZOOM_OUT 4
# define ZOOM_IN 5
# define MINUS 27
# define PLUS 24
# define TAB 48
# define LOCK 257
# define UP_KEY 126
# define DOWN_KEY 125
# define RIGHT_KEY 124
# define LEFT_KEY 123
# define RES 49
# define ESC 53

typedef struct		s_trd
{
	int				yi;
	int				yf;
}					t_trd;

typedef struct		s_dpl
{
	int				deca_x;
	int				deca_y;
	int				zoom;
}					t_dpl;

typedef struct		s_rgb
{
	int				r;
	int				g;
	int				b;
}					t_rgb;

typedef struct		s_mdl
{
	t_trd			trd;
	double			x1;
	double			x2;
	double			y1;
	double			y2;
	double			img_x;
	double			img_y;
	double			c_r;
	double			c_i;
	double			z_r;
	double			z_i;
	double			ite_max;
}					t_mdl;

typedef struct		s_jul
{
	t_trd			trd;
	double			x1;
	double			x2;
	double			y1;
	double			y2;
	double			img_x;
	double			img_y;
	double			cr;
	double			ci;
	double			re;
	double			im;
	double			ite_max;
	int				lock;
}					t_jul;

typedef struct		s_tri
{
	t_trd			trd;
	double			x1;
	double			x2;
	double			y1;
	double			y2;
	double			img_x;
	double			img_y;
	double			c_r;
	double			c_i;
	double			z_r;
	double			z_i;
	double			ite_max;
}					t_tri;

typedef struct		s_env
{
	t_mdl			mdl;
	t_jul			jul;
	t_tri			tri;
	t_dpl			dpl;
	int				id_color;
	char			*image;
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;
}					t_env;

void				proper_exit(char *s);
void				ft_add_menu(t_env *env, int lock);

t_env				*ft_init_mdl(t_env *env);
t_env				*ft_init_jul(t_env *env);
t_env				*ft_init_tri(t_env *env);

int					ft_key_mdl(int key, t_env *env);
int					ft_key_jul(int key, t_env *env);
int					ft_key_tri(int key, t_env *env);

int					ft_mouse_mdl(int key, int x, int y, t_env *env);
int					ft_mouse_jul(int key, int x, int y, t_env *env);
int					ft_mouse_tri(int key, int x, int y, t_env *env);
int					ft_motion_mouse(int x, int y, t_env *env);

t_env				*ft_thread_mdl(t_env *env);
t_env				*ft_thread_jul(t_env *env);
t_env				*ft_thread_tri(t_env *env);

int					ft_loop_mdl(t_env *env);
t_env				*ft_reload_mdl(t_env *env);

int					ft_loop_jul(t_env *env);
t_env				*ft_reload_jul(t_env *env);

int					ft_loop_tri(t_env *env);
t_env				*ft_reload_tri(t_env *env);

t_rgb				ft_get_rgb(t_env *env, int i, double ite_max);

t_env				*ft_add_pix(t_env *env, int x, int y, t_rgb color);
t_env				*ft_clear_image(t_env *env);

void				ft_free_all(t_env *env);

#endif
