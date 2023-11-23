#include "cub3d.h"

//setta elementi per fov e camera su screen
void	ft_set_fov(t_game *g, double dir_y, double cam_x, double cam_y)
{
	/*if (g->player_spawn)
		ft_quit("error: multiple players spawned.\n", 0);*/
	g->player->dirY = dir_y;
	g->player->planeX = cam_x;
	g->player->planeY = cam_y;
}

/* change player vector direction using this matrix formula:
   [ cos(a) -sin(a) ] *
   [ sin(a)  cos(a) ]
   (a is the angle of rotation / sensitivity)*/
void	ft_look_right(t_game *game)
{
	double prev_dirX;
	double prev_planeX;
	double sens;

	prev_dirX = game->player->dirX;
	prev_planeX = game->player->planeX;
	sens = game->player->sens;
	game->player->dirX =
		game->player->dirX * cos(sens) -
		game->player->dirY * sin(sens);
	game->player->dirY = prev_dirX * sin(sens) +
		game->player->dirY * cos(sens);
	game->player->planeX =
		game->player->planeX * cos(sens) -
		game->player->planeY * sin(sens);
	game->player->planeY = prev_planeX * sin(sens) +
		game->player->planeY * cos(sens);
}

void	ft_look_left(t_game *game)
{
	double prev_dirX;
	double prev_planeX;
	double sens;

	prev_dirX = game->player->dirX;
	prev_planeX = game->player->planeX;
	sens = game->player->sens;
	game->player->dirX =
		game->player->dirX * cos(-sens) -
		game->player->dirY * sin(-sens);
	game->player->dirY = prev_dirX * sin(-sens) +
		game->player->dirY * cos(sens);
	game->player->planeX =
		game->player->planeX * cos(-sens) -
		game->player->planeY * sin(-sens);
	game->player->planeY = prev_planeX * sin(-sens) +
		game->player->planeY * cos(-sens);
}
