/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_map_4.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouali <ybouali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 00:47:26 by ybouali           #+#    #+#             */
/*   Updated: 2022/05/13 00:55:18 by ybouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	error_expact_3(int i)
{
	printf ("Error\n");
	printf ("Hi expacte a 1 character !\n");
	printf ("help\nlien number [%d] please close the map 1 character\n", i + 1);
	return (1);
}

int	error_expact_4(int i)
{
	printf ("Error\n");
	printf ("Hi expacte a 1 character !\n");
	printf ("help\nlien number [%d] please close the map 1 character\n", i + 1);
	return (1);
}

int	error_len_map(int i)
{
	printf ("Error\n");
	printf ("help\nthe lien number [%d] has not the same \
	length with the authors lines\n", i + 1);
	return (1);
}

int	error_number_of_player(void)
{
	printf ("Error\n");
	printf ("hi in the map it shoud be just one player !!\n");
	return (1);
}

int	error_name_tex(void)
{
	printf("Error\n");
	printf("The name of map shoud be .xpm\n");
	return (1);
}
