/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mneri <mneri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 15:21:32 by mneri             #+#    #+#             */
/*   Updated: 2023/11/30 17:04:51 by mneri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <math.h>
# include "../minilibx-linux/mlx.h"
# include "../Libft/libft.h"
# include <X11/keysym.h>
# define NORTH 1
# define EAST 2
# define SOUTH 3
# define WEST 4
# define WIN_HEIGHT 1080
# define WIN_WIDTH 1920

typedef struct s_window
{
	void	*mlx;
	void	*win;
}	t_window;

typedef struct s_player
{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	double	cam_height;
	double	speed;
	double	sens;
	char	direction;
	int		found;
}	t_player;

typedef struct s_ray
{
	double	raydir_x;
	double	raydir_y;
	double	camera_x;
	double	deltadist_x;
	double	deltadist_y;
	double	sidedist_x;
	double	sidedist_y;
	double	perpwalldist;
	int		curr_x;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
	int		draw_start;
	int		draw_end;
	int		line_height;
}	t_ray;

typedef struct s_line
{
	int	x;
	int	y;
	int	y0;
	int	y1;
	int	tex_x;
	int	tex_y;
}	t_line;

typedef struct s_image
{
	void	*img_ptr;
	char	*data;
	int		bits_per_pixel;
	int		linelen;
	int		endian;
	int		width;
	int		height;
}				t_image;

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
}	t_controls;

typedef struct s_game
{
	t_window	*window;
	t_player	*player;
	t_controls	*controls;
	t_image		*img;
	t_image		*no_tex;
	t_image		*so_tex;
	t_image		*ea_tex;
	t_image		*we_tex;
	int			c_color;
	int			f_color;
	int			map_x;
	int			map_y;
	char		**map;
	char		*no;
	char		*so;
	char		*we;
	char		*ea;
	char		*f;
	char		*c;
}	t_game;

void	free_mlx(t_game *g);
void	free_init_game(t_game *g, int status);
void	free_map_pathmaze(t_game *g);
int		valid_zero(char **map, int i, int j);
int		check_map(char *argv, t_game *g);
char	**check_open_map(char *argv);
int		valid_edge(char **map, int i, int j);
int		valid_top_bottom(char **map, int i, int j);
int		valid_whitespace(char **map, int i, int j);
int		nosp_strlen(char *str);
int		map_colomn(char **mx);
int		map_row(char **mx);
int		draw2Dmap(t_game *g);
void	draw_square(t_game *g, int x, int y, int color);
int		close_x(t_game *g);
int		press_key(int key, t_game *game);
int		release_key(int key, t_game *game);
void	ft_check_key(t_game *game);
void	ft_move_fwd(t_game *game);
void	ft_move_bwd(t_game *game);
void	ft_move_left(t_game *game);
void	ft_move_right(t_game *game);
void	ft_look_right(t_game *game);
void	ft_look_left(t_game *game);
void	ft_init_controls(t_game *g);
void	ft_init_player(t_game *g);
void	render(t_game *g, t_ray *ray);
void	paint_texture_line(t_game *g, double wall_x, t_line *line, t_ray *ray);
void	draw_texture_image(t_game *g, t_image *tex, t_line *line, t_ray *ray);
void	texture_on_img(t_game *g, t_image *tex, t_line *line, t_ray *ray);
void	init_ray_value(t_game *g, t_ray *ray);
void	calculate_side(t_game *g, t_ray *ray);
void	dda(t_game *g, t_ray *ray);
void	measure_perp(t_game *g, t_ray *ray);
int		game_loop(t_game *g);
void	ft_quit(t_game *g, char *str, int status);
void	init_player(t_game *g, int i, int j, char **map);
int		check_mapname(char *argv);
int		check_map_maze(char **map, t_game *g);
int		loadtextures(t_game *g);
int		process_color(t_game *g);
int		check_map_path(char **map, t_game *g);
void	paint_line(t_game *g, t_line *line, int rgb);
int		continue_valid(char **map, t_game *g, int i, int j);

#endif
