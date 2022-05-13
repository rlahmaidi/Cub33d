/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_syntax.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouali <ybouali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 03:05:25 by ybouali           #+#    #+#             */
/*   Updated: 2022/05/08 14:26:36 by ybouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int     check_sytax(t_cub3d **info_check)
{
    t_cub3d *info;

    
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