#include "cub3d.h"

int	press_key(int key, t_core *core)
{
	if (key == ESC_KEY)
		ft_quit("Quitting the game\n", 0);
	if (key == W_KEY)
		core->movement->move_up = 1;
	if (key == S_KEY)
		core->movement->move_down = 1;
	if (key == A_KEY)
		core->movement->move_left = 1;
	if (key == D_KEY)
		core->movement->move_right = 1;
	if (key == UP_KEY)
		core->movement->look_up = 1;
	if (key == DOWN_KEY)
		core->movement->look_down = 1;
	if (key == RIGHT_KEY)
		core->movement->look_right = 1;
	if (key == LEFT_KEY)
		core->movement->look_left = 1;
	return (0);
}
