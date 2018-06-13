/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvigne <bvigne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 19:15:51 by bvigne            #+#    #+#             */
/*   Updated: 2018/03/19 18:13:17 by bvigne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

static t_env	*ft_iterate(t_env *env, int *i)
{
	double	tmp;

	tmp = 0;
	tmp = env->mdl.z_r;
	env->mdl.z_r = env->mdl.z_r * env->mdl.z_r - env->mdl.z_i * \
	env->mdl.z_i + env->mdl.c_r;
	env->mdl.z_i = 2 * env->mdl.z_i * tmp + env->mdl.c_i;
	(*i)++;
	return (env);
}

static t_env	*ft_set_mdl(t_env *env)
{
	env->dpl.zoom = WIDTH / (env->mdl.x2 - env->mdl.x1);
	env->mdl.img_x = (env->mdl.x2 - env->mdl.x1) * env->dpl.zoom;
	env->mdl.img_y = (env->mdl.y2 - env->mdl.y1) * env->dpl.zoom;
	env->dpl.deca_x = (WIDTH / 2) - (env->mdl.img_x / 2);
	env->dpl.deca_y = (LENGTH / 2) - (env->mdl.img_y / 2);
	return (env);
}

t_env			*ft_reload_mdl(t_env *env)
{
	double	x;
	double	y;
	int		i;

	x = 0;
	env = ft_set_mdl(env);
	while (x++ < env->mdl.img_x)
	{
		y = 0;
		while (y++ < env->mdl.img_y)
		{
			env->mdl.c_r = x / env->dpl.zoom + env->mdl.x1;
			env->mdl.c_i = y / env->dpl.zoom + env->mdl.y1;
			env->mdl.z_r = 0;
			env->mdl.z_i = 0;
			i = 0;
			while (i < env->mdl.ite_max && env->mdl.z_r * env->mdl.z_r + \
			env->mdl.z_i * env->mdl.z_i <= 4)
				env = ft_iterate(env, &i);
			if (i != env->mdl.ite_max)
				ft_add_pix(env, x, y, ft_get_rgb(env, i, env->mdl.ite_max));
		}
	}
	return (env);
}

int				ft_loop_mdl(t_env *env)
{
	env = ft_init_mdl(env);
	mlx_put_image_to_window(env->mlx_ptr, env->win_ptr, env->img_ptr, 0, 0);
	ft_add_menu(env, 0);
	mlx_hook(env->win_ptr, 2, 3, ft_key_mdl, env);
	mlx_mouse_hook(env->win_ptr, ft_mouse_mdl, env);
	mlx_loop(env->mlx_ptr);
	return (0);
}
