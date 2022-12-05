/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgioia <dgioia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 10:16:30 by dgioia            #+#    #+#             */
/*   Updated: 2022/12/03 12:22:44 by dgioia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	move_to_up_down(t_program *p, int	dir)
{
	p->sprite = new_sprite(p->mlx, '0', p);
	mlx_put_image_to_window(p->mlx, p->window.ref, p->sprite.ref, p->e[0].pos.x * 64 , p->e[0].pos.y * 64);
	mlx_destroy_image(p->mlx, p->sprite.ref);
	if(dir == W)
		p->e[0].pos.y--;
	else if (dir == S)
		p->e[0].pos.y++;
	p->sprite = new_sprite(p->mlx, 'P', p);
	mlx_put_image_to_window(p->mlx, p->window.ref, p->sprite.ref, p->e[0].pos.x * 64, p->e[0].pos.y * 64);
	mlx_destroy_image(p->mlx, p->sprite.ref);

	game_update_score(p);
	//mlx_string_put(p->mlx, p->window.ref, 130, 15, 0x00000, ft_itoa(p->game.moves));
}

void	move_to_left_right(t_program *p, int dir)
{
	p->sprite = new_sprite(p->mlx, '0', p);
	mlx_put_image_to_window(p->mlx, p->window.ref, p->sprite.ref, p->e[0].pos.x * 64 , p->e[0].pos.y * 64);
	mlx_destroy_image(p->mlx, p->sprite.ref);
	if(dir == A)
		p->e[0].pos.x--;
	else if (dir == D)
		p->e[0].pos.x++;
	p->sprite = new_sprite(p->mlx, 'P', p);
	mlx_put_image_to_window(p->mlx, p->window.ref, p->sprite.ref, p->e[0].pos.x * 64, p->e[0].pos.y * 64);
	mlx_destroy_image(p->mlx, p->sprite.ref);
	game_update_score(p);
	//mlx_string_put(p->mlx, p->window.ref, 130, 15, 0x00000, ft_itoa(p->game.moves));
}
