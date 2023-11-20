/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mneri <mneri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 15:20:20 by mneri             #+#    #+#             */
/*   Updated: 2023/11/20 14:55:26 by mneri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void init_game(t_game *g)
{
	g->player = malloc(sizeof(t_player));
	g->line = malloc(sizeof(t_line));
	g->ray = malloc(sizeof(t_ray));
	g->window = malloc(sizeof(t_window));
	g->line = malloc(sizeof(t_line));
	g->NO_tex = malloc(sizeof(t_image));
	g->SO_tex = malloc(sizeof(t_image));
	g->WE_tex = malloc(sizeof(t_image));
	g->EA_tex = malloc(sizeof(t_image));
}
void	ft_quit(char *str, int status)
{
	ft_putstr_fd(str, 0);
	exit(status);
}

int	ft_input(int keycode, t_game *g)
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
}

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
		g.window->mlx = mlx_init();
		if(!check_map(argv[1], &g))
		{
			printf("Error\n");
			return 0;
		}
		g.window->win = mlx_new_window(g.window->mlx, 1920, 1080, "cub3D");
		// draw2Dmap(&g);
		mlx_hook(g.window->win, 2, 1L << 0, *ft_input, &g);
		mlx_loop_hook(g.window->mlx, game_loop, &g);
		mlx_hook(g.window->win, 17, 0, close_x, &g);
		mlx_loop(g.window->mlx);
	}
}