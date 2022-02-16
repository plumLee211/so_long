/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyoulee <jiyoulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 15:58:44 by jiyoulee          #+#    #+#             */
/*   Updated: 2022/02/14 21:57:50 by jiyoulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

int	exit_game(t_game *info)
{
	mlx_clear_window(info->mlx, info->win);
	info->moves++;
	free_map(*(info->map));
	mlx_destroy_image(info->mlx, info->img_backg);
	mlx_destroy_image(info->mlx, info->img_wall);
	mlx_destroy_image(info->mlx, info->img_player);
	mlx_destroy_image(info->mlx, info->img_collect);
	mlx_destroy_image(info->mlx, info->img_exit);
	mlx_clear_window(info->mlx, info->win);
	mlx_destroy_window(info->mlx, info->win);
	exit(0);
	return (0);
}
