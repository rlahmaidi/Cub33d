/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouali <ybouali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 15:50:21 by ybouali           #+#    #+#             */
/*   Updated: 2021/11/08 18:11:18 by ybouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*buff;
	int		len;

	buff = (void *)0;
	len = ft_strlen(s1);
	buff = (char *)ft_calloc(len + 1, sizeof(char));
	if (!buff)
		return (buff);
	ft_strlcpy(buff, s1, len + 1);
	return (buff);
}
