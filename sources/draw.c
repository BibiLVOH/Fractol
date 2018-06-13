/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvigne <bvigne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 19:20:24 by bvigne            #+#    #+#             */
/*   Updated: 2018/03/19 14:50:52 by bvigne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

t_env	*ft_add_pix(t_env *env, int x, int y, t_rgb color)
{
	long	j;

	j = 0;
	if (x + env->dpl.deca_x >= 0 && y + env->dpl.deca_y >= 0 && x + \
	env->dpl.deca_x < WIDTH && y + env->dpl.deca_y < LENGTH)
	{
		j = (WIDTH * (y + env->dpl.deca_y) + (x + env->dpl.deca_x)) * 4;
		env->image[j] = color.b;
		env->image[j + 1] = color.g;
		env->image[j + 2] = color.r;
	}
	return (env);
}

t_env	*ft_clear_image(t_env *env)
{
	long	i;

	i = 0;
	while (i < (WIDTH * LENGTH * 4))
	{
		env->image[i] = 0;
		i++;
	}
	return (env);
}
