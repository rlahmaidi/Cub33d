/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouali <ybouali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 01:02:45 by ybouali           #+#    #+#             */
/*   Updated: 2022/05/12 03:00:25 by ybouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int e(void *cub3d)
{
    (void)cub3d;
    exit(1);
    return (1);
}


static void init_images(t_cub3d *cub3d)
{
    int w;
    int h;

    cub3d->no_texture = mlx_xpm_file_to_image(cub3d->ptr_init, cub3d->no, &w, &h);
    cub3d->so_texture = mlx_xpm_file_to_image(cub3d->ptr_init, cub3d->so, &w, &h);
    cub3d->we_texture = mlx_xpm_file_to_image(cub3d->ptr_init, cub3d->we, &w, &h);
    cub3d->ea_texture = mlx_xpm_file_to_image(cub3d->ptr_init, cub3d->ea, &w, &h);
    cub3d->player_texture = mlx_xpm_file_to_image(cub3d->ptr_init, "./texture/player.xpm", &w, &h);
    cub3d->ground_texture = mlx_xpm_file_to_image(cub3d->ptr_init, "./texture/ground.xpm", &w, &h);
}

void launch(t_cub3d *cub3d)
{
    cub3d->height = (length_of_map(cub3d->info_of_map) * TILE_SIZE);
    cub3d->width = (max__with_in_map(cub3d->info_of_map) * TILE_SIZE);
    // i added this
    //cub3d->colorbuffer = (uint32_t *)mallloc(sizeof(uint32_t) * (uint32_t)cub3d->width * (uint32_t)cub3d->height);
    // end 
    cub3d->ptr_init = mlx_init();
    cub3d->ptr_win = mlx_new_window(cub3d->ptr_init, cub3d->width, cub3d->height, "CUB3D");
    mlx_hook(cub3d->ptr_win, 17, 0L, e, cub3d);
    change_the_position_of_player(cub3d);
    init_images(cub3d);
    cub3d->player = init_player(cub3d);
   	

    print_images(cub3d);
    mlx_key_hook(cub3d->ptr_win, key_press, cub3d);
    mlx_loop(cub3d->ptr_init);
}