/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_collection_map.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouali <ybouali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 20:39:50 by ybouali           #+#    #+#             */
/*   Updated: 2022/05/08 14:32:26 by ybouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"



static int     check_in_map(t_lexer *lexer)
{
    if (lexer->c == '1')
        return (1);
    if (lexer->c == '0')
        return (1);
    if (lexer->c == '\n')
        return (1);
    if (lexer->c == '1')
        return (1);
    if (lexer->c == ' ')
        return (1);
    if (check_in("NEWS", lexer->c))
        return (1);
    return (0);
}

t_token *lexer_collection_map(t_lexer *lexer, int type)
{
    char    *value;
    
    value = ft_strdup("");
    while (lexer->c != '\0' && check_in_map(lexer) == 1)
        value = lexer_stock(lexer, value);
    get_one_info(lexer, type);
    return (init_token(type, value));
}
