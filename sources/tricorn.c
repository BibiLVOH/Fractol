/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tricorn.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvigne <bvigne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 19:16:16 by bvigne            #+#    #+#             */
/*   Updated: 2018/03/19 18:13:06 by bvigne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

static t_env	*ft_iterate(t_env *env, int *i)
{
	double	tmp;

	tmp = 0;
	tmp = env->tri.z_r;
	env->tri.z_r = env->tri.z_r * env->tri.z_r - env->tri.z_i * \
	env->tri.z_i + env->tri.c_r;
	env->tri.z_i = -2 * env->tri.z_i * tmp + env->tri.c_i;
	(*i)++;
	return (env);
}

static t_env	*ft_set_tri(t_env *env)
{
	env->dpl.zoom = WIDTH / (env->tri.x2 - env->tri.x1);
	env->tri.img_x = (env->tri.x2 - env->tri.x1) * env->dpl.zoom;
	env->tri.img_y = (env->tri.y2 - env->tri.y1) * env->dpl.zoom;
	env->dpl.deca_x = (WIDTH / 2) - (env->tri.img_x / 2);
	env->dpl.deca_y = (LENGTH / 2) - (env->tri.img_y / 2);
	return (env);
}

t_env			*ft_reload_tri(t_env *env)
{
	double	x;
	double	y;
	int		i;

	x = 0;
	env = ft_set_tri(env);
	while (x++ < env->tri.img_x)
	{
		y = 0;
		while (y++ < env->tri.img_y)
		{
			env->tri.c_r = x / env->dpl.zoom + env->tri.x1;
			env->tri.c_i = y / env->dpl.zoom + env->tri.y1;
			env->tri.z_r = 0;
			env->tri.z_i = 0;
			i = 0;
			while (i < env->tri.ite_max && env->tri.z_r * env->tri.z_r + \
			env->tri.z_i * env->tri.z_i <= 4)
				env = ft_iterate(env, &i);
			if (i != env->tri.ite_max)
				ft_add_pix(env, x, y, ft_get_rgb(env, i, env->tri.ite_max));
		}
	}
	return (env);
}

int				ft_loop_tri(t_env *env)
{
	env = ft_init_tri(env);
	mlx_put_image_to_window(env->mlx_ptr, env->win_ptr, env->img_ptr, 0, 0);
	ft_add_menu(env, 0);
	mlx_hook(env->win_ptr, 2, 3, ft_key_tri, env);
	mlx_mouse_hook(env->win_ptr, ft_mouse_tri, env);
	mlx_loop(env->mlx_ptr);
	return (0);
}
