/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouali <ybouali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 17:58:39 by ybouali           #+#    #+#             */
/*   Updated: 2021/11/13 17:32:02 by ybouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_stock_join(char const *str_1, char const *str_2, char *str_new)
{
	int		index_1;
	int		index_2;

	index_1 = 0;
	while (str_1[index_1])
	{
		str_new[index_1] = str_1[index_1];
		index_1++;
	}
	index_2 = 0;
	while (str_2[index_2])
	{
		str_new[index_1] = str_2[index_2];
		index_1++;
		index_2++;
	}
	str_new[index_1] = '\0';
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		len_s1;
	int		len_s2;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	str = (void *)0;
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	str = (char *)ft_calloc((len_s1 + len_s2 + 1), sizeof(char));
	if (!str)
		return (NULL);
	ft_stock_join(s1, s2, str);
	return (str);
}
