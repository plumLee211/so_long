/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyoulee <jiyoulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 22:54:59 by jiyoulee          #+#    #+#             */
/*   Updated: 2022/02/14 22:15:29 by jiyoulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_game	new_game(void)
{
	t_game	info;

	info.height = 0;
	info.width = 0;
	info.exit = 0;
	info.player = 0;
	info.collect = 0;
	return (info);
}

int	main(int argc, char **argv)
{
	char	**map;
	t_game	info;

	info = new_game();
	map = check_argument(argc, argv, &info);
	info.map = &map;
	game_init(map, &info);
	gameplay(&info);
	mlx_loop(info.mlx);
	return (0);
}
