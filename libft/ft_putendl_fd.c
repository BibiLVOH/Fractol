/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvigne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 16:55:06 by bvigne            #+#    #+#             */
/*   Updated: 2017/11/10 16:55:07 by bvigne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char const *s, int fd)
{
	int		i;
	char	*str;

	i = 0;
	if (s)
	{
		str = (char *)s;
		while (str[i])
		{
			ft_putchar_fd(str[i], fd);
			i++;
		}
		ft_putchar_fd('\n', fd);
	}
}
