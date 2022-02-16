/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyoulee <jiyoulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 15:57:23 by jiyoulee          #+#    #+#             */
/*   Updated: 2022/02/16 15:37:07 by jiyoulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	img_draw(t_game *info, void *image, int x, int y)
{
	mlx_put_image_to_window
		(info->mlx, info->win, image, x * SIZE, y * SIZE + 32);
}

void	player_draw(t_game *info, void *image, int x, int y)
{
	info->p_x = x;
	info->p_y = y;
	img_draw(info, image, x, y);
}

void	player_move_draw(t_game *info)
{
	img_draw(info, info->img_player, info->p_x, info->p_y);
}

void	exit_draw(t_game *info, int x, int y)
{
	if (info->collect == 0)
	{
		mlx_destroy_image(info->mlx, info->img_exit);
		info->img_exit = mlx_xpm_file_to_image
			(info->mlx, ESCAPE_DIR, &info->img_w, &info->img_h);
	}
	img_draw(info, info->img_exit, x, y);
}

int	map_draw(char **map, t_game *info, int first)
{
	int	y;
	int	x;

	y = -1;
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
		{
			if (map[y][x] == '1')
				img_draw(info, info->img_wall, x, y);
			else if (map[y][x] == '0')
				img_draw(info, info->img_backg, x, y);
			else if (map[y][x] == 'P' && first == 1)
				player_draw(info, info->img_player, x, y);
			else if (map[y][x] == 'C')
				img_draw(info, info->img_collect, x, y);
			else if (map[y][x] == 'E')
				exit_draw(info, x, y);
			else if (map[y][x] == 'D')
				img_draw(info, info->img_enemy, x, y);
		}
	}
	display_moves(info);
	return (0);
}
