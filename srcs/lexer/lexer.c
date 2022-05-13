/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouali <ybouali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 20:06:24 by ybouali           #+#    #+#             */
/*   Updated: 2022/05/10 17:41:34 by ybouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

t_token     *lexer_get_next_token(t_lexer *lexer)
{
    while (lexer->c != '\0' && lexer->index < ft_strlen(lexer->contents))
    {
        if ((lexer->c >= 9 && lexer->c <= 13))
            lexer_skep_withespace(lexer);
        if ((lexer->c == 'N' && lexer->contents[lexer->index + 1] == 'O' && \
         lexer->contents[lexer->index + 2] == ' ') && \
         lexer->no_bool == 0)
            return (lexer_collection_texture(lexer, NO));
        else if ((lexer->c == 'S' && lexer->contents[lexer->index + 1] == 'O' && \
        lexer->contents[lexer->index + 2] == ' ') && \
         lexer->so_bool == 0)
            return (lexer_collection_texture(lexer, SO));
        else if ((lexer->c == 'W' && lexer->contents[lexer->index + 1] == 'E' && \
        lexer->contents[lexer->index + 2] == ' ') && \
         lexer->we_bool == 0)
            return (lexer_collection_texture(lexer, WE));
        else if ((lexer->c == 'E' && lexer->contents[lexer->index + 1] == 'A' && \
        lexer->contents[lexer->index + 2] == ' ') && \
         lexer->ea_bool == 0)
            return (lexer_collection_texture(lexer, EA));
        else if ((lexer->c == 'F' && lexer->contents[lexer->index + 1] == ' ') && \
         lexer->f_bool == 0)
            return (lexer_collection_texture(lexer, F));
        else if ((lexer->c == 'C' && lexer->contents[lexer->index + 1] == ' ') && \
         lexer->c_bool == 0)
            return (lexer_collection_texture(lexer, C));
        else if (lexer->map_bool == 0)
            return (lexer_collection_map(lexer, MAP));
        else    
            return (NULL);
    }
    return (NULL);
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