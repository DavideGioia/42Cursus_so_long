/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgioia <dgioia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 21:18:06 by dgioia            #+#    #+#             */
/*   Updated: 2022/07/01 20:19:37 by dgioia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/map.h"

int	map_err_checker(char **map)
{
	int	i;

	i = 0;
	
	while (i <= 0)
	{
		printf("%s", map[i]);
		i++;
	}
	return 0;
}

void	map_init(void)
{
	char	**map;
	char	*line;
	int		fd;
	int		line_count;
	int		i;

	fd = open("maps/map.ber", O_RDONLY);
	line_count = 0;
	line = get_next_line(fd);
	while (line)
	{
		line = get_next_line(fd);
		line_count++;
	}
	free(line);
	close(fd);
	map = (char **)malloc(sizeof(char *) * (line_count + 1));
	fd = open("maps/map.ber", O_RDONLY);
	i = 0;
	while (i++ < line_count)
		map[i] = get_next_line(fd);
	map_err_checker(map);
}

int	main(void)
{
	map_init();
}
