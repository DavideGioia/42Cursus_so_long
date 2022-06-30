/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgioia <dgioia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 22:27:02 by dgioia            #+#    #+#             */
/*   Updated: 2022/06/30 21:09:12 by dgioia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(void)
{
	char	*line;
	int		fd;

	fd = open("maps/map.ber", O_RDONLY);
	line = "";
	while (!line)
	{
		if (!line)
		{
			ft_printf("mappa finita");
			break ;
		}
		line = get_next_line(fd);
		ft_printf("%s", line);
	}
}
