/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_map_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouali <ybouali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 20:39:42 by ybouali           #+#    #+#             */
/*   Updated: 2022/05/09 16:39:43 by ybouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int     error_map_1(void)
{
    printf ("Error\n");
    printf ("the map should be more then 4 lines !\n");
    return (1);
}

int     error_space(int boolean)
{
    printf ("Error\n");
    printf ("Hi please check the map\n");
    if (boolean == 0)
        printf ("The first line of map should be 1 or space\n");
    else
        printf ("The last line of map should be 1 or space\n");
    return (1);
}

int     error_space_advance(void)
{
    printf ("Error\n");
    printf ("Hi wen there is a space in map schould be surrounded by 1\n");
    return (1);
}

int     error_the_first_char_on_line(int boolean)
{
    printf ("Error\n");
    printf ("Hi please check the map\n");
    if (boolean == 0)
        printf ("The first character on middle lines of map should be 1 or space\n");
    else
        printf ("The last character on middle lines of map should be 1 or space\n");
    return (1);
    
}

int     error_expact_1(void)
{
    printf ("Error\n");
    printf ("Hi expacte a 1 character !\n");
    return (1);
}

int     error_expact_2(int i)
{
    printf ("Error\n");
    printf ("Hi expacte a 1 character !\n");
    printf ("help\nlien number [%d] there is (space Or spacese) in your map it should be start or space with 1 character\n", i + 1);
    return (1);
}   

int     error_expact_3(int i)
{
    printf ("Error\n");
    printf ("Hi expacte a 1 character !\n");
    printf ("help\nlien number [%d] please close the map 1 character\n", i + 1);
    return (1);   
}

int     error_expact_4(int i)
{
    printf ("Error\n");
    printf ("Hi expacte a 1 character !\n");
    printf ("help\nlien number [%d] please close the map 1 character\n", i + 1);
    return (1);
}

int     error_len_map(int i)
{
    printf ("Error\n");
    printf ("help\nthe lien number [%d] has not the same length with the authors lines\n", i + 1);
    return (1);
}

int     error_number_of_player(void)
{
    printf ("Error\n");
    printf ("hi in the map it shoud be just one player !!\n");
    return (1);
}