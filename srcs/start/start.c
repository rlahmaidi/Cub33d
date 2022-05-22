/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouali <ybouali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 01:02:45 by ybouali           #+#    #+#             */
/*   Updated: 2022/05/15 02:55:44 by ybouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

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

	cub3d->no_texture = mlx_xpm_file_to_image(cub3d->ptr_init, \
	cub3d->no, &w, &h);
	cub3d->so_texture = mlx_xpm_file_to_image(cub3d->ptr_init, \
	cub3d->so, &w, &h);
	cub3d->we_texture = mlx_xpm_file_to_image(cub3d->ptr_init, \
	cub3d->we, &w, &h);
	cub3d->ea_texture = mlx_xpm_file_to_image(cub3d->ptr_init, \
	cub3d->ea, &w, &h);
	cub3d->player_texture = mlx_xpm_file_to_image(cub3d->ptr_init, \
	"./texture/player.xpm", &w, &h);
	cub3d->ground_texture = mlx_xpm_file_to_image(cub3d->ptr_init, \
	"./texture/ground.xpm", &w, &h);
}

void launch(t_cub3d *cub3d)
{
	cub3d->height = (length_of_map(cub3d->info_of_map) * TILE_SIZE);
	cub3d->width = (max__with_in_map(cub3d->info_of_map) * TILE_SIZE);
	cub3d->ptr_init = mlx_init();
	cub3d->ptr_win = mlx_new_window(cub3d->ptr_init, WIDTH, HEIGHT, "CUB3D");
	cub3d->data.img = mlx_new_image(cub3d->ptr_init, WIDTH, HEIGHT);
	cub3d->data.addr =  mlx_get_data_addr(cub3d->data.img, &cub3d->data.bits_per_pixel,\
	 &cub3d->data.line_length,&cub3d->data.endian);
	mlx_hook(cub3d->ptr_win, 17, 0L, e, cub3d);
	change_the_position_of_player(cub3d);
	init_images(cub3d);
	cub3d->player = init_player(cub3d);
	print_images(cub3d);
	// printf ("posi X {%d} posi Y {%d}\n", cub3d->player->x, cub3d->player->y);
	mlx_key_hook(cub3d->ptr_win, key_press, cub3d);
	mlx_loop(cub3d->ptr_init);
}