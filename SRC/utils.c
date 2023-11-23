#include "cub3d.h"

void	ft_init_player(t_game *g)
{
	g->player = malloc(sizeof(t_player));
	if (!g->player)
		close_x(g);
	g->player->posX = 5;
	g->player->posY = 5;
	g->player->dirX = 0;
	g->player->dirY = 0;
	g->player->planeX = 0;
	g->player->planeY = 0;
	g->player->speed = 0.5;
}

void	ft_init_controls(t_game *g)
{
	g->controls = malloc(sizeof(t_controls));
	if (!g->controls)
		close_x(g);
	//g->controls->look_left = 0;
	//g->controls->look_right = 0;
	//g->controls->look_up = 0;
	//g->controls->look_down = 0;
	g->controls->move_left = 0;
	g->controls->move_right = 0;
	g->controls->move_up = 0;
	g->controls->move_down = 0;
}
