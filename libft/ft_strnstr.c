/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouali <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 15:51:15 by ybouali           #+#    #+#             */
/*   Updated: 2021/11/13 14:21:28 by ybouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *src, const char *to_find, size_t len)
{
	size_t	index_s;
	size_t	len_to_find;
	size_t	index_t;

	len_to_find = ft_strlen(to_find);
	if (len_to_find == 0)
		return ((char *)src);
	if (len == 0)
		return ((void *)0);
	index_s = 0;
	while (src[index_s])
	{
		index_t = 0;
		while (src[index_s + index_t] == to_find[index_t])
		{
			index_t++;
			if ((index_t + index_s) > len)
				return (0);
			if (to_find[index_t] == '\0')
				return ((char *)(src + index_s));
		}
		index_s++;
	}
	return (0);
}
