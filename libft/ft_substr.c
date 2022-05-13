/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouali <ybouali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 17:02:08 by ybouali           #+#    #+#             */
/*   Updated: 2021/11/13 17:31:11 by ybouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_stock(char *buff, char const *str, size_t start, size_t len)
{
	size_t	index;

	index = 0;
	while (str[index] && index < len)
	{
		buff[index] = str[start];
		start++;
		index++;
	}
	buff[index] = '\0';
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*buff;
	size_t	index;

	buff = (void *)0;
	if (s == NULL)
		return (NULL);
	index = ft_strlen(s);
	if (index == 0 || start >= index)
	{
		buff = (char *)ft_calloc(1, sizeof(char));
		*buff = '\0';
		return (buff);
	}
	if (index < len)
		len = index;
	buff = (char *)ft_calloc(len + 1, sizeof(char));
	if (!buff)
		return (buff);
	ft_stock(buff, s, start, len);
	return (buff);
}
