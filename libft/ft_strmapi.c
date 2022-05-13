/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouali <ybouali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 19:19:25 by ybouali           #+#    #+#             */
/*   Updated: 2021/11/13 16:25:02 by ybouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	len;
	char			*src;

	if (s == NULL || f == NULL)
		return (NULL);
	len = ft_strlen(s);
	src = (char *)ft_calloc((len + 1), sizeof(char));
	if (!src)
		return (NULL);
	len = 0;
	while (s[len])
	{
		src[len] = f(len, s[len]);
		len++;
	}
	src[len] = '\0';
	return (src);
}
