/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouali <ybouali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 17:43:40 by ybouali           #+#    #+#             */
/*   Updated: 2022/05/11 20:06:46 by ybouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/cub3d.h"




int main(int ac, char **av)
{
    t_cub3d     *cub3d_info;
    
    if (ac != 2)
        return (err_args());

    cub3d_info = check_for_syntax_map(av[1]);
    if (!cub3d_info)
        return (1);
    if (check_map_errors(cub3d_info))
    {
        free_info_map(&cub3d_info);
        return (1);
    }
    // display_cub3d_info(&cub3d_info);
    launch(cub3d_info);
    
    return (0);
}
