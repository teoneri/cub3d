/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mneri <mneri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 15:20:20 by mneri             #+#    #+#             */
/*   Updated: 2023/11/13 18:08:33 by mneri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void init_game(t_game *g)
{
	g->player = malloc(sizeof(t_player));
}

int	ft_input(int keycode, t_game *g)
{
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

int game_loop(t_game *g)
{

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
		mlx_loop_hook(g.window->mlx, game_loop, &g);
		mlx_loop(g.window->mlx);
	}
}