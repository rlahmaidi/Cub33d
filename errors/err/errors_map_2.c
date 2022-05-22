/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_map_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouali <ybouali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 00:42:49 by ybouali           #+#    #+#             */
/*   Updated: 2022/05/13 00:56:51 by ybouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	error_syntax_no(void)
{
	printf ("Error\n");
	printf ("Please add the path of north texture\n");
	return (1);
}

int	error_syntax_so(void)
{
	printf ("Error\n");
	printf ("Please add the path of south texture\n");
	return (1);
}

int	error_syntax_we(void)
{
	printf ("Error\n");
	printf ("Please add the path of west texture\n");
	return (1);
}

int	error_syntax_ea(void)
{
	printf ("Error\n");
	printf ("Please add the path of east texture\n");
	return (1);
}

int	error_syntax_f(void)
{
	printf ("Error\n");
	printf ("Please add the F and his color\n");
	return (1);
}
