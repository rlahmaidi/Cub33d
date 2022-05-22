/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_5.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouali <ybouali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 01:15:34 by ybouali           #+#    #+#             */
/*   Updated: 2022/05/13 01:24:43 by ybouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	help_check_lines_between_1(t_cub3d *cub3d_info, int i, int j)
{
	if ((j - 1) > 0 && cub3d_info->info_of_map[i][j - 1] != '1')
		return (error_expact_1());
	else
	{
		while (cub3d_info->info_of_map[i][j] != '\0' && \
			cub3d_info->info_of_map[i][j] == ' '
		)
			j++;
		if (cub3d_info->info_of_map[i][j] != '\0' && \
			cub3d_info->info_of_map[i][j] != '1')
			return (error_expact_1());
	}
	return (j);
}

int	true(t_cub3d *cub3d, int i, int j)
{
	while (j > 0 && cub3d->info_of_map[i][j] == ' ')
		j--;
	if (j == 0)
		return (1);
	return (0);
}

int	help_check_lines_between_2(t_cub3d *cub3d_info, int i, int j)
{
	if (true(cub3d_info, i, j) && cub3d_info->info_of_map[i][j] != '1')
		return (error_expact_1());
	while (check_in("10NSWE", cub3d_info->info_of_map[i][j]))
		j++;
	if (
		cub3d_info->info_of_map[i][j] == '\0' && \
		cub3d_info->info_of_map[i][j - 1] != '1'
	)
		return (error_expact_1());
	else if (
		cub3d_info->info_of_map[i][j] != '\0' && \
		cub3d_info->info_of_map[i][j] != '1' && \
		cub3d_info->info_of_map[i][j] != ' '
	)
		return (error_expact_1());
	return (j);
}

int	help_check_lines_between(t_cub3d *cub3d_info, int i)
{
	int	j;
	int	r;

	j = 0;
	while (cub3d_info->info_of_map[i][j] != '\0')
	{
		if (cub3d_info->info_of_map[i][j] == ' ')
		{
			r = help_check_lines_between_1(cub3d_info, i, j);
			if (r == -1)
				return (-1);
			j = r;
		}
		else if (check_in("10NSWE", cub3d_info->info_of_map[i][j]))
		{
			r = help_check_lines_between_2(cub3d_info, i, j);
			if (r == -1)
				return (-1);
			j = r;
		}
		else
			return (error_expact_1());
	}
	return (0);
}

int	check_lines_between(t_cub3d *cub3d_info, int n)
{
	int	i;

	i = 0;
	while (++i < (n - 1))
	{
		if (help_check_lines_between(cub3d_info, i) == -1)
			return (1);
		if (check_space_is_not_closed(cub3d_info, n))
			return (error_expact_1());
	}
	return (0);
}
