/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgioia <dgioia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 02:28:19 by dgioia            #+#    #+#             */
/*   Updated: 2022/11/29 02:57:53 by dgioia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	tile_checker(t_program *p, int dir)
{
	char	curr;
	char	up;
	char	down;
	char	left;
	char	right;

	curr = p->map->map[p->e[0].pos.y][p->e[0].pos.x];
	up = p->map->map[p->e[0].pos.y - 1][p->e[0].pos.x];
	down = p->map->map[p->e[0].pos.y + 1][p->e[0].pos.x];
	left = p->map->map[p->e[0].pos.y][p->e[0].pos.x - 1];
	right = p->map->map[p->e[0].pos.y][p->e[0].pos.x + 1];

	if (dir == W && up == '1')
		return (1);
	if (dir == A && left == '1')
		return (1);
	if (dir == S && down == '1')
		return (1);
	if (dir == D && right == '1')
		return (1);

	if (curr == 'C')
	{		
		p->map->map[p->e[0].pos.y][p->e[0].pos.x] = '0';
		p->game.coin_collected++;
		ft_printf("COIN COLLECTED: %d", p->game.coin_collected);
		if (p->game.coin_collected == p->map->n_coin)
			exit(0);
	}

	return (0);
}

void	place_grass(t_program *p)
{
	p->sprite = new_sprite(p->mlx, '0');
	mlx_put_image_to_window(p->mlx, p->window.ref, p->sprite.ref, p->e[0].pos.x * 64 , p->e[0].pos.y * 64);
}

void	place_player(t_program *p)
{
	p->sprite = new_sprite(p->mlx, 'P');
	mlx_put_image_to_window(p->mlx, p->window.ref, p->sprite.ref, p->e[0].pos.x * 64, p->e[0].pos.y * 64);
}

int	ft_input(int key, t_program *p)
{
	if ((key == W || key == ARR_UP) && tile_checker(p, W) != 1)
	{
		place_grass(p);
		p->e[0].pos.y--;
		place_player(p);
	}
	if ((key == A || key == ARR_LEFT) && tile_checker(p, A) != 1)
	{
		place_grass(p);
		p->e[0].pos.x--;
		place_player(p);
	}
	if ((key == S || key == ARR_DOWN) && tile_checker(p, S) != 1)
	{
		place_grass(p);
		p->e[0].pos.y++;
		place_player(p);
	}
	if ((key == D || key == ARR_RIGHT) && tile_checker(p, D) != 1)
	{
		place_grass(p);
		p->e[0].pos.x++;
		place_player(p);
	}
	return (0);
}