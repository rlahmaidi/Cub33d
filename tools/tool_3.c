/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouali <ybouali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 18:24:42 by ybouali           #+#    #+#             */
/*   Updated: 2022/05/10 20:42:49 by ybouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

t_cub3d    *init_cub3d_info(void)
{
    t_cub3d *cub3d_init;
    
    cub3d_init = malloc(sizeof(t_cub3d));
    if (!cub3d_init)
    {
        error_malloc();
        return (NULL);
    }
    cub3d_init->fov_angle = (60 * (M_PI / 180));
    cub3d_init->c = NULL;
    cub3d_init->f = NULL;
    cub3d_init->ceilling_c = 0;
    cub3d_init->floor_c = 0;
    cub3d_init->ea = NULL;
    cub3d_init->info_of_map = NULL;
    cub3d_init->no = NULL;
    cub3d_init->so = NULL;
    cub3d_init->we = NULL;
    cub3d_init->player = NULL;
    cub3d_init->ground_texture = NULL;
    cub3d_init->player_texture = NULL;
    cub3d_init->rays = NULL;
    return (cub3d_init);
}

int	length_of_map(char **table)
{
	int	i;

	i = 0;
	while (table[i])
		i++;
	return (i);
}

int max__with_in_map(char **table)
{
    int     i;
    int     j;
    int     len;

    i = -1;
    len = 0;
    while (table[++i] != 0)
    {
        j = ft_strlen(table[i]);
        if (len < j)
            len = j;
    }
    return (len);
}

t_ray   *init_ray(void)
{
    t_ray   *rays;
    
    rays = malloc(sizeof(t_ray));
    if (!rays)
        return (NULL);
    rays->ray_id = 0;
    rays->distance = 0;
    rays->is_ray_facing_down = 0;
    rays->is_ray_facing_left = 0;
    rays->is_ray_facing_right = 0;
    rays->is_ray_facing_up = 0;
    rays->was_hit_horizontal = 0;
    rays->was_hit_vertical = 0;
    rays->wall_hit_x = 0;
    rays->wall_hit_y = 0;
    rays->wall_hit_content = '\0';
    rays->next = NULL;
    return (rays);
}

void    push_ray(t_ray **head, t_ray *new)
{
    t_ray *tmp;

    tmp = *head;
    if (*head == NULL)
        *head = new;
    else
    {
        while (tmp->next != NULL)
            tmp = tmp->next;
        tmp->next = new;
    }
}

void    free_rays(t_ray **head)
{
    t_ray   *tmp;
    t_ray   *tmp_1;

    tmp = *head;
    if (*head != NULL)
    {
        while (tmp)
        {
            tmp_1 = tmp;
            tmp = tmp->next;
            tmp_1->next = NULL;
            free (tmp_1);
        }
        free (tmp);
        *head = NULL;
    }
}