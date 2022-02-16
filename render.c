/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyoulee <jiyoulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 16:53:34 by jiyoulee          #+#    #+#             */
/*   Updated: 2022/02/16 23:31:49 by jiyoulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	img_init(t_game *info)
{
	info->img_backg = mlx_xpm_file_to_image
		(info->mlx, "./sprites/blank.xpm", &info->img_w, &info->img_h);
	info->img_wall = mlx_xpm_file_to_image
		(info->mlx, WALL_DIR, &info->img_w, &info->img_h);
	info->img_player = mlx_xpm_file_to_image
		(info->mlx, "./sprites/closed.xpm", &info->img_w, &info->img_h);
	info->img_collect = mlx_xpm_file_to_image
		(info->mlx, FOOD_DIR, &info->img_w, &info->img_h);
	info->img_exit = mlx_xpm_file_to_image
		(info->mlx, ESCAPE_DIR, &info->img_w, &info->img_h);
	info->img_enemy = mlx_xpm_file_to_image
		(info->mlx, "./sprites/enemy.xpm", &info->img_w, &info->img_h);
}

void	game_init(char **map, t_game *info)
{
	info->mlx = mlx_init();
	info->win = mlx_new_window
		(info->mlx, info->width * SIZE, info->height * SIZE + 80, "so_long");
	info->moves = 0;
	img_init(info);
	map_draw(map, info, 1);
}	
