/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouali <ybouali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 01:50:02 by ybouali           #+#    #+#             */
/*   Updated: 2022/04/04 21:42:13 by ybouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int len_of_table(char *name_of_map)
{
    int len;
    char *line;
    
    len = 0;
    int fd = open (name_of_map, O_RDONLY, 0644);
    if (fd < 0)
        return (error_fd(name_of_map));
    line = get_next_line(fd);
    while (line)
    {
        len++;
        free (line);
        line = get_next_line(fd);
    }
    close (fd);
    return (len);
}

char    **alocate_2d_table(char *name_of_file)
{
    int     len;
    char    **info_of_map;
    
    len = len_of_table(name_of_file);
    if (len == -1)
        return (NULL);
    if (len == 0)
        return (error_map_empty(name_of_file));
    info_of_map = malloc(sizeof(char *) * (len + 1));
    if (!info_of_map)
    {
        error_malloc();
        return (NULL);
    }
    info_of_map[len] = 0;
    return (info_of_map);
}

char    **stock_info_map(char *name_of_map)
{
    char    *line;
    int     fd;
    int     i;
    char    **info_of_map;
    
    info_of_map = alocate_2d_table(name_of_map);
    if (!info_of_map)
        return (NULL);
    fd = open (name_of_map, O_RDONLY, 0644);
    if (fd < 0)
    {
        error_fd(name_of_map);
        return (NULL);
    }
    line = get_next_line(fd);
    i = 0;
    while (line)
    {
        info_of_map[i] = ft_strdup(line);
        if (!info_of_map[i])
        {
            error_malloc();
            return (NULL);
        }
        i++;
        free (line);
        line = get_next_line(fd);
    }
    close (fd);
    return (info_of_map);
}