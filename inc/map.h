/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgioia <dgioia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 21:06:35 by dgioia            #+#    #+#             */
/*   Updated: 2022/06/30 21:18:39 by dgioia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

#include <fcntl.h>
# include "../libft/includes/libft.h"
# include "../libft/includes/ft_printf.h"
# include "../libft/includes/get_next_line.h"
# include "../mlx/mlx.h"

void	read_map(void);

typedef	struct s_map
{
	char	**map;
	int		rows;
	int		e;
	int		p;
	int		c;
}	s_map;

#endif