/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgioia <dgioia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 17:27:38 by dgioia            #+#    #+#             */
/*   Updated: 2022/11/08 03:19:43 by dgioia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

t_window	window_init(void *mlx, t_map *map)
{
	t_window	window;

	window.ref = mlx_new_window(mlx, (map->n_col - 1) * 64, map->n_rows * 64, "Test");
	window.screen_size.x = (map->n_col - 1) * 64;
	window.screen_size.y = map->n_rows * 64;

	mlx_hook(window.ref, 17, 0, exit, 0);

	return (window);
}

t_image	new_sprite(void	*mlx, char	*img_path)
{
	t_image img;
	
	img.ref = mlx_xpm_file_to_image(mlx, img_path, &img.size.x, &img.size.y);

	return (img);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	main(void)
{
	t_program	program;
	t_map		*map;
	t_window	window;

	program.mlx = mlx_init();

	map = (t_map *)malloc(sizeof(t_map));
	map_init(map);
	
	program.window = window_init(program.mlx, map);
	
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
				program.sprite = new_sprite(program.mlx, "imgs/wall.xmp");
				program.sprite_pos.x = j * 64;
				program.sprite_pos.y = i * 64;
				mlx_put_image_to_window(program.mlx, program.window.ref, program.sprite.ref, program.sprite_pos.x, program.sprite_pos.y);
			}
			j++;
		}
		i++;
	}
	mlx_loop(program.mlx);
}

// int	main(void)
// {
// 	t_map	*map;
// 	t_program	program;
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
	
// 	program.mlx = mlx_init();
// 	program.window = window_init(program.mlx, map);
// 	// if(program.mlx != 0)
// 	// {
// 	// 	program.sprite = new_sprite(program.mlx, "imgs/wall.xmp");
// 	// 	program.sprite_pos.x = 0;
// 	// 	program.sprite_pos.y = 0;
// 	// 	mlx_put_image_to_window(program.mlx, program.window.ref, program.sprite.ref, program.sprite_pos.x, program.sprite_pos.y);
// 	// }
// 	// int img;
// 	// int img_width;
// 	// int img_height;
// 	// img = mlx_xpm_file_to_image(program.mlx, "../imgs/wall.xmp", &img_width, &img_height);
// 	img.img = mlx_new_image(program.mlx, 1920, 1080);
// 	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
// 	my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
// 	ft_printf("prima del seg");

// 	mlx_put_image_to_window(program.mlx, program.window.ref, img.img, 0, 0);
// 	mlx_loop(program.mlx);
// 	return (0);
// }