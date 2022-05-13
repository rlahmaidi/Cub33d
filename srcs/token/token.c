/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouali <ybouali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 20:31:13 by ybouali           #+#    #+#             */
/*   Updated: 2022/04/04 21:05:52 by ybouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

t_token	*init_token(int type, char *value)
{
	t_token	*token;
    
	token = malloc(sizeof(t_token));
	token->type = type;
	token->value = value;
	token->next = NULL;
	return (token);
}

void	push_back_token(t_token **list, t_token *new)
{
	t_token	*head;

	head = *list;
	if (*list == NULL)
		*list = new;
	else
	{
		while (head->next != NULL)
			head = head->next;
		head->next = new;
		new->next = NULL;
	}
}