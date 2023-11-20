/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mneri <mneri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 15:21:32 by mneri             #+#    #+#             */
/*   Updated: 2023/11/20 14:45:28 by mneri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H

# include <unistd.h>
# include <stdio.h>
# include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
# include <math.h>
# include "../minilibx-linux/mlx.h"
# include "../Libft/libft.h"
# include <X11/keysym.h>
# define NORTH 1
# define EAST 2
# define SOUTH 3
# define WEST 4


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
	double planeX;
	double planeY;
	double cam_height;
	char direction;
} t_player;

typedef struct s_ray
{
	double rayDirX;
	double rayDirY;
	double cameraX;
	double deltaDistX;
	double deltaDistY;
	double sideDistX;
	double sideDistY;
	double perpWallDist;
	int curr_x;
	int stepX;
	int stepY;
	int hit;
	int side;
	int draw_start;
	int draw_end;
	int line_height;
} t_ray;

typedef struct s_line
{
	int x;
	int y;
	int y0;
	int y1;
	int tex_x;
	int tex_y;
} t_line;

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
	t_window *window;
	t_player *player;
	t_ray *ray;
	t_line *line;
	t_image *img;
	t_image *NO_tex;
	t_image *SO_tex;
	t_image *EA_tex;
	t_image *WE_tex;
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
void	render(t_game *g);
void paint_texture_line(t_game *g, double wall_x);
void draw_texture_image(t_game *g, t_image *tex);
void texture_on_img(t_game *g, t_image *tex);
void init_ray_value(t_game *g);
void calculate_side(t_game * g);
void dda(t_game *g);
void	measure_perp(t_game *g);
int game_loop(t_game *g);

#endif