/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mneri <mneri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 15:20:20 by mneri             #+#    #+#             */
/*   Updated: 2023/11/30 16:53:36 by mneri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_game(t_game *g)
{
	ft_init_player(g);
	ft_init_controls(g);
	g->window = malloc(sizeof(t_window));
	g->no_tex = malloc(sizeof(t_image));
	g->so_tex = malloc(sizeof(t_image));
	g->we_tex = malloc(sizeof(t_image));
	g->ea_tex = malloc(sizeof(t_image));
	g->no = ft_calloc(1, 1);
	g->so = ft_calloc(1, 1);
	g->we = ft_calloc(1, 1);
	g->ea = ft_calloc(1, 1);
	g->c = ft_calloc(1, 1);
	g->f = ft_calloc(1, 1);
	g->img = malloc(sizeof(t_image));
	g->img->img_ptr = NULL;
}

int	close_x(t_game *g)
{
	ft_quit(g, "Quitting the game\n", 0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	g;

	if (argc == 2)
	{
		init_game(&g);
		if (!check_map(argv[1], &g))
		{
			printf("Error\n");
			return (0);
		}
		g.window->win = mlx_new_window(g.window->mlx,
				WIN_WIDTH, WIN_HEIGHT, "cub3D");
		g.img->img_ptr = mlx_new_image(g.window->mlx, WIN_WIDTH, WIN_HEIGHT);
		g.img->width = WIN_WIDTH;
		g.img->height = WIN_HEIGHT;
		g.img->data = mlx_get_data_addr(g.img->img_ptr,
				&g.img->bits_per_pixel, &g.img->linelen, &g.img->endian);
		mlx_hook(g.window->win, 2, 1L << 0, press_key, &g);
		mlx_loop_hook(g.window->mlx, game_loop, &g);
		mlx_hook(g.window->win, 17, 0, close_x, &g);
		mlx_loop(g.window->mlx);
	}
	return (0);
}
