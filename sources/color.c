/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvigne <bvigne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 21:42:53 by bvigne            #+#    #+#             */
/*   Updated: 2018/03/17 17:38:40 by bvigne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

t_rgb		ft_get_rgb(t_env *env, int i, double ite_max)
{
	t_rgb	clr;

	clr.r = (i / ite_max) * 255;
	clr.g = (i / ite_max) * 255;
	clr.b = (i / ite_max) * 255;
	if (env->id_color == 2 && clr.g < 195)
		clr.g += 60;
	else if (env->id_color == 3 && clr.g < 195 && i % 2 == 0)
		clr.g += 60;
	else if (env->id_color == 4 && clr.b < 195)
		clr.b += 60;
	else if (env->id_color == 5 && clr.b < 195 && i % 2 == 0)
		clr.b += 60;
	else if (env->id_color == 6 && clr.r < 195)
		clr.r += 60;
	else if (env->id_color == 7 && clr.r < 195 && i % 2 == 0)
		clr.r += 60;
	return (clr);
}
