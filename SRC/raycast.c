/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mneri <mneri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 15:27:24 by mneri             #+#    #+#             */
/*   Updated: 2023/11/23 14:56:24 by mneri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


void init_ray_value(t_game *g, t_ray *ray)
{
	ray->cameraX = (2 * ray->curr_x )/ (double)WIN_WIDTH - 1;
	ray->rayDirX = g->player->dirX + g->player->planeX * ray->cameraX;
	ray->rayDirY = g->player->dirY + g->player->planeY * ray->cameraX;
	g->mapX = (int)g->player->posX;
	g->mapY = (int)g->player->posY;
	ray->deltaDistX = fabs(1 / ray->rayDirX);
	ray->deltaDistY = fabs(1 / ray->rayDirY);
	ray->hit = 0;
}

void calculate_side(t_game * g, t_ray *ray)
{
	if(ray->rayDirX < 0)
	{
		ray->stepX = -1;
		ray->sideDistX = (g->player->posX - g->mapX) * ray->deltaDistX;
	}
	else
	{
		ray->stepX = 1;
		ray->sideDistX = (g->mapX + 1.0 - g->player->posX) * ray->deltaDistX;
	}
	if(ray->rayDirY < 0)
	{
		ray->stepY = -1;
		ray->sideDistY = (g->player->posY - g->mapY) * ray->deltaDistY;
		
	}
	else
	{
		ray->stepY = 1;
		ray->sideDistY = (g->mapY + 1.0 - g->player->posY) * ray->deltaDistY;
	}
}


void dda(t_game *g, t_ray *ray)
{
	while(ray->hit == 0)
	{
		if(ray->sideDistX < ray->sideDistY)
		{
			ray->sideDistX += ray->deltaDistX;
			g->mapX += ray->stepX;
			if(ray->stepX == -1)
				ray->side = EAST;
			else
				ray->side = WEST;
		}
		else
		{
			ray->sideDistY += ray->deltaDistY;
			g->mapY += ray->stepY;
			if(ray->stepY == -1)
				ray->side = SOUTH;
			else
				ray->side = NORTH;
		}
	if(g->map[g->mapY][g->mapX] == '1')
		ray->hit = 1;
	}
}

void	measure_perp(t_game *g, t_ray *ray)
{
	if(ray->side == WEST || ray->side == EAST)
	{
		ray->perpWallDist = ((double)g->mapX - g->player->posX +
			(1 - ray->stepX) / 2) / ray->rayDirX;
	}
	else
	{
		ray->perpWallDist = ((double)g->mapY - g->player->posY +
			(1 - ray->stepY) / 2) / ray->rayDirY;
	}
	ray->line_height = WIN_HEIGHT / ray->perpWallDist;
	ray->draw_start = -ray->line_height / 2 + ((WIN_HEIGHT / 2 ) * g->player->cam_height);
	if(ray->draw_start <= 0)
		ray->draw_start = 0;
	ray->draw_end = ray->line_height / 2 + ((WIN_HEIGHT / 2) * g->player->cam_height);
	if(ray->draw_end >= WIN_HEIGHT)
		ray->draw_end = WIN_HEIGHT - 1;
}




int game_loop(t_game *g)
{
	t_ray *ray;

	ray = malloc(sizeof(t_ray));
	ray->curr_x = 0;
	while(ray->curr_x < WIN_WIDTH)
	{
		init_ray_value(g, ray);
		calculate_side(g, ray);
		dda(g, ray);
		measure_perp(g, ray);
		render(g, ray);
		ray->curr_x ++;
	}
	mlx_put_image_to_window(g->window->mlx, g->window->win, g->img->img_ptr, 0, 0);
	free(ray);
	return 0;
}