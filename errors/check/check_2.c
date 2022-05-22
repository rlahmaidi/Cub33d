/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouali <ybouali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 23:21:05 by ybouali           #+#    #+#             */
/*   Updated: 2022/05/13 01:23:07 by ybouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	check_number_of_player(char **table)
{
	int	i;
	int	j;
	int	count;

	i = -1;
	count = 0;
	while (table[++i] != 0)
	{
		j = -1;
		while (table[i][++j] != '\0')
		{
			if (check_in("NEWS", table[i][j]))
				count++;
		}
	}
	if (count != 1)
		return (error_number_of_player());
	return (0);
}

int	check_zero(t_cub3d *cub3d_info, int i, int j, int n)
{
	int	i_tmp;

	i_tmp = i;
	while (i_tmp > 0 && cub3d_info->info_of_map[i_tmp][j] != '1')
		i_tmp--;
	if (i_tmp == 0 && cub3d_info->info_of_map[i_tmp][j] != '1')
		return (1);
	i_tmp = i;
	while (i_tmp < n && cub3d_info->info_of_map[i_tmp][j] != '1')
		i_tmp++;
	if (i_tmp == n && cub3d_info->info_of_map[i_tmp][j] != '1')
		return (1);
	return (0);
}

int	check_space_is_not_closed(t_cub3d *cub3d_info, int n)
{
	int	i;
	int	j;

	i = -1;
	while (cub3d_info->info_of_map[++i] != 0)
	{
		j = 0;
		while (cub3d_info->info_of_map[i][j++])
		{
			if (cub3d_info->info_of_map[i][j] == ' ')
				if (check_space(cub3d_info, i, j, n))
					return (1);
			if (cub3d_info->info_of_map[i][j] == '0')
				if (check_zero(cub3d_info, i, j, n))
					return (1);
		}
	}
	return (0);
}
