/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_map_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouali <ybouali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 00:46:12 by ybouali           #+#    #+#             */
/*   Updated: 2022/05/13 00:56:24 by ybouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	error_syntax_c(void)
{
	printf ("Error\n");
	printf ("Please add the C and his color\n");
	return (1);
}

int	error_syntax_map(void)
{
	printf ("Error\n");
	printf ("Hi !!! there is no map i have just the\
	 info of the map Please add the map\n");
	return (1);
}

void	error_map_lines(void)
{
	printf ("Error\n");
	printf ("Hi !!! LINE EMPTY IN MAP\n");
}

int	error_file_exist(int fd)
{
	close (fd);
	printf ("Error\n");
	printf ("Hi !!! One of textures dosent existe\n");
	return (1);
}

int	error_expact_2(int i)
{
	printf ("Error\n");
	printf ("Hi expacte a 1 character !\n");
	printf ("help\nlien number [%d] there is (space Or spacese) in \
	your map it should be start or space with 1 character\n", i + 1);
	return (1);
}
