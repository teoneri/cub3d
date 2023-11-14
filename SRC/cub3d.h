/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mneri <mneri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 15:21:32 by mneri             #+#    #+#             */
/*   Updated: 2023/11/14 16:40:07 by mneri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H

# include <unistd.h>
# include <stdio.h>
# include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
# include "../minilibx-linux/mlx.h"
# include "../Libft/libft.h"
# include <X11/keysym.h>


typedef struct s_window
{
	void *mlx;
	void *win;
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

#endif