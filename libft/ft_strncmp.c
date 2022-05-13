/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouali <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 21:25:08 by ybouali           #+#    #+#             */
/*   Updated: 2021/11/13 14:24:21 by ybouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			index;
	unsigned char	*a;
	unsigned char	*b;

	a = (unsigned char *)s1;
	b = (unsigned char *)s2;
	index = 0;
	while (index < n && a[index] && b[index])
	{
		if (a[index] == b[index])
			index++;
		else
			return (a[index] - b[index]);
	}
	if (index == n)
		return (0);
	return (a[index] - b[index]);
}
