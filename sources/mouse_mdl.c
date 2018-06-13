/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_mdl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvigne <bvigne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 14:43:23 by bvigne            #+#    #+#             */
/*   Updated: 2018/03/19 15:52:25 by bvigne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

static t_env	*ft_zoom_in(t_env *env, double ratx, double raty)
{
	double		tmp;
	static int	i = 0;

	tmp = 0;
	tmp = env->mdl.x1;
	env->mdl.x1 = env->mdl.x1 + (env->mdl.x2 - env->mdl.x1) * ratx / 10;
	env->mdl.x2 = env->mdl.x2 - (env->mdl.x2 - tmp) * (1 - ratx) / 10;
	tmp = env->mdl.y1;
	env->mdl.y1 = env->mdl.y1 + (env->mdl.y2 - env->mdl.y1) * raty / 10;
	env->mdl.y2 = env->mdl.y2 - (env->mdl.y2 - tmp) * (1 - raty) / 10;
	i % 3 == 0 ? env->mdl.ite_max++ : 0;
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
	tmp = env->mdl.x1;
	env->mdl.x1 = env->mdl.x1 - (env->mdl.x2 - env->mdl.x1) * (1 - ratx) / 10;
	env->mdl.x2 = env->mdl.x2 + (env->mdl.x2 - tmp) * ratx / 10;
	tmp = env->mdl.y1;
	env->mdl.y1 = env->mdl.y1 - (env->mdl.y2 - env->mdl.y1) * (1 - raty) / 10;
	env->mdl.y2 = env->mdl.y2 + (env->mdl.y2 - tmp) * raty / 10;
	i % 3 == 0 ? env->mdl.ite_max-- : 0;
	i += 1;
	env = ft_clear_image(env);
	return (env);
}

int				ft_mouse_mdl(int button, int x, int y, t_env *env)
{
	double	ratx;
	double	raty;

	ratx = (double)x / (double)WIDTH;
	raty = (double)y / (double)LENGTH;
	if (button == ZOOM_IN)
		env = ft_zoom_in(env, ratx, raty);
	if (button == ZOOM_OUT)
		env = ft_zoom_out(env, ratx, raty);
	env = ft_reload_mdl(env);
	mlx_put_image_to_window(env->mlx_ptr, env->win_ptr, env->img_ptr, 0, 0);
	ft_add_menu(env, 0);
	return (0);
}
