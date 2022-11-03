/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgioia <dgioia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 21:18:06 by dgioia            #+#    #+#             */
/*   Updated: 2022/11/03 02:57:13 by dgioia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	map_row_counter(void)
{
	int		fd;
	int		c;
	char	*row;

	fd = open("maps/map.ber", O_RDONLY);
	c = 0;
	row = get_next_line(fd);
	while (row)
	{
		row = get_next_line(fd);
		c++;
	}
	free(row);
	close(fd);
	return (c);
}

// si occupa di leggere la mappa e contare quanti item ci sono all'interno
char	**map_init(s_map *map)
{
	int		i;
	int		fd;
	char	*row;

	map->rows = map_row_counter();
	map->c = 0;
	map->e = 0;
	map->p = 0;
	fd = open("maps/map.ber", O_RDONLY);
	map->map = (char **)malloc (sizeof (char *) * (map->rows + 1));
	i = 0;
	while (i < map->rows)
	{
		row = get_next_line(fd);
		map->map[i] = row;
		map->e += ft_countchar(row, 'E');
		map->p += ft_countchar(row, 'P');
		map->c += ft_countchar(row, 'C');
		i++;
	}
	close(fd);
	return (map->map);
}

// da rimuovere a fine progeto, serve per controllare la mappa
void	map_debugger(s_map *map)
{
	int i;

	i = 0;
	while(i < map->rows)
	{
		ft_printf("%s", map->map[i]);
		i++;
	}
	ft_printf("\nROWS: %d\n", map->rows);
	ft_printf("COLLECTIBLES: %d\n", map->c);
	ft_printf("MAP EXIT: %d\n", map->e);
	ft_printf("PLAYERS: %d\n", map->p);
}
