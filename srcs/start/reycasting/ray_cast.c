/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouali <ybouali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 23:45:18 by ybouali           #+#    #+#             */
/*   Updated: 2022/05/12 03:18:21 by ybouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

float   normalize_angle(float ray_angle)
{
    ray_angle = remainder(ray_angle, (M_PI * 2));
    if (ray_angle < 0)
        ray_angle = ((M_PI * 2) + ray_angle);
    return (ray_angle);
}

float   distance(t_cub3d *cub3d, float y, float x)
{
    return (sqrt(((x - cub3d->player->x) * (x - cub3d->player->x)) + ((y - cub3d->player->y) * (y - cub3d->player->y))));
}

void     cast_ray(t_cub3d *cub3d, float ray_angle, int ray_id)
{
    float   y_intercept;
    float   x_intercept;
    float   y_step;
    float   x_step;
    float   x_check;
    float   next_horz_touch_x;
    float   next_horz_touch_y;
    float   y_check;
    t_ray   *ray;
    float tmp_ang;
    
    tmp_ang = ray_angle;
    ray_angle = normalize_angle(ray_angle);
    ray = init_ray();
    push_ray(&cub3d->rays, ray);
    ray->ray_id = ray_id;
    ray->is_ray_facing_down = (ray_angle > 0 && ray_angle < M_PI);
    ray->is_ray_facing_up = !ray->is_ray_facing_down;
    
    ray->is_ray_facing_right = (ray_angle < (0.5 * M_PI) || ray_angle > (1.5 * M_PI));
    ray->is_ray_facing_left = !ray->is_ray_facing_right;
    
    y_intercept = floor(cub3d->player->y / TILE_SIZE) * TILE_SIZE;

    y_intercept += ray->is_ray_facing_down ? TILE_SIZE : 0;
    
    x_intercept = (cub3d->player->x + ((y_intercept - cub3d->player->y) / tan(ray_angle)));
    
    y_step = TILE_SIZE;
    y_step *= ray->is_ray_facing_up ? -1 : 1; 
    
    x_step = (TILE_SIZE / tan(ray_angle));
    x_step *= (ray->is_ray_facing_left && x_step > 0) ? -1 : 1;
    x_step *= (ray->is_ray_facing_right && x_step < 0) ? -1 : 1;
    

    next_horz_touch_x = x_intercept;
    next_horz_touch_y = y_intercept;
    
    while (next_horz_touch_x >= 0 && next_horz_touch_x <= cub3d->width && next_horz_touch_y >= 0 && next_horz_touch_y <= cub3d->height)
    {
        x_check = next_horz_touch_x;
        y_check = next_horz_touch_y + (ray->is_ray_facing_up ? -1 : 0);
        if (!no_wall(cub3d, x_check, y_check))
        {
            ray->wall_hit_x = next_horz_touch_x;
            ray->wall_hit_y = next_horz_touch_y;
            ray->distance = distance(cub3d, ray->wall_hit_y, ray->wall_hit_x);
            ray->was_hit_horizontal = 1;
            break;
        }
        else
        {
            next_horz_touch_x += x_step;
            next_horz_touch_y += y_step;
        }
        if (next_horz_touch_x > cub3d->width || next_horz_touch_y > cub3d->height)
            break;   
    }
    
    float ver_des;
    x_intercept = floor(cub3d->player->x / TILE_SIZE) * TILE_SIZE;
    x_intercept += ray->is_ray_facing_right ? TILE_SIZE : 0;
    
    y_intercept = (cub3d->player->y + ((x_intercept - cub3d->player->x) * tan(ray_angle)));
    
    x_step = TILE_SIZE;
    x_step *= ray->is_ray_facing_left ? -1 : 1;

    y_step = (TILE_SIZE * tan(ray_angle));
    y_step *= (ray->is_ray_facing_up && y_step > 0) ? -1 : 1;
    y_step *= (ray->is_ray_facing_down && y_step < 0) ? -1 : 1;
    

    next_horz_touch_x = x_intercept;
    next_horz_touch_y = y_intercept;
    
    while (next_horz_touch_x >= 0 && next_horz_touch_x <= cub3d->width && next_horz_touch_y >= 0 && next_horz_touch_y <= cub3d->height)
    {
        x_check = next_horz_touch_x + (ray->is_ray_facing_left ? -1 : 0);
        y_check = next_horz_touch_y ;
        
        if (!no_wall(cub3d, x_check, y_check))
        {
            ver_des = distance(cub3d, next_horz_touch_y, next_horz_touch_x);
            if (ray->distance == 0 || ray->distance > ver_des)
            {
                ray->was_hit_horizontal = 0;
                ray->was_hit_vertical = 1;
                ray->wall_hit_x = next_horz_touch_x;
                ray->wall_hit_y = next_horz_touch_y;
            }
            break;
        }
        else
        {
            next_horz_touch_x += x_step;
            next_horz_touch_y += y_step;
        }
        if (next_horz_touch_x > cub3d->width || next_horz_touch_y > cub3d->height)
            break;
    }
}

void    cast_all_rays(t_cub3d *cub3d)
{
    float   ray_angle = cub3d->player->rotation_angel - (FOV_ANGLE / 2);
    int     ray_id;
    
    ray_id = -1;
    while (++ray_id < (cub3d->width / TILE_SIZE))
    {
        cast_ray(cub3d, ray_angle, ray_id);
        cub3d->ray = ray_angle;
        // DDA_ray(
        //     cub3d,
        //     cub3d->player->y + sin(ray_angle) * 100,
        //     cub3d->player->x + cos(ray_angle) * 100,
        //     encode_rgb(0,0,0)
        // );
        ray_angle += (FOV_ANGLE / (cub3d->width / TILE_SIZE));
    }
    
}