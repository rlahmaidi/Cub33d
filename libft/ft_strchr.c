/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouali <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 21:03:06 by ybouali           #+#    #+#             */
/*   Updated: 2021/11/13 14:25:57 by ybouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	int		index;

	index = 0;
	while (s[index] != (char)c && s[index])
		index++;
	if (s[index] == (char)c)
		return ((char *)s + index);
	return (0);
}
