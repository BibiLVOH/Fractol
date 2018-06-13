/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_charjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvigne <bvigne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 18:25:17 by bvigne            #+#    #+#             */
/*   Updated: 2017/12/12 18:29:42 by bvigne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_charjoin(char const *s1, char c)
{
	char	*res;

	res = NULL;
	if (s1 && c)
	{
		if (!(res = ft_strnew(ft_strlen((char *)s1) + 1)))
			return (NULL);
		ft_strcpy(res, (char *)s1);
		res[ft_strlen((char *)s1) + 1] = c;
	}
	return (res);
}
