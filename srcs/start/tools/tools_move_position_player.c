/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_move_position_player.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouali <ybouali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 00:08:10 by ybouali           #+#    #+#             */
/*   Updated: 2022/05/16 00:13:08 by ybouali          ###   ########.fr       */
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
    printf ("X_PLAYER [%d] Y_PLAYER [%d]\n\n", cub3d->player->x, cub3d->player->y);
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
    for (int i = 0; i <= steps; i++) // this need to changed with while if we have to keep it;
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
    }
}

void    update_rays_info(t_ray **rays_h, t_cub3d *cub3d)
{
    t_ray   *rays;
    float   pwh;
    
    pwh =((HEIGHT / 2) / tan(FOV_ANGLE / 2));
    rays = *rays_h;
    while (rays != NULL)
    {
        rays->distance = fabs(rays->distance * cos(rays->ray_angle - cub3d->player->rotation_angel));
        rays->wall_h = pwh * (TILE_SIZE / rays->distance);
        rays->wall_h_helf = (rays->wall_h / 2);
        rays->wall_start_y = ((HEIGHT / 2) - rays->wall_h_helf);
        rays->wall_start_y = (rays->wall_start_y <= 0 || rays->distance == 0) ? 0 : rays->wall_start_y;
        rays->wall_start_x = rays->ray_id * TILE_SIZE;
        rays->wall_end_y = ((HEIGHT / 2) + rays->wall_h_helf);
        rays->wall_end_y = (rays->wall_end_y >= HEIGHT || rays->distance == 0) ? HEIGHT : rays->wall_end_y;
        rays->wall_end_x = rays->ray_id * TILE_SIZE;
        rays = rays->next;
    }
}

void    print_rays(t_ray **rays_h, t_cub3d *cub3d)
{
    t_ray   *rays;
    
    int     r = 0, g = 0, b = 0;
    
    rays = *rays_h;
    while (rays != NULL)
    {   
        DDA_ray(
                cub3d,
                rays->wall_hit_y,
                rays->wall_hit_x
                ,encode_rgb(r, g, b));
        r += 8;
        g += 8;
        b += 8;
        if (r >= 255 || g >= 255 || b >= 255)
        {
            r = 0;
            g = 0;
            b = 0;
        }
        
        rays = rays->next;
    }
}

int     number_rays(t_ray **rays)
{    
    t_ray   *ray;
    int     i;
    
    i = 0;
    ray = *rays;
    while (ray != NULL)
    {
        i++;
        ray = ray->next;
    }
    return (i);
}

