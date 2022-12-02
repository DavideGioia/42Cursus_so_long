/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgioia <dgioia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 10:16:30 by dgioia            #+#    #+#             */
/*   Updated: 2022/12/01 12:00:21 by dgioia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	move_to_up_down(t_program *p, int	dir)
{
	p->sprite = new_sprite(p->mlx, '0', p);
	mlx_put_image_to_window(p->mlx, p->window.ref, p->sprite.ref, p->e[0].pos.x * 64 , p->e[0].pos.y * 64);
	if(dir == W)
		p->e[0].pos.y--;
	else if (dir == S)
		p->e[0].pos.y++;
	p->sprite = new_sprite(p->mlx, 'P', p);
	mlx_put_image_to_window(p->mlx, p->window.ref, p->sprite.ref, p->e[0].pos.x * 64, p->e[0].pos.y * 64);

	p->game.moves++;
	mlx_string_put(p->mlx, p->window.ref, 130, 15, 0x00000, ft_itoa(p->game.moves));
}

void	move_to_left_right(t_program *p, int dir)
{
	p->sprite = new_sprite(p->mlx, '0', p);
	mlx_put_image_to_window(p->mlx, p->window.ref, p->sprite.ref, p->e[0].pos.x * 64 , p->e[0].pos.y * 64);
	if(dir == A)
		p->e[0].pos.x--;
	else if (dir == D)
		p->e[0].pos.x++;
	p->sprite = new_sprite(p->mlx, 'P', p);
	mlx_put_image_to_window(p->mlx, p->window.ref, p->sprite.ref, p->e[0].pos.x * 64, p->e[0].pos.y * 64);

	p->game.moves++;
	mlx_string_put(p->mlx, p->window.ref, 130, 15, 0x00000, ft_itoa(p->game.moves));
}
