/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouali <ybouali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 20:06:24 by ybouali           #+#    #+#             */
/*   Updated: 2022/05/13 16:56:19 by ybouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int     lexer_check(t_lexer *lexer, char c_f, char c_s)
{
    if (
        lexer->c == c_f && \
        lexer->contents[lexer->index + 1] == c_s && \
        lexer->contents[lexer->index + 2] == ' '
    )
    {
        if (c_f == 'N' && lexer->no_bool == 0)
            return (1);
        if (c_f == 'S' && lexer->so_bool == 0)
            return (1);
        if (c_f == 'W' && lexer->we_bool == 0)
            return (1);
        if (c_f == 'E' && lexer->ea_bool == 0)
            return (1);
    }
    return (0);
}

t_token     *help(t_lexer *lexer)
{
    if (lexer_check(lexer, 'N', 'O'))
        return (lexer_collection_texture(lexer, NO));
    else if (lexer_check(lexer, 'S', 'O'))
        return (lexer_collection_texture(lexer, SO));
    else if (lexer_check(lexer, 'W', 'E'))
        return (lexer_collection_texture(lexer, WE));
    else if (lexer_check(lexer, 'E', 'A'))
        return (lexer_collection_texture(lexer, EA));
    else if ((lexer->c == 'F' && \
        lexer->contents[lexer->index + 1] == ' ') && \
         lexer->f_bool == 0)
            return (lexer_collection_texture(lexer, F));
        else if ((lexer->c == 'C' && \
        lexer->contents[lexer->index + 1] == ' ') && \
         lexer->c_bool == 0)
            return (lexer_collection_texture(lexer, C));
        else if (lexer->map_bool == 0)
            return (lexer_collection_map(lexer, MAP));
    return (NULL);
}

t_token     *lexer_get_next_token(t_lexer *lexer)
{
    t_token *token;
    
    while (lexer->c != '\0' && lexer->index < ft_strlen(lexer->contents))
    {
        if ((lexer->c >= 9 && lexer->c <= 13))
            lexer_skep_withespace(lexer);
        token = help(lexer);
        if (token == NULL)
            return (NULL);
        if (token != NULL)
            return (token);
    }
    return (NULL);
}

t_token *lexer_help(char *name_of_map)
{
    t_lexer     *lexer;
    t_token     *token_new;
    char        *content_for_lexer;

    content_for_lexer = check_map(name_of_map);
    if (!content_for_lexer)
        return (NULL);
    lexer = lexer_init(content_for_lexer);
    if (!lexer)
    {
        error_malloc();
        return (NULL);
    }
    token_new = lexer_get_next_token(lexer);
    if (!token_new || token_new->value[0] == '\0')
    {
        error_map_empty(name_of_map);
        return (NULL);
    }
    return (token_new);
}

t_token *lexer_start(char *name_of_map)
{
    t_lexer     *lexer;
    t_token     *tokens = NULL;
    t_token     *token_new;
    char        *content_for_lexer;

    content_for_lexer = check_map(name_of_map);
    if (!content_for_lexer)
        return (NULL);
    lexer = lexer_init(content_for_lexer);
    if (!lexer)
        return (error_malloc_t()); 
    token_new = lexer_get_next_token(lexer);
    if (!token_new || token_new->value[0] == '\0')
        return (error_map_empty_t(name_of_map));
    while (token_new != NULL)
    {
        push_back_token(&tokens, token_new);
        token_new = lexer_get_next_token(lexer);
    }
    if (token_new == NULL && lexer->c != '\0')
        return (error_on_map());
    free (lexer->contents);
    free (lexer);
    return (tokens);
}