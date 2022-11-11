/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgioia <dgioia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 21:06:35 by dgioia            #+#    #+#             */
/*   Updated: 2022/11/08 21:28:57 by dgioia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include <fcntl.h>
# include "../libft/includes/libft.h"
# include "../libft/includes/ft_printf.h"
# include "../libft/includes/get_next_line.h"
# include "../mlx_linux/mlx.h"

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

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

typedef struct s_program
{
	void		*mlx;
	t_window	window;
	t_image		sprite;
	t_vector	sprite_pos;
}	t_program;

typedef	struct s_map
{
	char	**map;
	int		n_rows;
	int		n_col;
	int		n_exit;
	int		n_player;
	int		n_collect;
}	t_map;

// map
char	**map_init(t_map *map);
int		map_row_counter(void);
void	map_debugger(t_map *map); // da rimuovere

// map checker
int	map_items_checker(t_map *map);
int	map_checker(t_map *map);

// window
t_window	window_init(void *mlx, t_map *map);


#endif