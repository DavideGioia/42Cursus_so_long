/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgioia <dgioia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 17:27:38 by dgioia            #+#    #+#             */
/*   Updated: 2022/11/28 19:55:59 by dgioia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

t_image	new_sprite(void	*mlx, char map_item)
{
	t_image img;
	
	if	(map_item == 'P')
	{
		ft_printf(" P ");
		img.ref = mlx_xpm_file_to_image(mlx, "./imgs/player.xpm", &img.size.x, &img.size.y);
	}
	else if (map_item == '1')
	{
		ft_printf(" 1 ");
		img.ref = mlx_xpm_file_to_image(mlx, "./imgs/wall.xpm", &img.size.x, &img.size.y);
	}
	else if (map_item == '0')
	{
		ft_printf(" 0 ");
		img.ref = mlx_xpm_file_to_image(mlx, "./imgs/grass.xpm", &img.size.x, &img.size.y);
	}
	
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

int	check_tile(t_program *p, int direction)
{
	if (direction == W)
	{
		ft_printf("%c", p->map->map[0][0]);
		if (p->map->map[0][0] == '1')
			return (1);
	}
	return (0);
}

int	ft_input(int key, t_program *p)
{
	if ((key == W || key == ARR_UP) && check_tile(p, W) != 1)
	{
		p->sprite = new_sprite(p->mlx, '0');
		mlx_put_image_to_window(p->mlx, p->window.ref, p->sprite.ref, p->e[0].pos.x * 64 , p->e[0].pos.y * 64);

		p->sprite = new_sprite(p->mlx, 'P');
		p->e[0].pos.y--;
		mlx_put_image_to_window(p->mlx, p->window.ref, p->sprite.ref, p->e[0].pos.x * 64, p->e[0].pos.y * 64);
	}
	if (key == A || key == ARR_LEFT)
	{
		p->sprite = new_sprite(p->mlx, '0');
		mlx_put_image_to_window(p->mlx, p->window.ref, p->sprite.ref, p->e[0].pos.x * 64 , p->e[0].pos.y * 64);

		p->sprite = new_sprite(p->mlx, 'P');
		p->e[0].pos.x--;
		mlx_put_image_to_window(p->mlx, p->window.ref, p->sprite.ref, p->e[0].pos.x * 64, p->e[0].pos.y * 64);
	}
	if (key == S || key == ARR_DOWN)
	{
		p->sprite = new_sprite(p->mlx, '0');
		mlx_put_image_to_window(p->mlx, p->window.ref, p->sprite.ref, p->e[0].pos.x * 64 , p->e[0].pos.y * 64);

		p->sprite = new_sprite(p->mlx, 'P');
		p->e[0].pos.y++;
		mlx_put_image_to_window(p->mlx, p->window.ref, p->sprite.ref, p->e[0].pos.x * 64, p->e[0].pos.y * 64);
	}
	if (key == D || key == ARR_RIGHT)
	{
		p->sprite = new_sprite(p->mlx, '0');
		mlx_put_image_to_window(p->mlx, p->window.ref, p->sprite.ref, p->e[0].pos.x * 64 , p->e[0].pos.y * 64);

		p->sprite = new_sprite(p->mlx, 'P');
		p->e[0].pos.x++;
		mlx_put_image_to_window(p->mlx, p->window.ref, p->sprite.ref, p->e[0].pos.x * 64, p->e[0].pos.y * 64);
	}
	
	//printf("Key pressed -> %d\n", key);
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

	p.map = &map;
	
	load_texture(map, &p);

	mlx_key_hook(p.window.ref, *ft_input, &p);

	ft_printf("\n MAPPA MAIN: %p", map->map);
	mlx_loop(p.mlx);
}
