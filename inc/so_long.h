/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgioia <dgioia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 21:06:35 by dgioia            #+#    #+#             */
/*   Updated: 2022/11/04 21:52:24 by dgioia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include <fcntl.h>
# include "../libft/includes/libft.h"
# include "../libft/includes/ft_printf.h"
# include "../libft/includes/get_next_line.h"
# include "../mlx_linux/mlx.h"

typedef struct s_program
{
	void	*mlx_ptr;
	void	*window;
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
int	map_checker(t_map *map, char *row, int is_last);


#endif