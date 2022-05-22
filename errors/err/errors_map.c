/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouali <ybouali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 04:19:43 by ybouali           #+#    #+#             */
/*   Updated: 2022/05/13 00:53:34 by ybouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	err_args(void)
{
	printf("Error\n");
	printf("To run the cub3d please\n");
	printf("Type ./cub3d name_of_map.cub\n");
	printf("NO MORE\n");
	return (1);
}

int	error_name(void)
{
	printf("Error\n");
	printf("The name of map shoud be .cub\n");
	return (1);
}

int	error_colors_1(void)
{
	printf("Error\n");
	printf("HI Ineed three values for one color\n");
	return (1);
}

int	error_colors_2(void)
{
	printf("Error\n");
	printf("char in colors\n");
	return (1);
}

int	error_colors_3(void)
{
	printf("Error\n");
	printf("HI the value of rgb color should be bteween 0 and 225\n");
	return (1);
}
