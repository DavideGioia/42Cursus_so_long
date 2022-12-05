/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgioia <dgioia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 10:14:48 by dgioia            #+#    #+#             */
/*   Updated: 2022/12/03 12:21:59 by dgioia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	game_update_score(t_program *p)
{
	static int	score;
	char		*score_s;

	score++;
	score_s = ft_itoa(score);
	//mlx_put_image_to_window(p->mlx, p->window.ref, p->e[0].sprite.ptr, 128, 0);
	mlx_string_put(p->mlx, p->window.ref, 130, 15, 0xFF0000, score_s);
	free(score_s);
}

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
