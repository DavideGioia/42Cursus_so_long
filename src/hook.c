/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgioia <dgioia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 02:28:19 by dgioia            #+#    #+#             */
/*   Updated: 2022/12/02 09:58:33 by dgioia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	ft_input(int key, t_program *p)
{
	if ((key == W || key == ARR_UP) && collition_checker(p, W) != 1)
		move_to_up_down(p, W);
	if ((key == A || key == ARR_LEFT) && collition_checker(p, A) != 1)
		move_to_left_right(p, A);
	if ((key == S || key == ARR_DOWN) && collition_checker(p, S) != 1)
		move_to_up_down(p, S);
	if ((key == D || key == ARR_RIGHT) && collition_checker(p, D) != 1)
		move_to_left_right(p, D);

	return (0);
}