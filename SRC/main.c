/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfai <lfai@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 15:20:20 by mneri             #+#    #+#             */
/*   Updated: 2023/11/15 11:41:36 by lfai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void init_game(t_game *g)
{
	g->player = malloc(sizeof(t_player));
	g->window = malloc(sizeof(t_window));
}
void	ft_quit(char *str, int status)
{
	ft_putstr_fd(str, 0);
	exit(status);
}

/*int	ft_input(int keycode, t_game *g)
{
	if (keycode == XK_Escape)
		ft_quit("Quitting the game\n", 0);
	if (keycode == XK_s)
		g->player->posY -=5;
	else if (keycode == XK_w)
		g->player->posY +=5;
	else if (keycode == XK_d)
		g->player->posX +=5;
	else if (keycode == XK_a)
		g->player->posX -=5;
	return (0);
}*/

int	close_x(void)
{
	ft_quit("Quitting the game\n", 0);
	return (0);
}

int main(int argc, char **argv)
{
	t_game g;

	if(argc == 2)
	{
		init_game(&g);
		if(!check_map(argv[1], &g))
		{
			printf("Error\n");
			return 0;
		}

		g.window->mlx = mlx_init();
		g.window->win = mlx_new_window(g.window->mlx, 1920, 1080, "cub3D");
		// draw2Dmap(&g);
		mlx_hook(g.window->win, 2, 1L << 0, press_key, &g);
		mlx_loop_hook(g.window->mlx, draw2Dmap, &g);
		mlx_hook(g.window->win, 17, 0, close_x, &g);
		mlx_loop(g.window->mlx);
	}
	return (0);
}
