/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgioia <dgioia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 17:27:38 by dgioia            #+#    #+#             */
/*   Updated: 2022/11/11 18:12:35 by dgioia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

t_image	new_sprite(void	*mlx, char *path)
{
	t_image img;
	
	img.ref = mlx_xpm_file_to_image(mlx, path, &img.size.x, &img.size.y);
	img.pixels  = mlx_get_data_addr(img.ref, &img.bits_per_pixel, &img.line_size, &img.endian);

	return (img);
}

void	load_texture(t_map *map, t_program p)
{
	int i;
	int j;

	i = 0;
	while (i < map->n_rows)
	{
		j = 0;
		while (j < map->n_col)
		{
			if (map->map[i][j] == '1')
			{
				p.sprite = new_sprite(p.mlx, "./imgs/wall.xpm");
				p.sprite_pos.x = j * 64;
				p.sprite_pos.y = i * 64;
				mlx_put_image_to_window(p.mlx, p.window.ref, p.sprite.ref, p.sprite_pos.x, p.sprite_pos.y);
			}
			if(map->map[i][j] == '0')
			{
				p.sprite = new_sprite(p.mlx, "./imgs/grass.xpm");
				p.sprite_pos.x = j * 64;
				p.sprite_pos.y = i * 64;
				mlx_put_image_to_window(p.mlx, p.window.ref, p.sprite.ref, p.sprite_pos.x, p.sprite_pos.y);	
			}
			j++;
		}
		i++;
	}
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

	load_texture(map, p);

	mlx_loop(p.mlx);
}

// int	main(void)
// {
// 	t_map	*map;
// 	t_p	p;
// 	void	*mlx_win;
// 	t_data	img;

// 	map = (t_map *)malloc(sizeof(t_map));
// 	// if (map_init(map) == 1)
// 	// {
// 	// 	ft_printf("ERRORE: Caricamento mappa fallito. \n");
// 	// 	return (1);
// 	// }
// 	map_init(map);
// 	map_debugger(map);
	
// 	p.mlx = mlx_init();
// 	p.window = window_init(p.mlx, map);
// 	// if(p.mlx != 0)
// 	// {
// 	// 	p.sprite = new_sprite(p.mlx, "imgs/wall.xmp");
// 	// 	p.sprite_pos.x = 0;
// 	// 	p.sprite_pos.y = 0;
// 	// 	mlx_put_image_to_window(p.mlx, p.window.ref, p.sprite.ref, p.sprite_pos.x, p.sprite_pos.y);
// 	// }
// 	// int img;
// 	// int img_width;
// 	// int img_height;
// 	// img = mlx_xpm_file_to_image(p.mlx, "../imgs/wall.xmp", &img_width, &img_height);
// 	img.img = mlx_new_image(p.mlx, 1920, 1080);
// 	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
// 	my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
// 	ft_printf("prima del seg");

// 	mlx_put_image_to_window(p.mlx, p.window.ref, img.img, 0, 0);
// 	mlx_loop(p.mlx);
// 	return (0);
// }