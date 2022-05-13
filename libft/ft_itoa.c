/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouali <ybouali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 16:31:01 by ybouali           #+#    #+#             */
/*   Updated: 2021/11/11 14:02:13 by ybouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_len_of_n(int n)
{
	int	index;

	index = 0;
	while (n)
	{
		index++;
		n /= 10;
	}
	return (index);
}

void	ft_stock_itoa(int n, int len, char *src)
{
	int	sign;

	sign = 0;
	if (n < 0)
	{
		src[0] = '-';
		sign = 1;
	}
	while (sign < len--)
	{
		if (n > 0)
			src[len] = (n % 10) + 48;
		else
			src[len] = ((n % 10) * -1) + 48;
		n /= 10;
	}
}

char	*ft_itoa(int n)
{
	char	*src;
	int		len;
	int		index;

	index = 0;
	if (n == 0)
	{
		src = (char *)ft_calloc(2, sizeof(char));
		if (!src)
			return ((void *)0);
		src[0] = 48;
		src[1] = '\0';
		return (src);
	}
	len = ft_len_of_n(n);
	if (n < 0)
		len += 1;
	src = (char *)malloc(sizeof(char) * len + 1);
	if (!src)
		return ((void *)0);
	src[len] = '\0';
	ft_stock_itoa(n, len, src);
	return (src);
}
