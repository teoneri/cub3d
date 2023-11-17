/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfai <lfai@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 15:21:32 by mneri             #+#    #+#             */
/*   Updated: 2023/11/17 15:39:16 by lfai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H

# include <unistd.h>
# include <stdio.h>
# include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
# include "../mlx/mlx.h"
# include "../Libft/libft.h"

# define ESC_KEY 53
# define UP_KEY 126
# define DOWN_KEY 125
# define LEFT_KEY 123
# define RIGHT_KEY 124
# define W_KEY 13
# define A_KEY 0
# define S_KEY 1
# define D_KEY 2

typedef struct s_controls
{
	int	look_left;
	int	look_right;
	int	look_up;
	int	look_down;
	int	move_left;
	int	move_right;
	int	move_up;
	int	move_down;
} t_controls;

typedef struct s_window
{
	void *mlx;
	void *win;
	t_controls *controls;
} t_window;

typedef struct s_player
{
	double posX;
	double posY;
	double dirX;
	double dirY;
	char direction;
} t_player;

typedef struct s_ray
{
	double rayDirX;
	double rayDirY;
	double camX;
	double planeX;
	double planeY;
	double deltaDistx;
	double deltaDistY;
	double sideDistX;
	double sideDistY;
} t_ray;

typedef struct s_game
{
	t_window *window;
	t_player *player;
	t_ray *ray;
	int mapX;
	int mapY;
	char **map;
	char *NO;
	char *SO;
	char *WE;
	char *EA;
	char *F;
	char *C;
} t_game;

int check_map(char *argv, t_game *g);
char **check_open_map(char *argv);
int valid_edge(char **map, int i, int j);
int valid_top_bottom(char **map, int i, int j);
int	valid_whitespace(char **map, int i, int j);
int nosp_strlen(char *str);
int map_colomn(char **mx);
int	map_row(char **mx);
int draw2Dmap(t_game *g);
void draw_square(t_game *g, int x, int y, int color);
int	press_key(int key,  t_window *window);
int	close_x(void);

#endif
