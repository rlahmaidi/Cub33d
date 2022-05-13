/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouali <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 14:25:02 by ybouali           #+#    #+#             */
/*   Updated: 2021/11/13 14:22:38 by ybouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			index;
	unsigned char	*src_1;
	unsigned char	*src_2;

	src_1 = (unsigned char *)s1;
	src_2 = (unsigned char *)s2;
	index = 0;
	while (index < n)
	{
		if (src_1[index] != src_2[index])
			return (src_1[index] - src_2[index]);
		index++;
	}
	return (0);
}
