/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouali <ybouali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 01:00:55 by ybouali           #+#    #+#             */
/*   Updated: 2022/05/14 22:17:51 by ybouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	check_name_of_textuer(char *name_of_map)
{
	int	len;

	len = ft_strlen(name_of_map);
	len -= 4;
	if (name_of_map[len] == '\0')
		return (error_name_tex());
	if (ft_strncmp(&name_of_map[len], ".xpm", \
	ft_strlen(&name_of_map[len])) == 0)
		return (0);
	return (error_name_tex());
}

int	check_name_of_textuers(t_cub3d *cub3d)
{
	if (check_name_of_textuer(cub3d->no))
		return (1);
	if (check_name_of_textuer(cub3d->so))
		return (1);
	if (check_name_of_textuer(cub3d->we))
		return (1);
	if (check_name_of_textuer(cub3d->ea))
		return (1);
	return (0);
}

int	check_digit_color(char **rgb)
{
	int	r;
	int	g;

	if (len_table(rgb) != 3)
		return (error_colors_1());
	r = -1;
	while (rgb[++r] != 0)
	{
		g = -1;
		while (rgb[r][++g] != '\0')
		{
			if (!ft_isdigit(rgb[r][g]))
				return (error_colors_2());
		}
	}
	return (0);
}

int	check_color_floor(t_cub3d *cub3d)
{
	int		r;
	int		g;
	int		b;
	char	**rgb;

	rgb = ft_split(cub3d->f, ',');
	if (check_digit_color(rgb))
	{
		free_table(rgb);
		return (1);
	}
	r = ft_atoi(rgb[0]);
	g = ft_atoi(rgb[1]);
	b = ft_atoi(rgb[2]);
	free_table(rgb);
	if ((r < 0 && r > 225) || (g < 0 && g > 225) || (b < 0 && b > 225))
		return (error_colors_3());
	cub3d->floor_c = encode_rgb(r, g, b);
	return (0);
}

int	check_color_ceilling(t_cub3d *cub3d)
{
	int		r;
	int		g;
	int		b;
	char	**rgb;

	rgb = ft_split(cub3d->c, ',');
	if (check_digit_color(rgb))
	{
		free_table(rgb);
		return (1);
	}
	r = ft_atoi(rgb[0]);
	g = ft_atoi(rgb[1]);
	b = ft_atoi(rgb[2]);
	free_table(rgb);
	if ((r < 0 && r > 225) || (g < 0 && g > 225) || (b < 0 && b > 225))
	{
		printf ("HI the value of rgb color should be bteween 0 and 225\n");
		return (1);
	}
	cub3d->ceilling_c = encode_rgb(r, g, b);
	return (0);
}
