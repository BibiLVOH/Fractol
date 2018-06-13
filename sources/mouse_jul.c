/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_jul.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvigne <bvigne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 14:43:23 by bvigne            #+#    #+#             */
/*   Updated: 2018/03/19 17:21:36 by bvigne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

static t_env	*ft_zoom_in(t_env *env, double ratx, double raty)
{
	double		tmp;
	static int	i = 0;

	tmp = 0;
	tmp = env->jul.x1;
	env->jul.x1 = env->jul.x1 + (env->jul.x2 - env->jul.x1) * ratx / 10;
	env->jul.x2 = env->jul.x2 - (env->jul.x2 - tmp) * (1 - ratx) / 10;
	tmp = env->jul.y1;
	env->jul.y1 = env->jul.y1 + (env->jul.y2 - env->jul.y1) * raty / 10;
	env->jul.y2 = env->jul.y2 - (env->jul.y2 - tmp) * (1 - raty) / 10;
	i % 3 == 0 ? env->jul.ite_max++ : 0;
	i += 1;
	env = ft_clear_image(env);
	return (env);
}

static t_env	*ft_zoom_out(t_env *env, double ratx, double raty)
{
	double		tmp;
	static int	i;

	i = 0;
	tmp = 0;
	tmp = env->jul.x1;
	env->jul.x1 = env->jul.x1 - (env->jul.x2 - env->jul.x1) * (1 - ratx) / 10;
	env->jul.x2 = env->jul.x2 + (env->jul.x2 - tmp) * ratx / 10;
	tmp = env->jul.y1;
	env->jul.y1 = env->jul.y1 - (env->jul.y2 - env->jul.y1) * (1 - raty) / 10;
	env->jul.y2 = env->jul.y2 + (env->jul.y2 - tmp) * raty / 10;
	i % 3 == 0 ? env->jul.ite_max-- : 0;
	i += 1;
	env = ft_clear_image(env);
	return (env);
}

int				ft_mouse_jul(int button, int x, int y, t_env *env)
{
	double	ratx;
	double	raty;

	ratx = (double)x / (double)WIDTH;
	raty = (double)y / (double)LENGTH;
	if (button == ZOOM_IN)
		env = ft_zoom_in(env, ratx, raty);
	if (button == ZOOM_OUT)
		env = ft_zoom_out(env, ratx, raty);
	env = ft_reload_jul(env);
	mlx_put_image_to_window(env->mlx_ptr, env->win_ptr, env->img_ptr, 0, 0);
	ft_add_menu(env, 0);
	return (0);
}

int				ft_motion_mouse(int x, int y, t_env *env)
{
	if (env->jul.lock == 1 && x < WIDTH / 2 && y < LENGTH / 2)
	{
		env->jul.cr -= 0.001;
		env->jul.ci -= 0.001;
	}
	else if (env->jul.lock == 1 && x > WIDTH / 2 && y < LENGTH / 2)
	{
		env->jul.cr += 0.001;
		env->jul.ci -= 0.001;
	}
	else if (env->jul.lock == 1 && x < WIDTH / 2 && y > LENGTH / 2)
	{
		env->jul.cr -= 0.001;
		env->jul.ci += 0.001;
	}
	else if (env->jul.lock == 1 && x > WIDTH / 2 && y > LENGTH / 2)
	{
		env->jul.cr += 0.001;
		env->jul.ci += 0.001;
	}
	env = ft_clear_image(env);
	env = ft_reload_jul(env);
	mlx_put_image_to_window(env->mlx_ptr, env->win_ptr, env->img_ptr, 0, 0);
	ft_add_menu(env, 1);
	return (0);
}
