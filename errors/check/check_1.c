/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouali <ybouali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 20:59:59 by ybouali           #+#    #+#             */
/*   Updated: 2022/05/13 01:20:06 by ybouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	check_first_line(t_cub3d *cub3d)
{
	int	i;

	i = 0;
	while (cub3d->info_of_map[0][i])
	{
		if (cub3d->info_of_map[0][i] == ' ')
		{
			while (cub3d->info_of_map[0][i] == ' ')
				i++;
			if (cub3d->info_of_map[0][i] == '\0')
				break ;
			if (cub3d->info_of_map[0][i] != '1')
				return (error_space(0));
		}
		else if (cub3d->info_of_map[0][i] != '1')
			return (error_space(0));
		i++;
	}
	return (0);
}

int	check_last_line(t_cub3d *cub3d, int len)
{
	int	i;

	i = 0;
	while (cub3d->info_of_map[len - 1][i])
	{
		if (cub3d->info_of_map[len - 1][i] == ' ')
		{
			while (cub3d->info_of_map[len - 1][i] == ' ')
				i++;
			if (cub3d->info_of_map[len - 1][i] == '\0')
				break ;
			if (cub3d->info_of_map[len - 1][i] != '1')
				return (error_space(1));
		}
		else if (cub3d->info_of_map[len - 1][i] != '1')
			return (error_space(1));
		i++;
	}
	return (0);
}

int	check_in(char *str, char c)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (str[i] == c)
			return (1);
	}
	return (0);
}

int	help_check_space(t_cub3d *cub3d, int n, int j, int i)
{
	while (i < n)
	{
		if ((i + 1) < n)
		{
			if (
				cub3d->info_of_map[i][j] == '\0' || \
				cub3d->info_of_map[i + 1][j] == '\0' || \
				(int)ft_strlen(cub3d->info_of_map[i + 1]) < j
			)
				break ;
			else if (
				cub3d->info_of_map[i + 1][j] != ' ' && \
				cub3d->info_of_map[i + 1][j] != '1'
			)
				return (1);
			else if (cub3d->info_of_map[i + 1][j] == '1')
				return (0);
			else if (cub3d->info_of_map[i + 1][j] == ' ')
				i++;
		}
		else
			break ;
	}
	return (0);
}

int	check_space(t_cub3d *cub3d_info, int i, int j, int n)
{
	int	i_tmp;

	i_tmp = i;
	while (i_tmp > 0)
	{
		if (
			cub3d_info->info_of_map[i_tmp - 1][j] == '\0' || \
			(int)ft_strlen(cub3d_info->info_of_map[i_tmp - 1]) < j
		)
			break ;
		if (
			(i_tmp - 1) > 0 && cub3d_info->info_of_map[i_tmp - 1][j] != ' ' && \
			cub3d_info->info_of_map[i_tmp - 1][j] != '1'
		)
			return (1);
		else if (cub3d_info->info_of_map[i_tmp - 1][j] == '1')
			break ;
		i_tmp--;
	}
	if (help_check_space(cub3d_info, n, j, i))
		return (1);
	return (0);
}
