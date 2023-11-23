#include "cub3d.h"

void	ft_move_fwd(t_game *game)
{
	t_player	*player;

	player = game->player;
	if (game->map[(int)(player->posY)][(int)(player->posX + player->dirX * ceil(player->speed))] != '1')
		player->posX += (player->speed * player->dirX);
	if (game->map[(int)(player->posY + player->dirY * ceil(player->speed))][(int)(player->posX)] != '1')
		player->posY += (player->speed * player->dirY);
	 printf("Move Forward - Current Position: (%f, %f)\n", player->posX, player->posY);
}

void	ft_move_bwd(t_game *game)
{
	t_player	*player;

	player = game->player;
	if (game->map[(int)(player->posY)][(int)(player->posX - player->dirX * ceil(player->speed))] != '1')
		player->posX -= (player->speed * player->dirX);
	if (game->map[(int)(player->posY - player->dirY * ceil(player->speed))][(int)(player->posX)] != '1')
		player->posY -= (player->speed * player->dirY);
}

void	ft_move_left(t_game *game)
{
	t_player	*player;

	player = game->player;
	if (game->map[(int)(player->posY)][(int)(player->posX - player->planeX * ceil(player->speed))] != '1')
		player->posX -= (player->speed * player->planeX);
	if (game->map[(int)(player->posY - player->planeY * ceil(player->speed))][(int)(player->posX)] != '1')
		player->posY -= (player->speed * player->planeY);
}

void	ft_move_right(t_game *game)
{
	t_player	*player;

	player = game->player;
	if (game->map[(int)(player->posY)][(int)(player->posX + player->planeX * ceil(player->speed))] != '1')
		player->posX += (player->speed * player->planeX);
	if (game->map[(int)(player->posY + player->planeY * ceil(player->speed))][(int)(player->posX)] != '1')
		player->posY += (player->speed * player->planeY);
}
