/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgioia <dgioia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 02:30:13 by dgioia            #+#    #+#             */
/*   Updated: 2022/12/01 12:02:19 by dgioia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	save_texture_pos(t_program *p, char map_item, int i, int j)
{
	if (map_item == 'P')
	{
		p->e[0].pos.x = j;
		p->e[0].pos.y = i;
	}
	if (map_item == 'E')
	{
		p->e[1].pos.x = j;
		p->e[1].pos.y = i;
	}
}

t_image	new_sprite(void	*mlx, char map_item, t_program *p)
{
	t_image img;
	
	if (map_item == 'C')
		img.ref = mlx_xpm_file_to_image(mlx, "./imgs/coin.xpm", &img.size.x, &img.size.y);
	else if (map_item == 'E' && p->game.coin_collected == p->map->n_coin)
		img.ref = mlx_xpm_file_to_image(mlx, "./imgs/chest_opened.xpm", &img.size.x, &img.size.y);
	else if (map_item == 'E')
		img.ref = mlx_xpm_file_to_image(mlx, "./imgs/chest_closed.xpm", &img.size.x, &img.size.y);
	else if	(map_item == 'P')
		img.ref = mlx_xpm_file_to_image(mlx, "./imgs/player.xpm", &img.size.x, &img.size.y);
	else if (map_item == '1')
		img.ref = mlx_xpm_file_to_image(mlx, "./imgs/wall.xpm", &img.size.x, &img.size.y);
	else if (map_item == '0')
		img.ref = mlx_xpm_file_to_image(mlx, "./imgs/grass.xpm", &img.size.x, &img.size.y);
	
	return (img);
}

void	load_texture(t_map *map, t_program *p)
{
	int i;
	int j;

	i = 0;
	while (i < map->n_rows)
	{
		j = 0;
		while (j < map->n_col - 1)
		{
			p->sprite = new_sprite(p->mlx, map->map[i][j], p);
			save_texture_pos(p, map->map[i][j], j, i);
			p->sprite_pos.x = j * 64;
			p->sprite_pos.y = i * 64;
			mlx_put_image_to_window(p->mlx, p->window.ref, p->sprite.ref, p->sprite_pos.x, p->sprite_pos.y);
			j++;
		}
		i++;
	}
}
