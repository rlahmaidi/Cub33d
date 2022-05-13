/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouali <ybouali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 18:00:54 by ybouali           #+#    #+#             */
/*   Updated: 2021/11/13 08:44:56 by ybouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (lst == NULL)
		return ;
	del(lst->content);
	free(lst);
}

void	delet(void *content)
{
	free(content);
}
/*
#include <stdio.h>
#include <string.h>

int		main(int ac, char **av)
{
	t_list	*node_1 = ft_lstnew(strdup(av[1]));
	t_list	*node_2 = ft_lstnew(strdup(av[2]));
	t_list	*node_3 = ft_lstnew(strdup(av[3]));
	t_list	*node_4 = ft_lstnew(strdup(av[4]));
	t_list	*node_5 = ft_lstnew(strdup(av[5]));
	t_list	*node_6 = ft_lstnew(strdup(av[6]));
	ft_lstadd_front(&node_1, node_2);
	ft_lstadd_front(&node_1, node_3);
	ft_lstadd_front(&node_1, node_4);
	ft_lstadd_front(&node_1, node_5);
	ft_lstadd_front(&node_1, node_6);

	ft_lstdelone(node_4, &delet);
	while (node_1)
	{
		printf ("node result :>%s\n", (char *)node_1->content);
		node_1 = node_1->next;
	}
}
*/