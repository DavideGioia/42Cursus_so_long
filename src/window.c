/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgioia <dgioia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 03:23:11 by dgioia            #+#    #+#             */
/*   Updated: 2022/11/08 20:22:18 by dgioia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

t_window	window_init(void *mlx, t_map *map)
{
	t_window	window;

	window.ref = mlx_new_window(mlx, (map->n_col - 1) * 64, map->n_rows * 64, "Test");
	window.screen_size.x = (map->n_col - 1) * 64;
	window.screen_size.y = map->n_rows * 64;

	mlx_hook(window.ref, 17, 0, exit, 0);

	return (window);
}