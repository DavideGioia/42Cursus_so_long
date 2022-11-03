/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgioia <dgioia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 17:26:19 by dgioia            #+#    #+#             */
/*   Updated: 2022/11/03 03:14:34 by dgioia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	map_rectangle_checker (s_map *map)
{
	int	i;
	int	fir_rowlen;
	int	curr_rowlen;

	i = 0;
	fir_rowlen = ft_strlen(map->map[0]) - 1;
	while (i < map->rows)
	{
		curr_rowlen = ft_strlen(map->map[i]);
		if (fir_rowlen && ((fir_rowlen != curr_rowlen - 1 && \
			ft_strchr(map->map[i], '\n')) || (fir_rowlen != curr_rowlen && \
			!ft_strchr(map->map[i], '\n'))))
			return (1);
		i++;
	}
	return (0);
}

int	map_walls_checker(s_map *map)
{
	return (0);
}

int	map_error(s_map *map)
{
	if (map_rectangle_checker(map) != 0)
	{
		ft_printf("ERRORE: la mappa non é un rettangolo.\n");
		return (1);
	}
	if (map->e < 1 || map->c < 1 || map->p < 1)
	{
		ft_printf("ERRORE: non ci sono abbastanza items. Controlla la mappa.\n");
		return (1);
	}
	return (0);
}