/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvigne <bvigne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 13:02:37 by bvigne            #+#    #+#             */
/*   Updated: 2018/03/19 14:50:54 by bvigne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	ft_free_all(t_env *env)
{
	ft_strdel(&env->image);
	free(env->mlx_ptr);
	free(env->win_ptr);
	free(env->img_ptr);
	free(env);
	env = NULL;
}
