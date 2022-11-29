/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgioia <dgioia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 17:27:38 by dgioia            #+#    #+#             */
/*   Updated: 2022/11/29 01:34:00 by dgioia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

t_image	new_sprite(void	*mlx, char map_item)
{
	t_image img;
	
	if	(map_item == 'P')
		img.ref = mlx_xpm_file_to_image(mlx, "./imgs/player.xpm", &img.size.x, &img.size.y);
	else if (map_item == '1')
		img.ref = mlx_xpm_file_to_image(mlx, "./imgs/wall.xpm", &img.size.x, &img.size.y);
	else if (map_item == '0')
		img.ref = mlx_xpm_file_to_image(mlx, "./imgs/grass.xpm", &img.size.x, &img.size.y);
	
	return (img);
}

void	save_element_pos(t_program *p, char map_item, int i, int j)
{
	if (map_item == 'P')
	{
		p->e[0].pos.x = j;
		p->e[0].pos.y = i;
	}
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

int	tile_checker(t_program *p, int dir)
{
	char	up;
	char	down;
	char	left;
	char	right;

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
	return (0);
}

int	ft_input(int key, t_program *p)
{
	if ((key == W || key == ARR_UP) && tile_checker(p, W) != 1)
	{
		p->sprite = new_sprite(p->mlx, '0');
		mlx_put_image_to_window(p->mlx, p->window.ref, p->sprite.ref, p->e[0].pos.x * 64 , p->e[0].pos.y * 64);

		p->sprite = new_sprite(p->mlx, 'P');
		p->e[0].pos.y--;
		mlx_put_image_to_window(p->mlx, p->window.ref, p->sprite.ref, p->e[0].pos.x * 64, p->e[0].pos.y * 64);
	}
	if ((key == A || key == ARR_LEFT) && tile_checker(p, A) != 1)
	{
		p->sprite = new_sprite(p->mlx, '0');
		mlx_put_image_to_window(p->mlx, p->window.ref, p->sprite.ref, p->e[0].pos.x * 64 , p->e[0].pos.y * 64);

		p->sprite = new_sprite(p->mlx, 'P');
		p->e[0].pos.x--;
		mlx_put_image_to_window(p->mlx, p->window.ref, p->sprite.ref, p->e[0].pos.x * 64, p->e[0].pos.y * 64);
	}
	if ((key == S || key == ARR_DOWN) && tile_checker(p, S) != 1)
	{
		p->sprite = new_sprite(p->mlx, '0');
		mlx_put_image_to_window(p->mlx, p->window.ref, p->sprite.ref, p->e[0].pos.x * 64 , p->e[0].pos.y * 64);

		p->sprite = new_sprite(p->mlx, 'P');
		p->e[0].pos.y++;
		mlx_put_image_to_window(p->mlx, p->window.ref, p->sprite.ref, p->e[0].pos.x * 64, p->e[0].pos.y * 64);
	}
	if ((key == D || key == ARR_RIGHT) && tile_checker(p, D) != 1)
	{
		p->sprite = new_sprite(p->mlx, '0');
		mlx_put_image_to_window(p->mlx, p->window.ref, p->sprite.ref, p->e[0].pos.x * 64 , p->e[0].pos.y * 64);

		p->sprite = new_sprite(p->mlx, 'P');
		p->e[0].pos.x++;
		mlx_put_image_to_window(p->mlx, p->window.ref, p->sprite.ref, p->e[0].pos.x * 64, p->e[0].pos.y * 64);
	}
	return (0);
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
	
	load_texture(map, &p);

	mlx_key_hook(p.window.ref, *ft_input, &p);

	ft_printf("\n MAPPA MAIN: %p\n", map);
	mlx_loop(p.mlx);
}
