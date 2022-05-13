/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouali <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 19:30:56 by ybouali           #+#    #+#             */
/*   Updated: 2021/11/14 19:58:45 by ybouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	index_d;
	size_t	dst_len;
	size_t	index_s;

	index_s = ft_strlen(src);
	if (dstsize == 0)
		return (index_s);
	index_d = ft_strlen(dst);
	dst_len = index_d;
	if (dstsize < index_d)
		return (dstsize + ft_strlen(src));
	index_s = 0;
	while (src[index_s] && (index_d + 1) < dstsize)
	{
		dst[index_d] = src[index_s];
		index_s++;
		index_d++;
	}	
	dst[index_d] = '\0';
	return (ft_strlen(src) + dst_len);
}
