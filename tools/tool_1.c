/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouali <ybouali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 18:10:00 by ybouali           #+#    #+#             */
/*   Updated: 2022/05/10 23:34:31 by ybouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int strlen_with(char *s, int c)
{
    int i;

    i = 0;
    while (s[i] && s[i] != (char)c)
        i++;
    if (s[i] == (char)c)
        return (i);
    return (0);
}

void    display_info_map(char **info)
{
    int     i;
    
    i = 0;
    while (info[i])
    {
        printf ("%s", info[i]);
        i++;
    }
}

void    display_tokens(t_token **tokens)
{
    t_token *token;
    
    token = *tokens;
    while (token)
    {
        printf ("\n\n");
        printf ("\nTYPE[%d]\nVALUE[%s]\n\n", token->type, token->value);
        token = token->next;
    }
}

void    display_cub3d_info(t_cub3d **cub3d)
{
    t_cub3d *cub3d_info;
    int     i;

    i = -1;
    cub3d_info = *cub3d;
    printf ("\033[0;34m\n------------------------------------------------------\n\033[0;37m");
    printf ("\033[0;34mNO::::::(%s)\n\033[0;37m", cub3d_info->no);
    printf ("\033[0;34mSO::::::(%s)\n\033[0;37m", cub3d_info->so);
    printf ("\033[0;34mWE::::::(%s)\n\033[0;37m", cub3d_info->we);
    printf ("\033[0;34mEA::::::(%s)\n\033[0;37m", cub3d_info->ea);
    printf ("\033[0;34mF::::::(%s) [%d]\n\033[0;37m", cub3d_info->f, cub3d_info->floor_c);
    printf ("\033[0;34mC::::::(%s) [%d]\n\033[0;37m", cub3d_info->c, cub3d_info->ceilling_c);
    printf ("\033[0;34m------------------------------------------------------\n\033[0;37m");
    printf ("\033[0;33m{INFO OF MAP 2d with number of lien}\n\033[0;37m");
    while (cub3d_info->info_of_map[++i])
        printf ("\033[0;31m[%d]:::[%s] \033[0;37m\n", i, cub3d_info->info_of_map[i]);
}

void    display_string(char *str, char *stri, char *strin)
{
    if (str != NULL)
    {
        printf("(%s)", str);
        // free (str);
    }
    printf  ("\n*************************************************************************************\n");
    if (stri != NULL)
    {
        printf("[%s]", stri);
        free (stri);
    }
    if (strin != NULL)
    {
        printf("[%s]", strin);
        // free (strin);
    }
    printf("\n");
}

void    free_table(char **table)
{
    int     i;

    i = 0;
    if (table != NULL)
    {
        while (table[i])
        {
            free (table[i]);
            i++;
        }
        free (table);
    }
}

char    *ft_table_dup_to_string(char **info_of_map)
{
    int     i;
    char    *map_info;
    char    *tmp;
    
    i = -1;
    map_info = ft_strdup("");
    if (!map_info)
    {
        error_malloc();
        return (NULL);
    }
    while (info_of_map[++i])
    {
        tmp = ft_strjoin(map_info, info_of_map[i]);
        if (!tmp)
        {
            error_malloc();
            return (NULL);
        }
        free (map_info);
        map_info = tmp;
    }
    free_table(info_of_map);
    return (map_info);
}