/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mneri <mneri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 15:40:06 by mneri             #+#    #+#             */
/*   Updated: 2023/11/30 15:55:52 by mneri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	destroy_image(t_game *g)
{
	if (g->no_tex->img_ptr != NULL)
		mlx_destroy_image(g->window->mlx, g->no_tex->img_ptr);
	if (g->ea_tex->img_ptr != NULL)
		mlx_destroy_image(g->window->mlx, g->ea_tex->img_ptr);
	if (g->we_tex->img_ptr != NULL)
		mlx_destroy_image(g->window->mlx, g->we_tex->img_ptr);
	if (g->so_tex->img_ptr != NULL)
		mlx_destroy_image(g->window->mlx, g->so_tex->img_ptr);
	if (g->img->img_ptr != NULL)
		mlx_destroy_image(g->window->mlx, g->img->img_ptr);
}

void	free_init_game(t_game *g, int status)
{
	if (status == 0)
		destroy_image(g);
	free(g->player);
	free(g->controls);
	free(g->no_tex);
	free(g->ea_tex);
	free(g->we_tex);
	free(g->so_tex);
	free(g->img);
	free(g->no);
	free(g->ea);
	free(g->so);
	free(g->we);
	free(g->f);
	free(g->c);
}

void	free_map_pathmaze(t_game *g)
{
	if (g->map)
		ft_freematrix(g->map);
}

void	free_mlx(t_game *g)
{
	mlx_destroy_display(g->window->mlx);
	free(g->window->mlx);
	free(g->window);
}

void	ft_quit(t_game *g, char *str, int status)
{
	free_init_game(g, 0);
	free_map_pathmaze(g);
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