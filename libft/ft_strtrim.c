/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouali <ybouali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 06:59:30 by ybouali           #+#    #+#             */
/*   Updated: 2021/11/13 17:33:02 by ybouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_in(char c, char const *set)
{
	int		i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static int	ft_lenofstr(const char *src, const char *set)
{
	int		index;
	int		len;

	len = 0;
	index = 0;
	while (src[index] && ft_is_in(src[index], set))
		index++;
	while (src[index])
	{
		len++;
		index++;
	}
	if (len == 0)
		return (-1);
	while (ft_is_in(src[index - 1], set) && src[index - 1])
	{
		len--;
		index--;
	}
	return (len);
}

static void	ft_stock_trim(char const *str, const char *set, char *ret, int len)
{
	int		index_1;
	int		index_2;

	index_1 = 0;
	index_2 = 0;
	while (str[index_1] && ft_is_in(str[index_1], set))
		index_1++;
	while (index_2 < len)
	{
		ret[index_2] = str[index_1];
		index_1++;
		index_2++;
	}
	ret[index_2] = '\0';
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		len;
	char	*ret;

	if (s1 == NULL || set == NULL)
		return (NULL);
	ret = (void *)0;
	len = ft_lenofstr(s1, set);
	if (len <= -1)
	{
		ret = (char *)ft_calloc(1, sizeof(char));
		if (!ret)
			return (NULL);
		*ret = '\0';
		return (ret);
	}
	ret = (char *)ft_calloc((len + 1), sizeof(char));
	if (!ret)
		return (NULL);
	ft_stock_trim(s1, set, ret, len);
	return (ret);
}
