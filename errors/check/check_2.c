/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouali <ybouali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 23:21:05 by ybouali           #+#    #+#             */
/*   Updated: 2022/05/08 14:53:34 by ybouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

// int check_len_map(t_cub3d *cub3d_info)
// {
//     size_t     len;
//     int     i;

//     i = 0;
//     len = ft_strlen(cub3d_info->info_of_map[0]);
//     while (cub3d_info->info_of_map[++i] != 0)
//     {
//         if (len != ft_strlen(cub3d_info->info_of_map[i]))
//             return (error_len_map(i));
//     }
//     return (0);
// }

int     check_number_of_player(char **table)
{
    int     i;
    int     j;
    int     count;

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