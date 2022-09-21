/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgioia <dgioia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 21:18:06 by dgioia            #+#    #+#             */
/*   Updated: 2022/09/21 15:50:56 by dgioia           ###   ########.fr       */
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

void	map_checklayout(s_map *map,	char *row)
{
	map->e += ft_countchar(row, 'E');
	map->p += ft_countchar(row, 'P');
	map->c += ft_countchar(row, 'C');

}

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
		map_checklayout(map, row);
		i++;
	}
	close(fd);
	return (map->map);
}

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
	ft_printf("PLAYERS: %d", map->p);
}

int	main(void)
{
	s_map	*map;
	//void	*mlx;
	//void	*mlx_win;

	map = (s_map *)malloc(sizeof(s_map));
	map->map = map_init(map);

	map_debugger(map);
	//mlx = mlx_init();
	//mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello World!");
	//mlx_loop(mlx);
}