/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouali <ybouali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 04:19:43 by ybouali           #+#    #+#             */
/*   Updated: 2022/05/10 23:29:00 by ybouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int    err_args(void)
{
    printf("Error\n");
    printf("To run the cub3d please\n");
    printf("Type ./cub3d name_of_map.cub\n");
    printf("NO MORE\n");
    return (1);
}

int     error_name(void)
{
    printf("Error\n");
    printf("The name of map shoud be .cub\n");
    return (1);
}

int     error_colors_1(void)
{
    printf("Error\n");
    printf("HI Ineed three values for one color\n");
    return (1);
}

int     error_colors_2(void)
{
    printf("Error\n");
    printf("char in colors\n");
    return (1);
}

int     error_colors_3(void)
{
    printf("Error\n");
    printf("HI the value of rgb color should be bteween 0 and 225\n");
    return (1);
}

int     error_name_tex(void)
{
    printf("Error\n");
    printf("The name of map shoud be .xpm\n");
    return (1);
}

int error_fd(char *name_of_file)
{
    printf("Error\n");
    printf("File with name of [%s] not found\n", name_of_file);
    return (-1);
}

char    **error_map_empty(char *name_of_file)
{
    printf("Error\n");
    printf("File with name of [%s] is is empty\n", name_of_file);
    return (NULL);
}

t_token *error_on_map(void)
{
    printf("Error\n");
    printf("Somthing is wrong in the map\nPlease read the pdf or ask the owner of this code\n");
    return (NULL);
}

int error_malloc(void)
{
    printf("Error\n");
    printf("Malloc feild to be honest, there is no reason to protect malloc a bro\n");
    return (-1);
}

int error_syntax_no(void)
{
    printf ("Error\n");
    printf ("Please add the path of north texture\n");
    return (1);
}

int error_syntax_so(void)
{
    printf ("Error\n");
    printf ("Please add the path of south texture\n");
    return (1);
}

int error_syntax_we(void)
{
    printf ("Error\n");
    printf ("Please add the path of west texture\n");
    return (1);
}

int error_syntax_ea(void)
{
    printf ("Error\n");
    printf ("Please add the path of east texture\n");
    return (1);
}

int error_syntax_f(void)
{
    printf ("Error\n");
    printf ("Please add the F and his color\n");
    return (1);
}

int error_syntax_c(void)
{
    printf ("Error\n");
    printf ("Please add the C and his color\n");
    return (1);
}

int error_syntax_map(void)
{
    printf ("Error\n");
    printf ("Hi !!! there is no map i have just the info of the map Please add the map\n");
    return (1);
}

void    error_map_lines(void)
{
    printf ("Error\n");
    printf ("Hi !!! LINE EMPTY IN MAP\n");
}

int    error_file_exist(int fd)
{
    close (fd);
    printf ("Error\n");
    printf ("Hi !!! One of textures dosent existe\n");
    return (1);
}