void    start_3d(t_ray **rays, t_cub3d *cub3d)
{
    t_ray   *ray;

    ray = *rays;
    int     x = 0;
    int     y = 0;
    int     end = 0;
    t_data ground_texture;
    t_data wall_texture;
    t_data ceiling_texture;
    char *dst;
    int textureOffsetX;
    int distanceFromTop;
    
    
 ground_texture.img = cub3d->no_texture;
 ground_texture.addr = mlx_get_data_addr (ground_texture.img,  &ground_texture.bits_per_pixel,  &ground_texture.line_length,
								 &ground_texture.endian);
wall_texture.img = cub3d->ea_texture;
wall_texture.addr = mlx_get_data_addr (wall_texture.img,  &wall_texture.bits_per_pixel,  &wall_texture.line_length,
								 &wall_texture.endian);
ceiling_texture.img = cub3d->we_texture;
ceiling_texture.addr = mlx_get_data_addr (ceiling_texture.img,  &ceiling_texture.bits_per_pixel,  &ceiling_texture.line_length,
								 &ceiling_texture.endian);
        printf("bits per pixel is :%d \n", ceiling_texture.bits_per_pixel);
    while (ray != NULL)
    {
        y = -1;
        while (++y <= ray->wall_start_y)// ceiling 
        {
            x = ray->ray_id * TILE_SIZE;
            end = ray->ray_id * TILE_SIZE + TILE_SIZE;
            while (x < end)
            {
                dst = ground_texture.addr + (y * 50  + x );
               my_mlx_pixel_put(&cub3d->data,  x,  y, cub3d->ceilling_c);
               //my_mlx_pixel_put(&cub3d->data,  x,  y, cub3d->floor_c);
                x++;
            }
        }
        // y = ray->wall_start_y;
        //// start of add;
        if(ray->was_hit_vertical)
        {
           textureOffsetX = (int) ray->wall_hit_y % TILE_SIZE ;
          
        }
        else
        {
            textureOffsetX = (int)ray->wall_start_x % TILE_SIZE;
        }
        //end of add;
        while (y <= ray->wall_end_y) //// wall 
        {
            distanceFromTop = y + (ray->wall_h / 2) - (HEIGHT / 2);
            int textureOffsetY = distanceFromTop * ((float)TEXTURE_HEITH / ray->wall_h);
            x = ray->ray_id * TILE_SIZE;
            end = ray->ray_id * TILE_SIZE + TILE_SIZE ; 
            while (x <= end)
            {

                
                 if (ray->was_hit_horizontal)
                 {
                    dst = wall_texture.addr + (textureOffsetY  * wall_texture.line_length * TEXTURE_WIDTH\
                     + textureOffsetX * (wall_texture.bits_per_pixel / 8) );
                     my_mlx_pixel_put(&cub3d->data,  x,  y, (unsigned int)dst);
                 }
                if (ray->was_hit_vertical)
                {
                    dst = wall_texture.addr + (textureOffsetY * TEXTURE_WIDTH + textureOffsetX );
                my_mlx_pixel_put(&cub3d->data,  x,  y, (unsigned int)dst);
                }
                x++;
            }
             y++;
        }
        //y = ray->wall_end_y;
        while (y < HEIGHT)// floor
        {
            x = ray->ray_id * TILE_SIZE;
            end = ray->ray_id * TILE_SIZE + TILE_SIZE;
            while (x < end)
            {
                //mlx_pixel_put(cub3d->ptr_init, cub3d->ptr_win, x, y, encode_rgb(255, 255, 255));
                //dst = ceiling_texture.addr + (y * TEXTURE_WIDTH + x );
                my_mlx_pixel_put(&cub3d->data,  x,  y, cub3d->floor_c);
                x++;
            }
            y++;
        }
        ray = ray->next;
    }
    mlx_put_image_to_window(cub3d->ptr_init,cub3d->ptr_win,cub3d->data.img,0, 0);
   // free(cub3d->data.img);
    
     //mlx_destroy_image(cub3d->ptr_init, cub3d->data.img);
    // mlx_destroy_image(cub3d->ptr_init, cub3d->no_texture);
    // mlx_destroy_image(cub3d->ptr_init, cub3d->ea_texture);
    // mlx_destroy_image(cub3d->ptr_init, cub3d->we_texture);0

} 

void    print_images(t_cub3d *cub3d)
{
    // int  x;
    // int  y;
    
    mlx_clear_window(cub3d->ptr_init, cub3d->ptr_win);
    // y = 0;
    // while (y < cub3d->height)
    // {
    //     x = 0;
    //     while (x < cub3d->width)
    //     {
    //         if (cub3d->info_of_map[(y / TILE_SIZE )][(x / TILE_SIZE)] == '1')
    //             mlx_put_image_to_window(cub3d->ptr_init, cub3d->ptr_win, cub3d->we_texture, x, y);
    //         else
    //             mlx_put_image_to_window(cub3d->ptr_init, cub3d->ptr_win, cub3d->ground_texture, x, y);
    //         if (cub3d->info_of_map[(y / TILE_SIZE)][(x / TILE_SIZE)] == '\0')
    //             break;
    //         x += TILE_SIZE;
    //     }
    //     y += TILE_SIZE;
    // }
    // print_player(cub3d);
    cast_all_rays(cub3d);
    // print_rays(&cub3d->rays, cub3d);
    // DDA_ray(
    //     cub3d,
    //     cub3d->player->y + sin(cub3d->player->rotation_angel) * 1000,
    //     cub3d->player->x + cos(cub3d->player->rotation_angel) * 1000,
    //     encode_rgb(0,32,255)
    // );
    update_rays_info(&cub3d->rays, cub3d);
    // display_ray_info(&cub3d->rays, cub3d);
    start_3d(&cub3d->rays, cub3d);
    free_rays(&cub3d->rays);
    cub3d->player->walk_derection = 0;
    cub3d->player->turn_derection = 0;
}