/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyoulee <jiyoulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 22:09:05 by jiyoulee          #+#    #+#             */
/*   Updated: 2022/02/16 23:28:16 by jiyoulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	player_update_image(char key, t_game *info)
{
	mlx_destroy_image(info->mlx, info->img_player);
	if (key == 'w')
		up_animation(info);
	else if (key == 's')
		down_animation(info);
	else if (key == 'a')
		left_animation(info);
	else if (key == 'd')
		right_animation(info);
}

void	player_w(char **map, t_game *info)
{
	info->p_y -= 1;
	player_update_image('w', info);
	if ((map[info->p_y][info->p_x] == 'E' && info->collect == 0) || \
		map[info->p_y][info->p_x] == 'D')
		exit_game(info);
	else if (map[info->p_y][info->p_x] == '1')
		info->p_y += 1;
	else
	{
		mlx_clear_window(info->mlx, info->win);
		if (map[info->p_y][info->p_x] == 'C')
		{
			info->collect -= 1;
			map[info->p_y][info->p_x] = '0';
		}
		info->moves++;
		map_draw(map, info, 0);
		player_move_draw(info);
	}
}

void	player_a(char **map, t_game *info)
{
	info->p_x -= 1;
	player_update_image('a', info);
	if ((map[info->p_y][info->p_x] == 'E' && info->collect == 0) || \
		map[info->p_y][info->p_x] == 'D')
		exit_game(info);
	else if (map[info->p_y][info->p_x] == '1')
		info->p_x += 1;
	else
	{
		mlx_clear_window(info->mlx, info->win);
		if (map[info->p_y][info->p_x] == 'C')
		{
			info->collect -= 1;
			map[info->p_y][info->p_x] = '0';
		}
		info->moves++;
		map_draw(map, info, 0);
		player_move_draw(info);
	}
}

void	player_s(char **map, t_game *info)
{
	info->p_y += 1;
	player_update_image('s', info);
	if ((map[info->p_y][info->p_x] == 'E' && info->collect == 0) || \
		map[info->p_y][info->p_x] == 'D')
		exit_game(info);
	else if (map[info->p_y][info->p_x] == '1')
		info->p_y -= 1;
	else
	{
		mlx_clear_window(info->mlx, info->win);
		if (map[info->p_y][info->p_x] == 'C')
		{
			info->collect -= 1;
			map[info->p_y][info->p_x] = '0';
		}
		info->moves++;
		map_draw(map, info, 0);
		player_move_draw(info);
	}
	img_draw(info, info->img_player, info->p_x, info->p_y);
}

void	player_d(char **map, t_game *info)
{
	info->p_x += 1;
	player_update_image('d', info);
	if ((map[info->p_y][info->p_x] == 'E' && info->collect == 0) || \
		map[info->p_y][info->p_x] == 'D')
		exit_game(info);
	else if (map[info->p_y][info->p_x] == '1')
		info->p_x -= 1;
	else
	{
		mlx_clear_window(info->mlx, info->win);
		if (map[info->p_y][info->p_x] == 'C')
		{
			info->collect -= 1;
			map[info->p_y][info->p_x] = '0';
		}
		info->moves++;
		map_draw(map, info, 0);
		player_move_draw(info);
	}
}
