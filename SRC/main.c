/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mneri <mneri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 15:20:20 by mneri             #+#    #+#             */
/*   Updated: 2023/11/10 16:17:41 by mneri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void init_game(t_game *g)
{
	g->player = malloc(sizeof(t_player));
}
int put_player(t_game *g)
{
	return mlx_pixel_put(g->window->mlx, g->window->win, g->player->x, g->player->y, 0x03ED27);
	
}
int	ft_input(int keycode, t_game *g)
{
	if (keycode == XK_s)
		g->player->y -=5;
	else if (keycode == XK_w)
		g->player->y +=5;
	else if (keycode == XK_d)
		g->player->x +=5;
	else if (keycode == XK_a)
		g->player->x -=5;
	put_player(g);
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
		printf("%f %f %c", g.player->x,g.player->y, g.player->direction);
		// g.window->mlx = mlx_init();
		// g.window->win = mlx_new_window(g.window->mlx, 1920, 1080, "cub3D");
		// mlx_loop_hook(g.window->mlx, put_player, &g);
		// mlx_loop(g.window->mlx);
	}
}