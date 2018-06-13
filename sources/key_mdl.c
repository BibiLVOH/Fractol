/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_mdl.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvigne <bvigne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 19:16:34 by bvigne            #+#    #+#             */
/*   Updated: 2018/03/19 16:35:34 by bvigne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

static t_env	*ft_color_iterate(t_env *env, int key)
{
	if (key == MINUS)
		env->mdl.ite_max -= 2;
	if (key == PLUS)
		env->mdl.ite_max += 2;
	if (key == TAB && env->id_color < 7)
		env->id_color++;
	else if (key == TAB && env->id_color == 7)
		env->id_color = 1;
	env = ft_clear_image(env);
	return (env);
}

static t_env	*ft_horizontal(t_env *env, int key)
{
	double		tmp;

	tmp = env->mdl.x1;
	if (key == LEFT_KEY)
	{
		tmp = env->mdl.x1;
		env->mdl.x1 -= (env->mdl.x2 - env->mdl.x1) * 0.1;
		env->mdl.x2 -= (env->mdl.x2 - tmp) * 0.1;
	}
	else if (key == RIGHT_KEY)
	{
		tmp = env->mdl.x1;
		env->mdl.x1 += (env->mdl.x2 - env->mdl.x1) * 0.1;
		env->mdl.x2 += (env->mdl.x2 - tmp) * 0.1;
	}
	env = ft_clear_image(env);
	return (env);
}

static t_env	*ft_vertical(t_env *env, int key)
{
	double		tmp;

	tmp = env->mdl.y1;
	if (key == DOWN_KEY)
	{
		env->mdl.y1 += (env->mdl.y2 - env->mdl.y1) * 0.1;
		env->mdl.y2 += (env->mdl.y2 - tmp) * 0.1;
	}
	else if (key == UP_KEY)
	{
		env->mdl.y1 -= (env->mdl.y2 - env->mdl.y1) * 0.1;
		env->mdl.y2 -= (env->mdl.y2 - tmp) * 0.1;
	}
	env = ft_clear_image(env);
	return (env);
}

int				ft_key_mdl(int key, t_env *env)
{
	if (key == ESC)
	{
		ft_free_all(env);
		exit(0);
	}
	if (key == MDL)
		env = ft_init_mdl(env);
	if (key == JUL)
		env = ft_init_jul(env);
	if (key == TRI)
		env = ft_init_tri(env);
	if (key == RES)
		env = ft_init_mdl(env);
	if (key == RIGHT_KEY || key == LEFT_KEY)
		env = ft_horizontal(env, key);
	if (key == UP_KEY || key == DOWN_KEY)
		env = ft_vertical(env, key);
	if (key == MINUS || key == PLUS || key == TAB)
		env = ft_color_iterate(env, key);
	env = ft_reload_mdl(env);
	mlx_put_image_to_window(env->mlx_ptr, env->win_ptr, env->img_ptr, 0, 0);
	ft_add_menu(env, 0);
	return (0);
}
