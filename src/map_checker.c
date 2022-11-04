/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgioia <dgioia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 17:26:19 by dgioia            #+#    #+#             */
/*   Updated: 2022/11/04 22:09:54 by dgioia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	map_rectangle_checker (t_map *map, char *row)
{
	int	curr_rowlen;

	curr_rowlen = ft_strlen(row);
	if (map->n_col - 1 != curr_rowlen - 1 && ft_strchr(row, '\n'))
		return (1);
	else if (map->n_col - 1 != curr_rowlen && !ft_strchr(row, '\n'))
		return (1);
	return (0);
}

int	map_walls_checker(t_map *map, char *row, int is_last)
{
	
	if (row[0] != '1' || row[map->n_col - 2] != '1')
		return (1);
	if (is_last)
		if (ft_countchar(row, '1') == map->n_col - 2)
			return (1);
	return (0);
}

int	map_invalidchar_checker(t_map *map, char *row)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->n_col)
	{
		if (row[i] != '1' && row[i] != '0' && \
			row[i] != 'E' && row[i] != 'P' && \
			row[i] != 'C' && row[i] != '\n' && \
			row[i] != '\0')
			return (1);
		i++;
	}
	return (0);
}

int	map_checker(t_map *map, char *row, int is_last)
{
	if (map_invalidchar_checker(map, row) != 0)
	{
		ft_printf("ERRORE: la mappa contiene caratteri non validi. \n");
		return (1);
	}
	if (map_rectangle_checker(map, row) != 0)
	{
		ft_printf("ERRORE: la mappa non é un rettangolo.\n");
		return (1);
	}
	if (map_walls_checker(map, row, is_last) != 0)
	{
		ft_printf("ERRORE: la mappa non é circondata da mura.\n");
		return (1);
	}
	// ottimizzare questo check
	if (map->n_exit < 1 || map->n_collect < 1 || map->n_player < 1)
	{
		ft_printf("ERRORE: non ci sono abbastanza items.\n");
		return (1);
	}
	return (0);
}
