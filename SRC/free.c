/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mneri <mneri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 15:40:06 by mneri             #+#    #+#             */
/*   Updated: 2023/11/28 16:34:18 by mneri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_init_game(t_game *g, int status)
{
if(status == 0)
{
	if(g->NO_tex->img_ptr != NULL)
		mlx_destroy_image(g->window->mlx, g->NO_tex->img_ptr);
	if(g->EA_tex->img_ptr != NULL)
		mlx_destroy_image(g->window->mlx, g->EA_tex->img_ptr);
	if(g->WE_tex->img_ptr != NULL)
		mlx_destroy_image(g->window->mlx, g->WE_tex->img_ptr);
	if(g->SO_tex->img_ptr != NULL)
		mlx_destroy_image(g->window->mlx, g->SO_tex->img_ptr);
	if(g->img->img_ptr != NULL)
		mlx_destroy_image(g->window->mlx, g->img->img_ptr);
}
	free(g->player);
	free(g->controls);
	free(g->NO_tex);
	free(g->EA_tex);
	free(g->WE_tex);
	free(g->SO_tex);
	free(g->img);
	free(g->NO);
	free(g->EA);
	free(g->SO);
	free(g->WE);
	free(g->F);
	free(g->C);
}


void 	free_map_pathMaze(t_game *g)
{
	if(g->map)
		ft_freematrix(g->map);
}

void free_mlx(t_game *g)
{
	mlx_destroy_display(g->window->mlx);
	free(g->window->mlx);
	free(g->window);
}

void	ft_quit(t_game *g, char *str, int status)
{
	free_init_game(g, 0);
	free_map_pathMaze(g);
	mlx_destroy_window(g->window->mlx, g->window->win);
	mlx_destroy_display(g->window->mlx);
	free(g->window->mlx);
	free(g->window);
	ft_putstr_fd(str, 0);
	exit(status);
}

// void	ft_quit2(t_game *g, char *str, int status)
// {
// 	mlx_destroy_image(g->window->mlx, g->img->img_ptr);
// 	mlx_destroy_image(g->window->mlx, g->NO_tex->img_ptr);
// 	mlx_destroy_image(g->window->mlx, g->SO_tex->img_ptr);
// 	mlx_destroy_image(g->window->mlx, g->EA_tex->img_ptr);
// 	mlx_destroy_image(g->window->mlx, g->WE_tex->img_ptr);
// 	free(g->img);
// 	free(g->player);
// 	free(g->controls);
// 	free(g->EA);
// 	free(g->WE);
// 	free(g->SO);
// 	free(g->NO);
// 	free(g->F);
// 	free(g->C);
// 	free(g->EA_tex);
// 	free(g->WE_tex);
// 	free(g->SO_tex);
// 	free(g->NO_tex);
// 	ft_freematrix(g->map);
// 	mlx_destroy_window(g->window->mlx, g->window->win);
// 	mlx_destroy_display(g->window->mlx);
// 	free(g->window->mlx);
// 	free(g->window);
// 	ft_putstr_fd(str, 0);
// 	exit(status);
// }