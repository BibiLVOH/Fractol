/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvigne <bvigne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 19:16:05 by bvigne            #+#    #+#             */
/*   Updated: 2018/03/19 18:12:58 by bvigne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

static t_env	*ft_iterate(t_env *env, int *i)
{
	double	tmp;

	tmp = 0;
	tmp = env->jul.re;
	env->jul.re = env->jul.re * env->jul.re - env->jul.im * \
	env->jul.im + env->jul.cr;
	env->jul.im = 2 * env->jul.im * tmp + env->jul.ci;
	(*i)++;
	return (env);
}

static t_env	*ft_set_mdl(t_env *env)
{
	env->dpl.zoom = WIDTH / (env->jul.x2 - env->jul.x1);
	env->jul.img_x = (env->jul.x2 - env->jul.x1) * env->dpl.zoom;
	env->jul.img_y = (env->jul.y2 - env->jul.y1) * env->dpl.zoom;
	env->dpl.deca_x = (WIDTH / 2) - (env->jul.img_x / 2);
	env->dpl.deca_y = (LENGTH / 2) - (env->jul.img_y / 2);
	return (env);
}

t_env			*ft_reload_jul(t_env *env)
{
	double	x;
	double	y;
	int		i;

	y = 0;
	env = ft_set_mdl(env);
	while (y++ < env->jul.img_y)
	{
		x = 0;
		while (x++ < env->jul.img_x)
		{
			env->jul.re = x / env->dpl.zoom + env->jul.x1;
			env->jul.im = y / env->dpl.zoom + env->jul.y1;
			i = 0;
			while (i < env->jul.ite_max && env->jul.re * env->jul.re + \
			env->jul.im * env->jul.im <= 4)
				env = ft_iterate(env, &i);
			if (i != env->jul.ite_max)
				ft_add_pix(env, x, y, ft_get_rgb(env, i, env->jul.ite_max));
		}
	}
	return (env);
}

int				ft_loop_jul(t_env *env)
{
	env = ft_init_jul(env);
	mlx_put_image_to_window(env->mlx_ptr, env->win_ptr, env->img_ptr, 0, 0);
	ft_add_menu(env, 1);
	mlx_hook(env->win_ptr, 6, 0, ft_motion_mouse, env);
	mlx_hook(env->win_ptr, 2, 3, ft_key_jul, env);
	mlx_mouse_hook(env->win_ptr, ft_mouse_jul, env);
	mlx_loop(env->mlx_ptr);
	return (0);
}
