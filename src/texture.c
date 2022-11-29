/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgioia <dgioia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 02:30:13 by dgioia            #+#    #+#             */
/*   Updated: 2022/11/29 02:45:33 by dgioia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

t_image	new_sprite(void	*mlx, char map_item)
{
	t_image img;
	
	if (map_item == 'C')
		img.ref = mlx_xpm_file_to_image(mlx, "./imgs/skeleton.xpm", &img.size.x, &img.size.y);
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
			p->sprite = new_sprite(p->mlx, map->map[i][j]);
			save_element_pos(p, map->map[i][j], j, i);
			p->sprite_pos.x = j * 64;
			p->sprite_pos.y = i * 64;
			mlx_put_image_to_window(p->mlx, p->window.ref, p->sprite.ref, p->sprite_pos.x, p->sprite_pos.y);
			j++;
		}
		i++;
	}
}
