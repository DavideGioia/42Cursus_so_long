/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgioia <dgioia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 21:06:35 by dgioia            #+#    #+#             */
/*   Updated: 2022/11/02 22:33:30 by dgioia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include <fcntl.h>
# include "../libft/includes/libft.h"
# include "../libft/includes/ft_printf.h"
# include "../libft/includes/get_next_line.h"
# include "../mlx_linux/mlx.h"

typedef	struct s_map
{
	char	**map;
	int		rows;
	int		e;
	int		p;
	int		c;
}	s_map;

// map
char	**map_init(s_map *map);
int		map_row_counter(void);
void	map_debugger(s_map *map); // da rimuovere

// map checker
int	map_items_checker(s_map *map);
int	map_error(s_map *map);


#endif