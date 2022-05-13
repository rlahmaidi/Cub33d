/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouali <ybouali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 17:03:16 by ybouali           #+#    #+#             */
/*   Updated: 2022/05/08 13:46:14 by ybouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

t_lexer     *lexer_init(char *content)
{
    t_lexer *lexer;
    
	if (!content)
		return (NULL);
    lexer = malloc(sizeof(t_lexer));
	if (!lexer)
		return (NULL);
    lexer->index = 0;
    lexer->contents = content;
    lexer->c = lexer->contents[lexer->index];
	lexer->no_bool = 0;
	lexer->so_bool = 0;
	lexer->we_bool = 0;
	lexer->ea_bool = 0;
	lexer->f_bool = 0;
	lexer->c_bool = 0;
	lexer->map_bool = 0;
	lexer->one_starting_position_bool = 0;
	return (lexer);
}

void        lexer_advance(t_lexer *lexer)
{
    if (lexer->c != '\0' && lexer->index < ft_strlen(lexer->contents))
    {
        lexer->index += 1;
        lexer->c = lexer->contents[lexer->index];
    }
}

void        lexer_skep_withespace(t_lexer *lexer)
{
    while ((lexer->c >= 9 && lexer->c <= 13))
		lexer_advance(lexer);
}

char	*lexer_stock(t_lexer *lexer, char *value)
{
	char	*tmp;
	char	*c;

	if (lexer->c != '\0')
	{
		c = malloc(2);
		if (!c)
			return (NULL);
		c[0] = lexer->c;
		c[1] = '\0';
		tmp = ft_strjoin(value, c);
		free(value);
		free(c);
		value = tmp;
		lexer_advance(lexer);
	}
	return (value);
}