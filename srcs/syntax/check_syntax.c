/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_syntax.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouali <ybouali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 03:05:25 by ybouali           #+#    #+#             */
/*   Updated: 2022/05/13 17:40:42 by ybouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	check_sytax(t_cub3d **info_check)
{
	t_cub3d	*info;

	info = *info_check;
	if (info->no == NULL || info->no[0] == '\0')
		return (error_syntax_no());
	else if (info->so == NULL || info->so[0] == '\0')
		return (error_syntax_so());
	else if (info->we == NULL || info->we[0] == '\0')
		return (error_syntax_we());
	else if (info->ea == NULL || info->ea[0] == '\0')
		return (error_syntax_ea());
	else if (info->f == NULL || info->f[0] == '\0')
		return (error_syntax_f());
	else if (info->c == NULL || info->c[0] == '\0')
		return (error_syntax_c());
	else if (info->info_of_map == NULL || info->info_of_map[0] == '\0')
		return (error_syntax_map());
	return (0);
}

int	help_convert(t_token *token, t_cub3d *cub3d)
{
	if (token->type == NO)
			cub3d->no = ft_strdup(token->value);
	else if (token->type == SO)
		cub3d->so = ft_strdup(token->value);
	else if (token->type == WE)
		cub3d->we = ft_strdup(token->value);
	else if (token->type == EA)
		cub3d->ea = ft_strdup(token->value);
	else if (token->type == F)
		cub3d->f = ft_strdup(token->value);
	else if (token->type == C)
		cub3d->c = ft_strdup(token->value);
	else if (token->type == MAP)
	{
		if (check_double_new_lines(token->value))
		{
			free_info_map(&cub3d);
			error_map_lines();
			return (1);
		}
		cub3d->info_of_map = ft_split(token->value, '\n');
	}
	return (0);
}
