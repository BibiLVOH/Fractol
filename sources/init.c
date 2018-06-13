/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvigne <bvigne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 21:42:53 by bvigne            #+#    #+#             */
/*   Updated: 2018/03/19 18:16:07 by bvigne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

t_env		*ft_init_mdl(t_env *env)
{
	env->mdl.x1 = -3.10;
	env->mdl.x2 = 1.70;
	env->mdl.y1 = -1.35;
	env->mdl.y2 = 1.35;
	env->mdl.ite_max = 100;
	env = ft_clear_image(env);
	env = ft_reload_mdl(env);
	return (env);
}

t_env		*ft_init_jul(t_env *env)
{
	env->jul.x1 = -2.60;
	env->jul.x2 = 2.20;
	env->jul.y1 = -1.35;
	env->jul.y2 = 1.35;
	env->jul.cr = -0.7;
	env->jul.ci = 0.27015;
	env->jul.lock = 1;
	env->jul.ite_max = 100;
	env = ft_clear_image(env);
	env = ft_reload_jul(env);
	return (env);
}

t_env		*ft_init_tri(t_env *env)
{
	env->tri.x1 = -3.10;
	env->tri.x2 = 1.70;
	env->tri.y1 = -1.35;
	env->tri.y2 = 1.35;
	env->tri.ite_max = 30;
	env = ft_clear_image(env);
	env = ft_reload_tri(env);
	return (env);
}
