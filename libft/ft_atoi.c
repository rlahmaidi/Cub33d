/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouali <ybouali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 19:53:36 by ybouali           #+#    #+#             */
/*   Updated: 2021/11/13 17:35:37 by ybouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_sheck_and_return_nbr(char *str, int sign)
{
	int		index;
	int		res;

	res = 0;
	index = 0;
	while (str[index] >= '0' && str[index] <= '9')
	{
		res = (res * 10) + (str[index] - 48);
		index++;
	}
	if (index > 19 && sign == -1)
		return (0);
	if (index > 19 && sign == 1)
		return (-1);
	return (res * sign);
}

int	ft_atoi(const char *str)
{
	int		index;
	int		sign;
	int		ret;

	ret = 0;
	index = 0;
	sign = 1;
	while ((str[index] >= 9 && str[index] <= 13) || str[index] == ' ')
		index++;
	if (str[index] == '-' || str[index] == '+')
	{
		if (str[index] == '-')
			sign = -1;
		index++;
	}
	ret = ft_sheck_and_return_nbr((char *)str + index, sign);
	return (ret);
}
