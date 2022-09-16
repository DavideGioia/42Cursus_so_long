/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgioia <dgioia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 21:18:06 by dgioia            #+#    #+#             */
/*   Updated: 2022/09/16 19:33:59 by dgioia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/map.h"

int	line_counter(void)
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

char	**map_init(s_map *map_ptr)
{
	int		fd;
	int		i;

	map_ptr->rows = line_counter();
	printf("%d", map_ptr->rows);
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

int	main(void)
{
	s_map	*map_ptr;

	map_ptr = (s_map *)malloc(sizeof(s_map));
	map_ptr->map = map_init(map_ptr);
}
