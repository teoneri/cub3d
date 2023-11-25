#include "cub3d.h"

int	press_key(int key,  t_game *game)
{
	if (key == ESC_KEY)
		ft_quit("Quitting the game\n", 0);
	if (key == W_KEY)
		ft_move_fwd(game);
	if (key == S_KEY)
		ft_move_bwd(game);
	if (key == A_KEY)
		ft_move_left(game);
	if (key == D_KEY)
		ft_move_right(game);
	if (key == RIGHT_KEY)
		ft_look_right(game);
	if (key == LEFT_KEY)
		ft_look_left(game);
	return (0);
}
