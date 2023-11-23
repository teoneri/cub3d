#include "cub3d.h"

int	press_key(int key,  t_game *game)
{
	if (key == XK_Escape)
		close_x();
	if (key == XK_w)
		game->controls->move_up = 1;
	printf("%d\n", key);
	if (key == XK_s)
		game->controls->move_down = 1;
	if (key == XK_a)
		game->controls->move_left = 1;
	if (key == XK_d)
		game->controls->move_right = 1;
	if (key == XK_Up)
		game->controls->look_up = 1;
	if (key == XK_Down)
		game->controls->look_down = 1;
	if (key == XK_Right)
		game->controls->look_right = 1;
	if (key == XK_Left)
		game->controls->look_left = 1;
	return (0);
}

int	release_key(int key,  t_game *game)
{
	if (key == XK_w)
		game->controls->move_up = 0;
	if (key == XK_s)
		game->controls->move_down = 0;
	if (key == XK_a)
		game->controls->move_left = 0;
	if (key == XK_d)
		game->controls->move_right = 0;
	if (key == XK_Up)
		game->controls->look_up = 0;
	if (key == XK_Down)
		game->controls->look_down = 0;
	if (key == XK_Right)
		game->controls->look_right = 0;
	if (key == XK_Left)
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
}
