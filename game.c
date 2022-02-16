/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyoulee <jiyoulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 16:55:51 by jiyoulee          #+#    #+#             */
/*   Updated: 2022/02/16 21:45:58 by jiyoulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	keypress(int keycode, t_game *info)
{
	if (keycode == KEY_ESC)
		exit_game(info);
	else if (keycode == KEY_W)
	{
		if (info->p_y > 0 && (*(info->map))[info->p_y - 1][info->p_x] != '1')
			player_w(*(info->map), info);
	}
	else if (keycode == KEY_A)
	{
		if (info->p_x > 0 && (*(info->map))[info->p_y][info->p_x - 1] != '1')
			player_a(*(info->map), info);
	}
	else if (keycode == KEY_S)
	{
		if (info->p_y < info->height && \
			(*(info->map))[info->p_y + 1][info->p_x] != '1')
			player_s(*(info->map), info);
	}
	else if (keycode == KEY_D)
	{
		if (info->p_x < info->width && \
			(*(info->map))[info->p_y][info->p_x + 1] != '1')
			player_d(*(info->map), info);
	}
	return (0);
}

void	gameplay(t_game *info)
{
	mlx_hook(info->win, 2, 0, keypress, info);
	mlx_hook(info->win, 9, 0, map_draw, info);
	mlx_hook(info->win, 17, 0, exit_game, info);
}
