/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyoulee <jiyoulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 16:52:16 by jiyoulee          #+#    #+#             */
/*   Updated: 2022/02/14 22:15:38 by jiyoulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	is_val_num(char **map, t_game *info)
{
	int	y;
	int	x;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'P')
				info->player++;
			else if (map[y][x] == 'E')
				info->exit++;
			else if (map[y][x] == 'C')
				info->collect++;
			x++;
		}
		y++;
	}
	if (info->player != 1 || !info->exit || !info->collect)
		print_error("Non valid number of components!");
}

void	is_wall(char **map, t_game *info)
{
	int	y;
	int	x;
	int	len;

	y = 0;
	x = 0;
	while (map[y])
		y++;
	while (map[0][x] && map[y - 1][x])
	{
		if (map[0][x] != '1' || map[y - 1][x] != '1')
			print_error("Map doesn't surrounded by wall!");
		x++;
	}
	y = 1;
	len = info->width;
	while (map[y])
	{
		if (map[y][0] != '1' || map[y][len - 1] != '1')
			print_error("Map doesn't surrounded by wall!");
		y++;
	}
}

void	is_validate(char **map)
{
	int	y;
	int	x;

	y = 0;
	while (map[y])
	{
		if (ft_strlen(map[y]) != ft_strlen(map[0]))
			print_error("Map is not rectangular!");
		x = 0;
		while (map[y][x])
		{
			if (!ft_strchr(VALID_CHAR, map[y][x]))
				print_error("INVALID CHARS!");
			x++;
		}
		y++;
	}
}

char	**check_argument(int argc, char **argv, t_game *info)
{
	int		fd;

	if (argc != 2)
		print_error("Invalid arguments!");
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		print_error("File does not exist!");
	if (ft_strrncmp(argv[1], ".ber", 4))
		print_error("Invalid file type!");
	return (check_error(fd, info));
}

char	**check_error(int fd, t_game *info)
{
	char	*str;
	char	**map;

	str = ft_strdup("");
	map = 0;
	read_map(fd, info, &str);
	map = ft_split(str, '\n');
	free(str);
	is_wall(map, info);
	is_validate(map);
	is_val_num(map, info);
	if (!map)
		print_error("Memory allocation error!");
	return (map);
}
