/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgioia <dgioia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 21:06:35 by dgioia            #+#    #+#             */
/*   Updated: 2022/12/03 11:01:34 by dgioia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include <fcntl.h>
# include "../libft/includes/libft.h"
# include "../libft/includes/ft_printf.h"
# include "../libft/includes/get_next_line.h"
# include "../mlx_linux/mlx.h"

# define W 119
# define A 97
# define S 115
# define D 100

# define ARR_UP 65362
# define ARR_LEFT 65361
# define ARR_DOWN 65364
# define ARR_RIGHT 65363

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_vector
{
	int	x;
	int	y;
}	t_vector;

typedef struct s_window
{
	void	*ref;
	t_vector	screen_size;
}	t_window;

typedef struct s_image
{
	void		*ref;
	void		**list;
	t_vector	size;
	char		*pixels;
	int			bits_per_pixel;
	int			line_size;
	int			endian;
}	t_image;

typedef struct s_e {
	t_vector	pos;
	t_image		sprite;
}				t_e;

typedef	struct s_game
{
	int	game_complete;
	int	coin_collected;
	int	moves;
}	t_game;

typedef	struct s_map
{
	char	**map;
	int		n_rows;
	int		n_col;
	int		n_exit;
	int		n_player;
	int		n_coin;
}	t_map;

typedef struct s_program
{
	void		*mlx;
	t_map		*map;
	t_window	window;
	t_image		sprite;
	t_vector	sprite_pos;
	t_e			*e;
	t_game		game;
}	t_program;

void	ft_free_stuff(t_program *p);

//collition 
// void	check_block(int	dir, char	tile);
int	collition_checker(t_program *p, int dir);

// game
void	game_init(t_program *p);
int	game_finish(t_program *p);
void	game_update_score(t_program *p);

// move
void	place_grass(t_program *p);
void	place_player(t_program *p);
void	move_to_up_down(t_program *p, int	dir);
void	move_to_left_right(t_program *p, int dir);

// map
int		map_uploader(t_map *map);
int		map_row_counter(void);
void	map_debugger(t_map *map); // da rimuovere

// map checker
int	map_items_checker(t_map *map);
int	map_checker(t_map *map);

// window
t_window	window_init(void *mlx, t_map *map, t_program *p);

// hook
int	ft_input(int key, t_program *p);
int	tile_checker(t_program *p, int dir);

//texture
t_image	new_sprite(void	*mlx, char map_item, t_program *p);
void	load_texture(t_map *map, t_program *p);

#endif