/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgioia <dgioia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 17:26:19 by dgioia            #+#    #+#             */
/*   Updated: 2022/12/03 12:27:38 by dgioia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	map_rectangle_checker (t_map *map)
{
	int	i;
	int	curr_rowlen;

	i = 0;
	while (i < map->n_rows)
	{
		curr_rowlen = ft_strlen(map->map[i]);
		if (map->n_col - 1 != curr_rowlen - 1 && ft_strchr(map->map[i], '\n'))
			return (1);
		if (map->n_col - 1 != curr_rowlen && !ft_strchr(map->map[i], '\n'))
			return (1);
		i++;
	}
	return (0);
}

int	map_walls_checker(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->n_rows)
	{
		if (ft_countchar(map->map[0], '1') != map->n_col - 1)
			return (1);
		if (ft_countchar(map->map[map->n_rows - 1], '1') != map->n_col - 1)
			return (1);
		if (map->map[i][0] != '1' || map->map[i][map->n_col - 2] != '1')
			return (1);
		i++;
	}
	return (0);
}

int	map_invalidchar_checker(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->n_rows)
	{
		j = 0;
		while (j < map->n_col)
		{
			if (map->map[i][j] != '1' && map->map[i][j] != '0' && \
				map->map[i][j] != 'E' && map->map[i][j] != 'P' && \
				map->map[i][j] != 'C' && map->map[i][j] != '\n' && \
				map->map[i][j] != 'S' && map->map[i][j] != '\0')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	map_checker(t_map *map)
{
	if (map_invalidchar_checker(map) != 0)
	{
		ft_printf("ERRORE: la mappa contiene caratteri non validi. \n");
		return (1);
	}
	if (map_rectangle_checker(map) != 0)
	{
		ft_printf("ERRORE: la mappa non é un rettangolo.\n");
		return (1);
	}
	if (map_walls_checker(map) != 0)
	{
		ft_printf("ERRORE: la mappa non é circondata da mura.\n");
		return (1);
	}
	if (map->n_exit < 1 || map->n_coin < 1 || map->n_player < 1)
	{
		ft_printf("ERRORE: non ci sono abbastanza items.\n");
		return (1);
	}
	return (0);
}
