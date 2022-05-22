/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_map_5.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouali <ybouali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 00:48:28 by ybouali           #+#    #+#             */
/*   Updated: 2022/05/13 15:51:52 by ybouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	error_fd(char *name_of_file)
{
	printf("Error\n");
	printf("File with name of [%s] not found\n", name_of_file);
	return (-1);
}

char	**error_map_empty(char *name_of_file)
{
	printf("Error\n");
	printf("File with name of [%s] is is empty\n", name_of_file);
	return (NULL);
}

t_token	*error_map_empty_t(char *name_of_file)
{
	printf("Error\n");
	printf("File with name of [%s] is is empty\n", name_of_file);
	return (NULL);
}

t_token	*error_on_map(void)
{
	printf("Error\n");
	printf("Somthing is wrong in the map\n\
	Please read the pdf or ask the owner of this code\n");
	return (NULL);
}

int	error_malloc(void)
{
	printf("Error\n");
	printf("Malloc feild to be honest, there is no reason to protect \
	malloc a bro\n");
	return (-1);
}

t_token	*error_malloc_t(void)
{
	printf("Error\n");
	printf("Malloc feild to be honest, there is no reason to protect \
	malloc a bro\n");
	return (NULL);
}
