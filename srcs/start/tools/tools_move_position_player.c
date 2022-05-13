/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_move_position_player.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouali <ybouali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 00:08:10 by ybouali           #+#    #+#             */
/*   Updated: 2022/05/12 03:08:27 by ybouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

void	ft_p_x_player(t_cub3d *cub3d, int x, int y, int k)
{
    if (cub3d->info_of_map[(x / 50)][(y / 50)] == 'N' && cub3d->info_of_map[(k / 50)][(y / 50)] == '0')
    {
        cub3d->info_of_map[(x / 50)][(y / 50)] = '0';
        cub3d->info_of_map[(k / 50)][(y / 50)] = 'N';
    }
}

void	ft_p_y_player(t_cub3d *cub3d, int x, int y, int k)
{
    if (cub3d->info_of_map[(x / 50)][(y / 50)] == 'N' && cub3d->info_of_map[(x / 50)][(k / 50)] == '0')
    {
        cub3d->info_of_map[(x / 50)][(y / 50)] = '0';
        cub3d->info_of_map[(x / 50)][(k / 50)] = 'N';
    }
}

void    protect_player_to_walk_into_wals(t_cub3d *cub3d)
{
    if (cub3d->player->walk_derection == 1)
        cub3d->player->x += 6;
    if (cub3d->player->walk_derection == -1)
        cub3d->player->x -= 6;
    if (cub3d->player->turn_derection == 1)
        cub3d->player->y -= 6;
    if (cub3d->player->turn_derection == -1)
        cub3d->player->y += 6;
}

void    print_player_info(t_cub3d *cub3d)
{
    printf ("\n\n|||||||||||||| START PRINTING INFO PLAYER ... ||||||||||||||||||||||||||||||||||||||\n");
    printf ("X_PLAYER [%f] Y_PLAYER [%f]\n\n", cub3d->player->x, cub3d->player->y);
    if (cub3d->player->turn_derection == 1)
        printf ("RIGHT\n");
    if (cub3d->player->turn_derection == -1)
        printf ("LEFT\n");
    if (cub3d->player->walk_derection == 1)
        printf ("FRONT\n");
    if (cub3d->player->walk_derection == -1)
        printf ("BACK\n");
    printf ("\n>>>>>>>>>>>>>>>>>>>{%f}\n", rad2deg(cub3d->player->rotation_angel));
    printf ("\n\n|||||||||||||| END PRINTING INFO PLAYER ... ||||||||||||||||||||||||||||||||||||||\n");
}

int abs (int n)
{
    return ( (n>0) ? n : ( n * (-1)));
}


void DDA(t_cub3d *cub3d , int Y1, int X1)
{
    // calculate dx & dy
    int     X0 = cub3d->player->x;
    int     Y0 = cub3d->player->y;
    int     dx = X1 - X0;
    int     dy = Y1 - Y0;
    
    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
 
    float Xinc = dx / (float) steps;
    float Yinc = dy / (float) steps;
 
    // Put pixel for each step
    float X = X0;
    float Y = Y0;
    for (int i = 0; i <= steps; i++)
    {
        mlx_pixel_put(cub3d->ptr_init, cub3d->ptr_win, X, Y, 000);
        X += Xinc;
        Y += Yinc;
    }
}

void    print_player(t_cub3d *cub3d)
{
    float   x_start;
    float   y_start;
    float   x_end; 
    float   y_end;
    
    y_start = cub3d->player->y - 3;
    x_end = cub3d->player->x + 3;
    y_end = cub3d->player->y + 3;
    // print_player_info(cub3d);
    while (y_start < y_end)
    {
        x_start = cub3d->player->x - 3;
        while (x_start < x_end)
            mlx_pixel_put(cub3d->ptr_init, cub3d->ptr_win, x_start++, y_start, 125);
        y_start++;
    }
}

int ab_s (int n)
{
    return ( (n>0) ? n : ( n * (-1)));
}

void DDA_ray(t_cub3d *cub3d , int Y1, int X1, int color)
{
    // calculate dx & dy
    int     X0 = cub3d->player->x;
    int     Y0 = cub3d->player->y;
    int     dx = X1 - X0;
    int     dy = Y1 - Y0;
    
    int steps = ab_s(dx) > ab_s(dy) ? ab_s(dx) : ab_s(dy);
 
    float Xinc = dx / (float) steps;
    float Yinc = dy / (float) steps;
 
    // Put pixel for each step
    float X = X0;
    float Y = Y0;
    for (int i = 0; i <= steps; i++)
    {
        mlx_pixel_put(cub3d->ptr_init, cub3d->ptr_win, X, Y, color);
        X += Xinc;
        Y += Yinc;
        if (X == 0 || Y == 0)
            printf("ray = %f\n", cub3d->ray);
    }
}

void    print_rays(t_ray **rays_h, t_cub3d *cub3d)
{
    t_ray   *rays;
    
    rays = *rays_h;
    // printf ("\n\n||||||||||||||||||||||||||||||||||||| START |||||||||||||||||||||||||||||||||||||||||||||\n");
    while (rays != NULL)
    {
        // printf ("\n\n\nray index {%d} ** X[%f] Y[%f]\n\n\n", rays->ray_id, rays->wall_hit_x, rays->wall_hit_y);
        DDA_ray(
                cub3d,
                rays->wall_hit_y,
                rays->wall_hit_x
                ,encode_rgb(255,0,0));
        rays = rays->next;
    }
    // printf ("\n\n|||||||||||||||||||||||||||||||||||| END ||||||||||||||||||||||||||||||||||||||||||||||\n");
}

void    print_images(t_cub3d *cub3d)
{
    int  x;
    int  y;
     //char *filename = ".texture/ground.xpm";

    
    // rays info
    // cast_all_rays(cub3d);
    mlx_clear_window(cub3d->ptr_init, cub3d->ptr_win);
    y = 0;
    while (y < cub3d->height)
    {
        x = 0;
        while (x < cub3d->width)
        {
            if (cub3d->info_of_map[(y / TILE_SIZE)][(x / TILE_SIZE)] == '1')
            {
                mlx_put_image_to_window(cub3d->ptr_init, cub3d->ptr_win, cub3d->we_texture, x, y);
                
            }
            else
                mlx_put_image_to_window(cub3d->ptr_init, cub3d->ptr_win, cub3d->ground_texture, x, y);
            if (cub3d->info_of_map[(y / TILE_SIZE)][(x / TILE_SIZE)] == '\0')
                break;
            x += TILE_SIZE;
        }
        y += TILE_SIZE;
    }
    //mlx_xpm_file_to_image( cub3d->ptr_init,  filename, (int *) 100 ,(int *) 100);
    print_player(cub3d);
    cast_all_rays(cub3d);
    print_rays(&cub3d->rays, cub3d);
    DDA_ray(
        cub3d,
        cub3d->player->y + sin(cub3d->player->rotation_angel) * 150,
        cub3d->player->x + cos(cub3d->player->rotation_angel) * 150,
        encode_rgb(0,32,255)
    );
    free_rays(&cub3d->rays);
    cub3d->player->walk_derection = 0;
    cub3d->player->turn_derection = 0;
}