/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgioia <dgioia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 21:18:06 by dgioia            #+#    #+#             */
/*   Updated: 2022/09/19 18:44:44 by dgioia           ###   ########.fr       */
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

void	map_item_checker(s_map *map_ptr)
{
	int	i;
	int j;

	i = 0;
	while (i < map_ptr->rows && map_ptr->map[i])
	{
		j = -1;
		while (map_ptr->map[i][++j] != '\0')
		{
			if (map_ptr->map[i][j] == 'E')
				map_ptr->e++;
			if (map_ptr->map[i][j] == 'P')
				map_ptr->p++;
			if (map_ptr->map[i][j] == 'C')
				map_ptr->c++;
		}
		i++;
	}
}

void	map_error_checker(s_map *map_ptr)
{
	if (map_ptr->e < 1 || map_ptr->p < 1 || map_ptr->c < 1)
		ft_printf("ERRORE: la mappa non ha abbastanza uscite, collezionabili o posizioni di partenza.");
}

char	**map_init(s_map *map_ptr)
{
	int		fd;
	int		i;

	map_ptr->rows = map_row_counter();
	map_ptr->c = 0;
	map_ptr->e = 0;
	map_ptr->p = 0;
	fd = open("maps/map.ber", O_RDONLY);
	map_ptr->map = (char **)malloc(sizeof(char*) * (map_ptr->rows + 1));
	i = 0;
	while (i < map_ptr->rows)
	{
		map_ptr->map[i] = get_next_line(fd);
		i++;
	}
	close(fd);
	return (map_ptr->map);
}

void	map_debugger(s_map *map_ptr)
{
	int i;

	i = 0;
	while(i < map_ptr->rows)
	{
		ft_printf("%s", map_ptr->map[i]);
		i++;
	}
	ft_printf("ROWS: %d\n", map_ptr->rows);
	ft_printf("COLLECTIBLES: %d\n", map_ptr->e);
	ft_printf("MAP EXIT: %d\n", map_ptr->p);
	ft_printf("PLAYERS: %d", map_ptr->c);
}

int	main(void)
{
	s_map	*map_ptr;
	//void	*mlx;
	//void	*mlx_win;

	map_ptr = (s_map *)malloc(sizeof(s_map));
	map_ptr->map = map_init(map_ptr);
	
	map_item_checker(map_ptr);
	map_error_checker(map_ptr);

	map_debugger(map_ptr);
	//mlx = mlx_init();
	//mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello World!");
	//mlx_loop(mlx);
}
