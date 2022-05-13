/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_mlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouali <ybouali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 21:29:18 by ybouali           #+#    #+#             */
/*   Updated: 2022/05/12 03:33:34 by ybouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

void    ft_exit(t_cub3d *cub3d)
{
    mlx_clear_window(cub3d->ptr_init, cub3d->ptr_win);
	mlx_destroy_window(cub3d->ptr_init, cub3d->ptr_win);
    exit (0);
}

int     no_wall(t_cub3d *cub3d, float x, float y)
{
    int     x_map;
    int     y_map;

    if (x < 0 || x >= cub3d->width || y < 0 || y >= cub3d->height)
        return (0);
    x_map = floor(x);
    y_map = floor(y);
    // printf ("max W {%f} MAX H [%f] to ckeck Y {%f} X {%f} \n", cub3d->width, cub3d->height, y, x);
    if (cub3d->info_of_map[(int)y_map / TILE_SIZE][(int)x_map / TILE_SIZE] == '1')
        return (0);
    return (1);
}

void    move_player_new(t_cub3d *cub3d)
{
    float   move_step;
    float   x_p;
    float   y_p;
    
    cub3d->player->rotation_angel += (cub3d->player->turn_derection * cub3d->player->turn_speed);
    
    move_step = cub3d->player->walk_derection * cub3d->player->walk_speed;
    
    y_p = cub3d->player->y + sin(cub3d->player->rotation_angel) * move_step;
    x_p = cub3d->player->x + cos(cub3d->player->rotation_angel) * move_step;
    
    if (no_wall(cub3d, x_p, y_p))
    {
        cub3d->player->y = y_p;
        cub3d->player->x = x_p;
    }
}

int     key_press(int key, t_cub3d *cub3d)
{
    if (key == 126 || key == 13)
        cub3d->player->walk_derection = 1;
	else if (key == 125 || key == 1)
        cub3d->player->walk_derection = -1;
	else if (key == 124 || key == 2)
        cub3d->player->turn_derection = 1;
	else if (key == 123 || key == 0)
        cub3d->player->turn_derection = -1;
	else if (key == 53)
        ft_exit(cub3d);
    else
        return (1);
    move_player_new(cub3d);
    print_images(cub3d);
    return (1);
}

int	encode_rgb(uint8_t red, uint8_t green, uint8_t blue)
{
	return (red << 16 | green << 8 | blue);
}

double      rad2deg(double rad)
{
    return ((rad * 180) / M_PI);
}

// double      deg2rad(double rad)
// {
//     return ((rad * 180) / M_PI);
// }