/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mneri <mneri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 15:27:24 by mneri             #+#    #+#             */
/*   Updated: 2023/11/30 16:29:26 by mneri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_ray_value(t_game *g, t_ray *ray)
{
	ray->camera_x = (2 * ray->curr_x) / (double)WIN_WIDTH - 1;
	ray->raydir_x = g->player->dir_x + g->player->plane_x * ray->camera_x;
	ray->raydir_y = g->player->dir_y + g->player->plane_y * ray->camera_x;
	g->map_x = (int)g->player->pos_x;
	g->map_y = (int)g->player->pos_y;
	ray->deltadist_x = fabs(1 / ray->raydir_x);
	ray->deltadist_y = fabs(1 / ray->raydir_y);
	ray->hit = 0;
}

void	calculate_side(t_game *g, t_ray *ray)
{
	if (ray->raydir_x < 0)
	{
		ray->step_x = -1;
		ray->sidedist_x = (g->player->pos_x - g->map_x) * ray->deltadist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->sidedist_x = (g->map_x + 1.0
				- g->player->pos_x) * ray->deltadist_x;
	}
	if (ray->raydir_y < 0)
	{
		ray->step_y = -1;
		ray->sidedist_y = (g->player->pos_y - g->map_y) * ray->deltadist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->sidedist_y = (g->map_y + 1.0
				- g->player->pos_y) * ray->deltadist_y;
	}
}

void	dda(t_game *g, t_ray *ray)
{
	while (ray->hit == 0)
	{
		if (ray->sidedist_x < ray->sidedist_y)
		{
			ray->sidedist_x += ray->deltadist_x;
			g->map_x += ray->step_x;
			if (ray->step_x == -1)
				ray->side = EAST;
			else
				ray->side = WEST;
		}
		else
		{
			ray->sidedist_y += ray->deltadist_y;
			g->map_y += ray->step_y;
			if (ray->step_y == -1)
				ray->side = SOUTH;
			else
				ray->side = NORTH;
		}
		if (g->map[g->map_y][g->map_x] == '1')
			ray->hit = 1;
	}
}

void	measure_perp(t_game *g, t_ray *ray)
{
	if (ray->side == WEST || ray->side == EAST)
	{
		ray->perpwalldist = ((double)g->map_x - g->player->pos_x
				+ (1 - ray->step_x) / 2) / ray->raydir_x;
	}
	else
	{
		ray->perpwalldist = ((double)g->map_y - g->player->pos_y
				+ (1 - ray->step_y) / 2) / ray->raydir_y;
	}
	ray->line_height = WIN_HEIGHT / ray->perpwalldist;
	ray->draw_start = -ray->line_height / 2
		+ ((WIN_HEIGHT / 2) * g->player->cam_height);
	if (ray->draw_start <= 0)
		ray->draw_start = 0;
	ray->draw_end = ray->line_height / 2
		+ ((WIN_HEIGHT / 2) * g->player->cam_height);
	if (ray->draw_end >= WIN_HEIGHT)
		ray->draw_end = WIN_HEIGHT - 1;
}

int	game_loop(t_game *g)
{
	t_ray	*ray;

	ray = malloc(sizeof(t_ray));
	ray->curr_x = 0;
	while (ray->curr_x < WIN_WIDTH)
	{
		init_ray_value(g, ray);
		calculate_side(g, ray);
		dda(g, ray);
		measure_perp(g, ray);
		render(g, ray);
		ray->curr_x ++;
	}
	mlx_put_image_to_window(g->window->mlx,
		g->window->win, g->img->img_ptr, 0, 0);
	free(ray);
	return (0);
}
