#include "cub3d.h"

int	press_key(int key,  t_game *game)
{
	if (key == ESC_KEY)
		ft_quit("Quitting the game\n", 0);
	if (key == W_KEY)
		game->controls->move_up = 1;
	printf("%d\n", key);
	if (key == S_KEY)
		game->controls->move_down = 1;
	if (key == A_KEY)
		game->controls->move_left = 1;
	if (key == D_KEY)
		game->controls->move_right = 1;
	if (key == UP_KEY)
		game->controls->look_up = 1;
	if (key == DOWN_KEY)
		game->controls->look_down = 1;
	if (key == RIGHT_KEY)
		game->controls->look_right = 1;
	if (key == LEFT_KEY)
		game->controls->look_left = 1;
	return (0);
}

int	release_key(int key,  t_game *game)
{
	if (key == W_KEY)
		game->controls->move_up = 0;
	if (key == S_KEY)
		game->controls->move_down = 0;
	if (key == A_KEY)
		game->controls->move_left = 0;
	if (key == D_KEY)
		game->controls->move_right = 0;
	if (key == UP_KEY)
		game->controls->look_up = 0;
	if (key == DOWN_KEY)
		game->controls->look_down = 0;
	if (key == RIGHT_KEY)
		game->controls->look_right = 0;
	if (key == LEFT_KEY)
		game->controls->look_left = 0;
	return (0);
}

void	ft_check_key(t_game *game)
{
	if (game->controls->move_up)
		ft_move_fwd(game);
	if (game->controls->move_down)
		ft_move_bwd(game);
	if (game->controls->move_left)
		ft_move_left(game);
	if (game->controls->move_right)
		ft_move_right(game);
	if (game->controls->look_right)
		ft_look_right(game);
	if (game->controls->look_left)
		ft_look_left(game);
}
