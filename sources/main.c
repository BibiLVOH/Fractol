/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvigne <bvigne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 17:44:15 by bvigne            #+#    #+#             */
/*   Updated: 2018/03/19 17:19:29 by bvigne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void			proper_exit(char *s)
{
	ft_putendl_fd(s, 2);
	exit(0);
}

static void		ft_menu_sup(t_env *env)
{
	if (env->jul.cr < 0)
		mlx_string_put(env->mlx_ptr, env->win_ptr, 140, 670, 16777215, "-");
	mlx_string_put(env->mlx_ptr, env->win_ptr, 150, 670, 16777215, \
	ft_itoa((int)env->jul.cr));
	mlx_string_put(env->mlx_ptr, env->win_ptr, 160, 670, 16777215, ".");
	mlx_string_put(env->mlx_ptr, env->win_ptr, 170, 670, 16777215, \
	ft_itoa(ft_abs((int)((int)(env->jul.cr * 1000) % 1000))));
	if (env->jul.ci < 0)
		mlx_string_put(env->mlx_ptr, env->win_ptr, 190, 690, 16777215, "-");
	mlx_string_put(env->mlx_ptr, env->win_ptr, 200, 690, 16777215, \
	ft_itoa((int)env->jul.ci));
	mlx_string_put(env->mlx_ptr, env->win_ptr, 210, 690, 16777215, ".");
	mlx_string_put(env->mlx_ptr, env->win_ptr, 220, 690, 16777215, \
	ft_itoa(ft_abs((int)((int)(env->jul.ci * 1000) % 1000))));
}

void			ft_add_menu(t_env *env, int jul)
{
	mlx_string_put(env->mlx_ptr, env->win_ptr, 10, 10, 16777215, "KEY CONTROL");
	mlx_string_put(env->mlx_ptr, env->win_ptr, 10, 40, 16777215, \
	"Mouse wheel -> ZOOM");
	mlx_string_put(env->mlx_ptr, env->win_ptr, 10, 60, 16777215, \
	"Arrows      -> TRANSLATION");
	mlx_string_put(env->mlx_ptr, env->win_ptr, 10, 80, 16777215, \
	"Tabulation  -> COLOR CHANGE");
	mlx_string_put(env->mlx_ptr, env->win_ptr, 10, 100, 16777215, \
	"- / +       -> MODIFIE ITERATION");
	mlx_string_put(env->mlx_ptr, env->win_ptr, 10, 120, 16777215, \
	"ESC         -> ESCAPE");
	if (jul)
	{
		mlx_string_put(env->mlx_ptr, env->win_ptr, 10, 670, 16777215, \
		"Real Const = ");
		mlx_string_put(env->mlx_ptr, env->win_ptr, 10, 690, 16777215, \
		"Imaginary Const = ");
		if (env->jul.lock == 1)
			mlx_string_put(env->mlx_ptr, env->win_ptr, 10, 650, 16777215, \
			"SHIFT -> LOCK MOTION");
		else
			mlx_string_put(env->mlx_ptr, env->win_ptr, 10, 650, 16777215, \
			"SHIFT -> UNLOCK MOTION");
		ft_menu_sup(env);
	}
}

void			ft_select_fractol(t_env *env, int type)
{
	env->id_color = 1;
	if (type == 1)
		ft_loop_mdl(env);
	else if (type == 2)
		ft_loop_jul(env);
	else
		ft_loop_tri(env);
}

int				main(int ac, char **av)
{
	t_env			*env;
	int				bpp;
	int				s_l;
	int				endian;

	if (ac != 2 || (ft_atoi(av[1]) != 1 && ft_atoi(av[1]) != 2 &&
	ft_atoi(av[1]) != 3) || ft_strlen(av[1]) != 1)
		proper_exit(USAGE);
	if (!(env = (t_env*)ft_memalloc(sizeof(t_env))))
		return (0);
	env->mlx_ptr = mlx_init();
	env->win_ptr = mlx_new_window(env->mlx_ptr, WIDTH, LENGTH, \
	"Generateur de fond d'ecran");
	env->img_ptr = mlx_new_image(env->mlx_ptr, WIDTH, LENGTH);
	env->image = mlx_get_data_addr(env->img_ptr, &bpp, &s_l, &endian);
	ft_select_fractol(env, ft_atoi(av[1]));
	return (0);
}
