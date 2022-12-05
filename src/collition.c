/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collition.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgioia <dgioia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 10:31:02 by dgioia            #+#    #+#             */
/*   Updated: 2022/12/03 12:51:33 by dgioia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	check_block(t_program *p, int dir, int x, int y)
{
	if (dir == W && p->map->map[y - 1][x] == '1')
		return (1);
	if (dir == A && p->map->map[y][x - 1] == '1')
		return (1);
	if (dir == S && p->map->map[y + 1][x] == '1')
		return (1);
	if (dir == D && p->map->map[y][x + 1] == '1')
		return (1);
	return (0);
}
int	check_exit(t_program *p, int dir, int x, int y)
{
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

	return (0);
}

int	check_enemies(t_program *p, int dir, int x, int y)
{
	if (dir == W && p->map->map[y - 1][x] == 'S')
		game_finish(p);
	if (dir == A && p->map->map[y][x - 1] == 'S')
		game_finish(p);
	if (dir == S && p->map->map[y + 1][x] == 'S')
		game_finish(p);
	if (dir == D && p->map->map[y][x + 1] == 'S')
		game_finish(p);
	return (0);
}

int check_coins(t_program *p, int x, int y)
{
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
			mlx_destroy_image(p->mlx, p->sprite.ref);
		}
	}
	return (0);
}
int	collition_checker(t_program *p, int dir)
{
	int	y;
	int	x;

	y = p->e[0].pos.y;
	x = p->e[0].pos.x;

	if (check_block(p, dir, x, y) == 1)
		return (1);
	if (check_exit(p, dir, x, y) == 1)
		return (1);
	check_enemies(p, dir, x, y);
	check_coins(p, x, y);

	return (0);
}
