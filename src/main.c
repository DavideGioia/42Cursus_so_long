/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgioia <dgioia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 17:27:38 by dgioia            #+#    #+#             */
/*   Updated: 2022/11/07 19:39:41 by dgioia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

t_image ft_new_image(void* mlx, int width, int height)
{
	t_image img;

	/* mlx function that creates and returns a pointer
	to an image of the given width and height */
	img.ref = mlx_new_image(mlx, width, height);
	img.size.x = width;
	img.size.x = height;

	/* mlx function that returs a pointer to the first pixel of the given image.
	* ¡Pixels are not stored in a 2D table, just a single char[] array!
	* the fuction also saves in the given pointers:
	*	the bits per pixel (each pixel is usually 4 chars of the array),
	* 	the line size of the pixels array  (the amount of pixels in one line of the image)
	* 	and the endian (info of how the colors are stored) */
	img.pixels = mlx_get_data_addr(img.ref, &img.bits_per_pixel, &img.line_size, &img.endian);

	return (img);
}

t_window	window_init(void *mlx, t_map *map)
{
	t_window	window;
	
	window.screen_size.x = map->n_col * 128;
	window.screen_size.y = map->n_rows * 128;
	window.ref = mlx_new_window(mlx, window.screen_size.x, window.screen_size.y, "TEST");
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

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 100, 100);
	mlx_loop(mlx);
}