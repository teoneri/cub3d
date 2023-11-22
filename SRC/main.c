/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfai <lfai@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 15:20:20 by mneri             #+#    #+#             */
/*   Updated: 2023/11/22 11:09:18 by lfai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void init_game(t_game *g)
{
	ft_init_player(g);
	ft_init_controls(g);
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

int	close_x()
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

		g.mlx = mlx_init();
		g.win = mlx_new_window(g.mlx, 700, 400, "cub3D");
		// draw2Dmap(&g);
		mlx_hook(g.win, 2, 1L << 0, press_key, &g);
		mlx_hook(g.win, 3, 1L << 1, release_key, &g);
		mlx_loop_hook(g.mlx, draw2Dmap, &g);
		mlx_hook(g.win, 17, 0, close_x, &g);
		mlx_loop(g.mlx);
	}
	return (0);
}
