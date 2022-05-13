/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouali <ybouali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 20:59:59 by ybouali           #+#    #+#             */
/*   Updated: 2022/05/10 17:39:09 by ybouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int     check_first_line(t_cub3d *cub3d)
{
    int     i;
    
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

int     check_last_line(t_cub3d *cub3d, int len)
{
    int     i;
    
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

int     check_in(char *str, char c)
{
    int     i;

    i = -1;
    while (str[++i])
    {
        if (str[i] == c)
            return (1);
    }
    return (0);
}

int     check_space(t_cub3d *cub3d_info, int i, int j, int n)
{
    int     i_tmp;
    
    i_tmp = i;
    while (i_tmp > 0)
    {
        if (cub3d_info->info_of_map[i_tmp - 1][j] == '\0' || (int)ft_strlen(cub3d_info->info_of_map[i_tmp - 1]) < j)
            break;
        if ((i_tmp - 1) > 0 && cub3d_info->info_of_map[i_tmp - 1][j] != ' ' && cub3d_info->info_of_map[i_tmp - 1][j] != '1')
        {
            return (1);
        }
        else if (cub3d_info->info_of_map[i_tmp - 1][j] == '1')
                break;
        i_tmp--;
    }
    i_tmp = i;
    while (i_tmp < n)
    {
        if ((i_tmp + 1) < n)
        {
            if (
                cub3d_info->info_of_map[i_tmp][j] == '\0' ||\
                cub3d_info->info_of_map[i_tmp + 1][j] == '\0' ||\
                (int)ft_strlen(cub3d_info->info_of_map[i_tmp + 1]) < j
            )
                break;
            else if (cub3d_info->info_of_map[i_tmp + 1][j] != ' ' && cub3d_info->info_of_map[i_tmp + 1][j] != '1')
                return (1);
            else if (cub3d_info->info_of_map[i_tmp + 1][j] == '1')
                return (0);
            else if (cub3d_info->info_of_map[i_tmp + 1][j] == ' ')
                i_tmp++;
        }
        else
            break;
    }
    return (0);
}

int     check_zero(t_cub3d *cub3d_info, int i, int j, int n)
{
    int     i_tmp;
    
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

int     check_space_is_not_closed(t_cub3d *cub3d_info, int n)
{
    int     i;
    int     j;
    
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

int     check_lines_between(t_cub3d *cub3d_info, int n)
{
    int i = 0;
    int j = 0;
    
    while (++i < (n - 1))
    {
        j = 0;
        while (cub3d_info->info_of_map[i][j] != '\0')
        {
            if (cub3d_info->info_of_map[i][j] == ' ')
            {
                if ((j - 1) > 0 && cub3d_info->info_of_map[i][j - 1] != '1')
                    return (error_expact_1());
                else
                {
                    while (cub3d_info->info_of_map[i][j] != '\0' && cub3d_info->info_of_map[i][j] == ' ')
                        j++;
                    if (cub3d_info->info_of_map[i][j] != '\0' && cub3d_info->info_of_map[i][j] != '1' )
                        return (error_expact_1());
                }
            }
            else if (check_in("10NSWE", cub3d_info->info_of_map[i][j]))
            {
                if (cub3d_info->info_of_map[i][j] != '1')
                    return (error_expact_1());
                while (check_in("10NSWE", cub3d_info->info_of_map[i][j]))
                    j++;
                if (cub3d_info->info_of_map[i][j] == '\0' && cub3d_info->info_of_map[i][j - 1] != '1')
                    return (error_expact_1());
                else if (cub3d_info->info_of_map[i][j] != '\0' && cub3d_info->info_of_map[i][j] != '1' && cub3d_info->info_of_map[i][j] != ' ')
                    return (error_expact_1());
            }
            else
                return (error_expact_1());
        }
        if (check_space_is_not_closed(cub3d_info, n))
            return (error_expact_1());
    }
    return (0);
}