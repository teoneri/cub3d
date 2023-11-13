#include "cub3d.h"

void	ft_quit(char *str, int status)
{
	ft_putstr_fd(str, 0);
	exit(status);
}
