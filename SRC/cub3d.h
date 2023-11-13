/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfai <lfai@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 15:21:32 by mneri             #+#    #+#             */
/*   Updated: 2023/11/12 19:52:50 by lfai             ###   ########.fr       */
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

# define ESC_KEY 65307
# define UP_KEY 65362
# define DOWN_KEY 65364
# define LEFT_KEY 65361
# define RIGHT_KEY 65363
# define W_KEY 119
# define A_KEY 97
# define S_KEY 115
# define D_KEY 100

typedef struct s_game
{
	t_window *window;
	t_player *player;
	char **map;
	char *NO;
	char *SO;
	char *WE;
	char *EA;
	char *F;
	char *C;
} t_game;

typedef struct s_window
{
	void *mlx;
	void *win;
} t_window;

typedef struct s_player
{
	float x;
	float y;
	char direction;
	float speed;
	float sens;
} t_player;

typedef struct s_movement
{
	int	look_up;
	int	look_down;
	int	look_left;
	int	look_right;
	int	move_up;
	int	move_down;
	int	move_left;
	int	move_right;
}				t_movement;

typedef struct s_core
{
	void			*mlx;
	void			*mlx_win;
	t_game		*game;
	t_movement	*movement;
}				t_core;

int check_map(char *argv, t_game *g);
char **check_open_map(char *argv);
int valid_edge(char **map, int i, int j);
int valid_top_bottom(char **map, int i, int j);
int	valid_whitespace(char **map, int i, int j);
int nosp_strlen(char *str);
int map_colomn(char **mx);
int	map_row(char **mx);
void	ft_quit(char *str, int status);
int	press_key(int key, t_core *core);



#endif
