/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgioia <dgioia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 17:27:38 by dgioia            #+#    #+#             */
/*   Updated: 2022/11/03 04:15:10 by dgioia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	main(void)
{
	t_map	*map;
	void	*mlx;
	void	*mlx_win;

	map = (t_map *)malloc(sizeof(t_map));
	map->map = map_init(map);
	map_debugger(map);
	if (map_error(map) != 0)
		return (1);
	
	// mlx = mlx_init();
	// mlx_win = mlx_new_window(mlx, 1920, 1080, "Peppe la minaccia");
	// if(mlx_win)
	// 	mlx_loop(mlx);
}