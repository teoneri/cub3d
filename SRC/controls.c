#include "cub3d.h"

int	press_key(int key,  t_window *window)
{
	if (key == ESC_KEY)
		close_x();
	if (key == W_KEY)
		window->controls->move_up = 1;
	printf("%d\n", key);
	if (key == S_KEY)
		window->controls->move_down = 1;
	if (key == A_KEY)
		window->controls->move_left = 1;
	if (key == D_KEY)
		window->controls->move_right = 1;
	if (key == UP_KEY)
		window->controls->look_up = 1;
	if (key == DOWN_KEY)
		window->controls->look_down = 1;
	if (key == RIGHT_KEY)
		window->controls->look_right = 1;
	if (key == LEFT_KEY)
		window->controls->look_left = 1;
	return (0);
}
