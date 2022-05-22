/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouali <ybouali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 01:06:09 by ybouali           #+#    #+#             */
/*   Updated: 2022/05/13 01:13:36 by ybouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	check_colors(t_cub3d *cub3d)
{
	if (check_color_floor(cub3d))
		return (1);
	if (check_color_ceilling(cub3d))
		return (1);
	return (0);
}

int	check_derection_and_colors(t_cub3d *cub3d)
{
	int	fd;

	if (check_name_of_textuers(cub3d))
		return (1);
	fd = open (cub3d->no, O_RDONLY);
	if (fd < 0)
		return (error_file_exist(fd));
	close (fd);
	fd = open (cub3d->so, O_RDONLY);
	if (fd < 0)
		return (error_file_exist(fd));
	close (fd);
	fd = open (cub3d->we, O_RDONLY);
	if (fd < 0)
		return (error_file_exist(fd));
	close (fd);
	fd = open (cub3d->ea, O_RDONLY);
	if (fd < 0)
		return (error_file_exist(fd));
	close (fd);
	if (check_colors(cub3d))
		return (1);
	return (0);
}

int	check_map_errors(t_cub3d *cub3d_info)
{
	int	i;
	int	n;

	i = 0;
	n = len_table(cub3d_info->info_of_map);
	if (n < 3)
		return (error_map_1());
	if (check_first_line(cub3d_info))
		return (1);
	if (check_last_line(cub3d_info, n))
		return (1);
	if (check_lines_between(cub3d_info, n))
		return (1);
	if (check_number_of_player(cub3d_info->info_of_map))
		return (1);
	if (check_derection_and_colors(cub3d_info))
		return (1);
	return (0);
}
