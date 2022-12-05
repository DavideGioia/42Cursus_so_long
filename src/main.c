/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgioia <dgioia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 17:27:38 by dgioia            #+#    #+#             */
/*   Updated: 2022/12/03 11:39:21 by dgioia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	ft_free_stuff(t_program *p)
{
	int	i;

	i = 0;
	while (p->map->map[i] != NULL && i < p->map->n_rows)
	{
		free(p->map->map[i]);
		p->map->map[i] = NULL;
		i++;
	}
	free(p->map->map);
	p->map->map = NULL;
}

void	ft_free_map(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->n_rows)
	{
		free(map->map[i]);
		map->map[i] = NULL;
		i++;
	}
	free(map->map);
	free(map);
}

int	main(void)
{
	t_program	p;
	t_map		*map;
	
	map = (t_map *)malloc(sizeof(t_map));
	p.map = map;

	if (map_uploader(map) == 1)
	{
		ft_free_map(map);
		return (1);
	}
	p.mlx = mlx_init();
	p.window = window_init(p.mlx, map, &p);
	
	p.e = (t_e *) malloc (sizeof(t_e) * 2);
	game_init(&p);
	load_texture(map, &p);
	mlx_key_hook(p.window.ref, *ft_input, &p);
	
	mlx_loop(p.mlx);
	
	return (0);
}
