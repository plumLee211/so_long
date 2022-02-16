/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyoulee <jiyoulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 17:35:26 by jiyoulee          #+#    #+#             */
/*   Updated: 2022/02/16 15:39:00 by jiyoulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./mlx/mlx.h"
# include "./mlx_beta/mlx.h"
# include "./utils.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

typedef struct s_game
{
	void	*mlx;
	void	*win;
	void	*img_backg;
	void	*img_wall;
	void	*img_player;
	void	*img_collect;
	void	*img_exit;
	void	*img_enemy;
	int		img_w;
	int		img_h;
	int		height;
	int		width;
	int		collect;
	int		player;
	int		exit;
	int		p_x;
	int		p_y;
	int		moves;
	char	***map;
}	t_game;

# define WALL_DIR	"./sprites/wall.xpm"
# define FOOD_DIR	"./sprites/food.xpm"
# define ESCAPE_DIR	"./sprites/escape.xpm"
# define BLANK_DIR	"./sprites/blank.xpm"
# define GHOST		"./sprites/ghost.xpm"

# define VALID_CHAR	"01CEPD\n"

# define SIZE		32

# define KEY_ESC    53
# define KEY_W      13
# define KEY_A      0
# define KEY_S      1
# define KEY_D      2

void	up_animation(t_game *info);
void	down_animation(t_game *info);
void	left_animation(t_game *info);
void	right_animation(t_game *info);
void	display_moves(t_game *info);

void	img_draw(t_game *info, void *image, int x, int y);
void	player_draw(t_game *info, void *image, int x, int y);
void	player_move_draw(t_game *info);
void	exit_draw(t_game *info, int x, int y);
int		map_draw(char **map, t_game *info, int first);

void	is_val_num(char **map, t_game *info);
void	is_wall(char **map, t_game *info);
void	is_validate(char **map);
char	**check_argument(int argc, char **argv, t_game *info);
char	**check_error(int fd, t_game *info);

void	free_map(char **map);
int		exit_game(t_game *info);

void	gameplay(t_game *info);

char	*ft_(char *s1, char *s2);
int		print_error(char *txt);
void	read_map(int fd, t_game *info, char **str);
void	check_map(char *line, t_game *info);

void	player_w(char **map, t_game *info);
void	player_a(char **map, t_game *info);
void	player_s(char **map, t_game *info);
void	player_d(char **map, t_game *info);

void	game_init(char **map, t_game *game);

#endif