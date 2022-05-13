/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_collection_texture.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouali <ybouali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 20:20:37 by ybouali           #+#    #+#             */
/*   Updated: 2022/05/10 17:46:18 by ybouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void    get_one_info(t_lexer *lexer, int type)
{
    if (type == NO)
        lexer->no_bool = 1;
    if (type == SO)
        lexer->so_bool = 1;
    if (type == WE)
        lexer->we_bool = 1;
    if (type == EA)
        lexer->ea_bool = 1;
    if (type == F)
        lexer->f_bool = 1;
    if (type == C)
        lexer->c_bool = 1;
    if (type == MAP)
        lexer->map_bool = 1;
}

t_token *lexer_collection_texture(t_lexer *lexer, int type)
{
    char    *value;

    value = ft_strdup("");
    lexer_advance(lexer);
    lexer_advance(lexer);
    if (type != F && type != C)
        lexer_advance(lexer);
    while (lexer->c != '\0' && lexer->c != '\n')
        value = lexer_stock(lexer, value);
    get_one_info(lexer, type);
    return (init_token(type, value));
}