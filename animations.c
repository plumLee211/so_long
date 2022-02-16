/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyoulee <jiyoulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 16:51:28 by jiyoulee          #+#    #+#             */
/*   Updated: 2022/02/14 22:17:26 by jiyoulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	up_animation(t_game *info)
{
	if (info->moves % 2 == 1)
		info->img_player = mlx_xpm_file_to_image
			(info->mlx, "./sprites/up_1.xpm", &info->img_w, &info->img_h);
	else
		info->img_player = mlx_xpm_file_to_image
			(info->mlx, "./sprites/up_2.xpm", &info->img_w, &info->img_h);
}

void	down_animation(t_game *info)
{
	if (info->moves % 2 == 1)
		info->img_player = mlx_xpm_file_to_image
			(info->mlx, "./sprites/down_1.xpm", &info->img_w, &info->img_h);
	else
		info->img_player = mlx_xpm_file_to_image
			(info->mlx, "./sprites/down_2.xpm", &info->img_w, &info->img_h);
}

void	left_animation(t_game *info)
{
	if (info->moves % 2 == 1)
		info->img_player = mlx_xpm_file_to_image
			(info->mlx, "./sprites/left_1.xpm", &info->img_w, &info->img_h);
	else
		info->img_player = mlx_xpm_file_to_image
			(info->mlx, "./sprites/left_2.xpm", &info->img_w, &info->img_h);
}

void	right_animation(t_game *info)
{
	if (info->moves % 2 == 1)
		info->img_player = mlx_xpm_file_to_image
			(info->mlx, "./sprites/right_1.xpm", &info->img_w, &info->img_h);
	else
		info->img_player = mlx_xpm_file_to_image
			(info->mlx, "./sprites/right_2.xpm", &info->img_w, &info->img_h);
}

void	display_moves(t_game *info)
{
	char	*str;
	char	*str2;

	str = ft_itoa(info->moves);
	str2 = ft_itoa(info->collect);
	mlx_string_put(info->mlx, info->win, 25, 20, 0xFFFFFF, "MOVES: ");
	mlx_string_put(info->mlx, info->win, 70, 20, 0xFFFFFF, str);
	mlx_string_put(info->mlx, info->win, 100, 20, 0xFFFFFF, str2);
	free(str);
}
