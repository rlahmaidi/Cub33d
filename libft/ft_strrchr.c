/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouali <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 21:16:28 by ybouali           #+#    #+#             */
/*   Updated: 2021/11/13 16:30:15 by ybouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		index;
	char	*src;

	src = (char *)s;
	index = ft_strlen(s);
	if (c == 0)
		return (src + index);
	while (index--)
	{
		if (src[index] == (unsigned char )c)
			return (&src[index]);
	}		
	return (NULL);
}
