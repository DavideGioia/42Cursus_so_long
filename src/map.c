/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgioia <dgioia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 21:18:06 by dgioia            #+#    #+#             */
/*   Updated: 2022/11/03 04:20:15 by dgioia           ###   ########.fr       */
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

// legge la mappa e inizializza le informazioni base
char	**map_init(t_map *map)
{
	int		i;
	int		fd;
	char	*row;

	map->n_rows = map_row_counter();
	map->n_collect = 0;
	map->n_exit = 0;
	map->n_player = 0;
	fd = open("maps/map.ber", O_RDONLY);
	map->map = (char **)malloc (sizeof (char *) * (map->n_rows + 1));
	i = 0;
	while (i < map->n_rows)
	{
		row = get_next_line(fd);
		map->map[i] = row;
		map->n_exit += ft_countchar(row, 'E');
		map->n_player += ft_countchar(row, 'P');
		map->n_collect += ft_countchar(row, 'C');
		i++;
	}
	map->n_col = ft_strlen(map->map[0]);
	close(fd);
	return (map->map);
}

// da rimuovere a fine progeto, serve per controllare la mappa
void	map_debugger(t_map *map)
{
	int i;

	i = 0;
	while(i < map->n_rows)
	{
		ft_printf("%s", map->map[i]);
		i++;
	}
	ft_printf("\nROWS: %d\n", map->n_rows);
	ft_printf("COLLECTIBLES: %d\n", map->n_collect);
	ft_printf("MAP EXIT: %d\n", map->n_exit);
	ft_printf("PLAYERS: %d\n", map->n_player);
}
