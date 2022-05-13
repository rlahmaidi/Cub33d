/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_for_syntax_map.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouali <ybouali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 02:43:24 by ybouali           #+#    #+#             */
/*   Updated: 2022/05/10 19:26:27 by ybouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	help_free(t_token *token_head)
{
	t_token	*tmp_token;

	while (token_head)
	{
		tmp_token = token_head;
		token_head = token_head->next;
		tmp_token->next = NULL;
		free(tmp_token->value);
		free(tmp_token);
		tmp_token = NULL;
	}
	token_head = NULL;
}

int     check_double_new_lines(char *lines)
{
    int i;
    int n;

    i = -1;
    while (lines[++i] != '\0')
    {
        if (lines[i] == '\n')
        {
            n = 0;
            while (lines[i] != '\0' && lines[i] == '\n')
            {
                i++;
                n++;
            }
            if (lines[i] == '\0')
                return (0);
            if (n > 1 && lines[i] != '\n')
                return (1);
        }
    }
    
    return (0);
}


t_cub3d     *convert_tokens_to_info_map(t_token **tokens)
{
    t_cub3d     *cub3d;
    t_token     *head_tokens;

    if (!(*tokens))
        return (NULL);
    head_tokens = *tokens;
    cub3d = init_cub3d_info();
    if (!cub3d)
        return (NULL);
    while (head_tokens)
    {
        if (head_tokens->type == NO)
            cub3d->no = ft_strdup(head_tokens->value);
        else if (head_tokens->type == SO)
            cub3d->so = ft_strdup(head_tokens->value);
        else if (head_tokens->type == WE)
            cub3d->we = ft_strdup(head_tokens->value);
        else if (head_tokens->type == EA)
            cub3d->ea = ft_strdup(head_tokens->value);
        else if (head_tokens->type == F)
            cub3d->f = ft_strdup(head_tokens->value);
        else if (head_tokens->type == C)
            cub3d->c = ft_strdup(head_tokens->value);
        else if (head_tokens->type == MAP)
        {
            if (check_double_new_lines(head_tokens->value))
            {
                free_info_map(&cub3d);
                help_free(*tokens);
                error_map_lines();
                return (NULL);
            }
            cub3d->info_of_map = ft_split(head_tokens->value, '\n');
        }
        head_tokens = head_tokens->next;
    }
    help_free(*tokens);
    return (cub3d);
}

void    free_info_map(t_cub3d **info_map)
{
    t_cub3d *info;

    info = *info_map;
    if (info->we != NULL)
        free (info->we);
    if (info->so != NULL)
        free (info->so);
    if (info->no != NULL)
        free (info->no);
    if (info->info_of_map != NULL)
        free_table (info->info_of_map);
    if (info->f != NULL)
        free (info->f);
    if (info->c != NULL)
        free (info->c);
    free (*info_map);
    *info_map = NULL;
}

t_cub3d     *check_for_syntax_map(char *name_of_file)
{
    t_token     *tokens;
    t_cub3d     *cub3d_info;
    
    tokens = lexer_start(name_of_file);
    if (!tokens)
        return (NULL);
    cub3d_info = convert_tokens_to_info_map(&tokens);
    if (!cub3d_info)
        return (NULL);
    if (check_sytax(&cub3d_info) != 0)
    {
        free_info_map(&cub3d_info);
        return (NULL);
    }
    return (cub3d_info);
}