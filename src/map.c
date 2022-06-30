/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgioia <dgioia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 21:18:06 by dgioia            #+#    #+#             */
/*   Updated: 2022/06/30 22:08:06 by dgioia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/map.h"

void	read_map(void)
{
	char	*line;
	int		fd;

	line = NULL;
	fd = open("../maps/map.ber", O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		ft_printf("%s", line);
		if (!line)
			break ;
	}
	close(fd);
}

int	main(void)
{

	read_map();
}