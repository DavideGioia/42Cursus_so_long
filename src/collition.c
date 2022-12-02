/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collition.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgioia <dgioia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 10:31:02 by dgioia            #+#    #+#             */
/*   Updated: 2022/12/01 11:23:06 by dgioia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	check_block(t_program *p, int	dir, char pos)
{
	if (dir == W)
		if (pos == '1' || (pos == 'E' && p->game.game_complete == 0))
			return (1);
	return (0);
}

int	collition_checker(t_program *p, int dir)
{
	int	y;
	int	x;

	y = p->e[0].pos.y;
	x = p->e[0].pos.x;


	//check_block(p, dir, p->map->map[y - 1][x]);
	if (dir == W && p->map->map[y - 1][x] == '1')
		return (1);
	if (dir == A && p->map->map[y][x - 1] == '1')
		return (1);
	if (dir == S && p->map->map[y + 1][x] == '1')
		return (1);
	if (dir == D && p->map->map[y][x + 1] == '1')
		return (1);

	if (dir == W && p->map->map[y - 1][x] == 'E' && p->game.game_complete == 0)
		return (1);
	if (dir == A && p->map->map[y][x - 1] == 'E' && p->game.game_complete == 0)
		return (1);
	if (dir == S && p->map->map[y + 1][x] == 'E' && p->game.game_complete == 0)
		return (1);
	if (dir == D && p->map->map[y][x + 1] == 'E' && p->game.game_complete == 0)
		return (1);

	if (dir == W && p->map->map[y - 1][x] == 'E' && p->game.game_complete == 1)
		game_finish(p);
	if (dir == A && p->map->map[y][x - 1] == 'E' && p->game.game_complete == 1)
		game_finish(p);
	if (dir == S && p->map->map[y + 1][x] == 'E' && p->game.game_complete == 1)
		game_finish(p);
	if (dir == D && p->map->map[y][x + 1] == 'E' && p->game.game_complete == 1)
		game_finish(p);

	if (p->map->map[y][x] == 'C')
	{		
		p->map->map[p->e[0].pos.y][p->e[0].pos.x] = '0';
		p->game.coin_collected++;
		ft_printf("COIN COLLECTED: %d", p->game.coin_collected);
		if (p->game.coin_collected == p->map->n_coin)
		{
			p->game.game_complete = 1;
			p->sprite = new_sprite(p->mlx, 'E', p);
			mlx_put_image_to_window(p->mlx, p->window.ref, p->sprite.ref, p->e[1].pos.y * 64, p->e[1].pos.x * 64);
		}
	}

	return (0);
}
