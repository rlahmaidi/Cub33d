/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouali <ybouali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 20:57:57 by ybouali           #+#    #+#             */
/*   Updated: 2022/05/12 03:12:42 by ybouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

char    get_the_player_in_map(t_cub3d *cub3d)
{
    int     i;
    int     j;
    
    i = -1;
    while (cub3d->info_of_map[++i] != 0)
    {
        j = -1;
        while (cub3d->info_of_map[i][++j] != '\0')
        {
            if (check_in("NEWS", cub3d->info_of_map[i][j]))
                return (cub3d->info_of_map[i][j]);
        }
    }
    return (0);
}

int     get_turn_derection_p(t_cub3d *cub3d)
{
    char    p;

    p = get_the_player_in_map(cub3d);
    if (p == 'W')
        return (-1);
    if (p == 'E')
        return (1);
    return (0);
}

int     get_walk_derection_p(t_cub3d *cub3d)
{
    char    p;

    p = get_the_player_in_map(cub3d);
    if (p == 'S')
        return (1);
    if (p == 'N')
        return (-1);
    return (0);
}

float   start_angle(t_player *player)
{
    if (player->turn_derection == 1)
        return (M_PI * 2);
    if (player->turn_derection == -1)
        return (M_PI);
    if (player->walk_derection == 1)
        return (M_PI / 2);
    if (player->walk_derection == -1)
        return ((3 * M_PI) / 2);
    return (0);
}

t_player    *init_player(t_cub3d *cub3d)
{
    t_player    *player_new;
    
    player_new = malloc(sizeof(t_player));
    player_new->x = cub3d->f_x;
    player_new->y = cub3d->f_y;
    player_new->height = 1;
    player_new->with = 1;
    player_new->turn_derection = get_turn_derection_p(cub3d);
    player_new->walk_derection = get_walk_derection_p(cub3d);
    player_new->rotation_angel = start_angle(player_new);
    player_new->walk_speed = 20;
    player_new->turn_speed = (45 * (M_PI / 180));
    return (player_new);
}
