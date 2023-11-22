/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfai <lfai@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 15:21:32 by mneri             #+#    #+#             */
/*   Updated: 2023/11/22 11:19:52 by lfai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H

# include <unistd.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <math.h>
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

/*typedef struct s_window
{
	void *mlx;
	void *win;
	//t_player	*player;
} t_window;*/

typedef struct s_player
{
	double posX;
	double posY;
	double dirX;
	double dirY;
	double planeX;
	double planeY;
	double speed;
	char direction;
} t_player;

typedef struct s_ray
{
	double rayDirX;
	double rayDirY;
	double cameraX;
	double deltaDistx;
	double deltaDistY;
	double sideDistX;
	double sideDistY;
	int stepX;
	int stepY;
	int hit;
	int side;
} t_ray;

typedef struct s_image
{
	void	*img_ptr;
	char	*data;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}				t_image;

typedef struct s_game
{
	//t_window	*window;
	t_player	*player;
	t_controls	*controls;
	t_ray *ray;
	t_image *img;
	void *mlx;
	void *win;
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

int	check_map(char *argv, t_game *g);
char	**check_open_map(char *argv);
int	valid_edge(char **map, int i, int j);
int	valid_top_bottom(char **map, int i, int j);
int	valid_whitespace(char **map, int i, int j);
int	nosp_strlen(char *str);
int	map_colomn(char **mx);
int	map_row(char **mx);
int	draw2Dmap(t_game *g);
void	draw_square(t_game *g, int x, int y, int color);
int	close_x();
int	press_key(int key,  t_game *game);
int	release_key(int key,  t_game *game);
void	ft_check_key(t_game *game);
void	ft_move_fwd(t_game *game);
void	ft_move_bwd(t_game *game);
void	ft_move_left(t_game *game);
void	ft_move_right(t_game *game);
void	ft_init_controls(t_game *g);
void	ft_init_player(t_game *g);

#endif
