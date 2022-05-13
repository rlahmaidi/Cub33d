/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouali <ybouali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 18:03:13 by ybouali           #+#    #+#             */
/*   Updated: 2022/05/10 23:29:20 by ybouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int     len_table(char **table)
{
    int     i;

    i = 0;
    while (table[i])
        i++;
    return (i);
}

int check_name_of_map(char *name_of_map)
{
    int     len;

    len = ft_strlen(name_of_map);
    len -= 4;
    if (name_of_map[len] == '\0')
        return (error_name());
    if (ft_strncmp(&name_of_map[len], ".cub", \
    ft_strlen(&name_of_map[len])) == 0)
        return (0);
    return (error_name());
}

char    *check_map(char *name_of_map)
{
    char    **info_of_map;
    
    if (check_name_of_map(name_of_map))
        return (NULL);
    info_of_map = stock_info_map(name_of_map);
    if (!info_of_map)
        return (NULL);
    return (ft_table_dup_to_string(info_of_map));
}

int     last_check(t_cub3d *cub3d_info, int n)
{
    int     i;
    int     j;

    i = 1;
    while (i < (n - 1))
    {
        j = 0;
        while (cub3d_info->info_of_map[i][j])
        {
            if (cub3d_info->info_of_map[i][j] == ' ')
            {
                if ((i - 1) > 0 && (i - 1) <= (n - 1))
                {
                    if (cub3d_info->info_of_map[i - 1][j] != '\0' &&\
                    cub3d_info->info_of_map[i - 1][j] != '1' &&\
                    cub3d_info->info_of_map[i - 1][j] != ' ')
                        return (error_expact_3(i - 1));
                }
                if ((i + 1) > 0 && (i + 1) <= (n - 1))
                {
                    if (cub3d_info->info_of_map[i + 1][j] != '\0' &&\
                    cub3d_info->info_of_map[i + 1][j] != '1' &&\
                    cub3d_info->info_of_map[i + 1][j] != ' ')
                        return (error_expact_4(i + 1));
                }
            }
            j++;
        }
        i++;
    }
    return (0);
}

int check_name_of_textuer(char *name_of_map)
{
    int     len;

    len = ft_strlen(name_of_map);
    len -= 4;
    if (name_of_map[len] == '\0')
        return (error_name_tex());
    if (ft_strncmp(&name_of_map[len], ".xpm", \
    ft_strlen(&name_of_map[len])) == 0)
        return (0);
    return (error_name_tex());
}

int check_name_of_textuers(t_cub3d *cub3d)
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

int     check_digit_color(char **rgb)
{
    int     r;
    int     g;
    
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

int check_color_floor(t_cub3d *cub3d)
{
    int     r;
    int     g;
    int     b;
    char    **rgb;
    
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
    if (r < 0 || r > 225 || g < 0 || g > 225 || b < 0 || b > 225)
        return (error_colors_3());
    cub3d->floor_c = encode_rgb(r, g, b);
    return (0);
}

int check_color_ceilling(t_cub3d *cub3d)
{
    int     r;
    int     g;
    int     b;
    char    **rgb;
    
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
    if (r < 0 || r > 225 || g < 0 || g > 225 || b < 0 || b > 225)
    {
        printf ("HI the value of rgb color should be bteween 0 and 225\n");
        return (1);
    }
    cub3d->ceilling_c = encode_rgb(r, g, b);
    return (0);
}

int     check_colors(t_cub3d *cub3d)
{
    if (check_color_floor(cub3d))
        return (1);
    if (check_color_ceilling(cub3d))
        return (1);
    
    return (0);
}

int     check_derection_and_colors(t_cub3d *cub3d)
{
    int     fd;
    
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
    // check for colors
    if (check_colors(cub3d))
        return (1);
    return (0);
}

int     check_map_errors(t_cub3d *cub3d_info)
{
    int     i;
    int     n;

    i = 0;
    n = len_table(cub3d_info->info_of_map);
    if (n <= 4)
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