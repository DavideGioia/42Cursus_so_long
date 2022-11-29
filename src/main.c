/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgioia <dgioia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 17:27:38 by dgioia            #+#    #+#             */
/*   Updated: 2022/11/29 02:58:34 by dgioia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	save_element_pos(t_program *p, char map_item, int i, int j)
{
	if (map_item == 'P')
	{
		p->e[0].pos.x = j;
		p->e[0].pos.y = i;
	}
}



void	game_init(t_program *p)
{
	p->game.coin_collected = 0;
	p->game.moves = 0;
	p->game.game_complete = 0;
}

int	main(void)
{
	t_program	p;
	t_map		*map;
	t_window	window;

	p.mlx = mlx_init();

	map = (t_map *)malloc(sizeof(t_map));
	map_init(map);

	p.window = window_init(p.mlx, map);
	p.e = (t_e *) malloc (sizeof(t_e) * 10);

	p.map = map;
	
	game_init(&p);
	
	load_texture(map, &p);

	mlx_key_hook(p.window.ref, *ft_input, &p);

	ft_printf("\n MAPPA MAIN: %p\n", map);
	mlx_loop(p.mlx);
}
