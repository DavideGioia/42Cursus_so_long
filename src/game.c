/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgioia <dgioia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 10:14:48 by dgioia            #+#    #+#             */
/*   Updated: 2022/11/30 10:17:11 by dgioia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	game_init(t_program *p)
{
	p->game.coin_collected = 0;
	p->game.moves = 0;
	p->game.game_complete = 0;
}

int	game_finish(t_program *p)
{
	mlx_clear_window(p->mlx, p->window.ref);
	mlx_destroy_window(p->mlx, p->window.ref);
	ft_free_stuff(p);
	exit(0);

	return (0);
}
