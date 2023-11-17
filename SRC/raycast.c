/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mneri <mneri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 15:27:24 by mneri             #+#    #+#             */
/*   Updated: 2023/11/17 18:46:36 by mneri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


void init_ray_value(t_game *g)
{
	g->ray->cameraX = 2 * g->ray->curr_x / (double)1920 - 1;
	g->ray->rayDirX = g->player->dirX + g->player->planeX * g->ray->cameraX;
	g->ray->rayDirY = g->player->dirY + g->player->planeY * g->ray->cameraX;
	g->mapX = (int)g->player->posX;
	g->mapY = (int)g->player->posY;
	g->ray->deltaDistX = abs(1 / g->ray->rayDirX);
	g->ray->deltaDistY = abs(1 / g->ray->rayDirY);
	g->ray->hit = 0;
}

void calculate_side(t_game * g)
{
	if(g->ray->rayDirX < 0)
	{
		g->ray->stepX = -1;
		g->ray->sideDistX = (g->player->posX - g->mapX) * g->ray->deltaDistX;
	}
	else
	{
		g->ray->stepX = 1;
		g->ray->sideDistX = (g->mapX + 1.0 - g->player->posX) * g->ray->deltaDistX;
	}
	if(g->ray->rayDirY < 0)
	{
		g->ray->stepY = -1;
		g->ray->sideDistX = (g->player->posY - g->mapY) * g->ray->deltaDistY;
		
	}
	else
	{
		g->ray->stepY = 1;
		g->ray->sideDistY = (g->mapY + 1.0 - g->player->posY) * g->ray->deltaDistY;
	}
}


void dda(t_game *g)
{
	while(g->ray->hit == 0)
	{
		if(g->ray->sideDistX < g->ray->sideDistY)
		{
			g->ray->sideDistX += g->ray->deltaDistX;
			g->mapX += g->ray->stepX;
			if(g->ray->stepX == -1)
				g->ray->side = EAST;
			else
				g->ray->side = WEST;
		}
		else
		{
			g->ray->sideDistY += g->ray->deltaDistY;
			g->mapY += g->ray->stepY;
			if(g->ray->stepY == -1)
				g->ray->side = SOUTH;
			else
				g->ray->side = NORTH;
		}
	if(g->map[g->mapX][g->mapY] > 0)
		g->ray->hit = 1;
	}
}

void	measure_perp(t_game *g)
{
	if(g->ray->side == 0)
		g->ray->perpWallDist = g->ray->sideDistX - g->ray->deltaDistX;
	else
		g->ray->perpWallDist = g->ray->sideDistY - g->ray->deltaDistY;
	g->ray->line_height = 1080 / g->ray->perpWallDist;
	g->ray->draw_start = -g->ray->line_height / 2 + ((1080 / 2) * g->player->cam_height);
	if(g->ray->draw_start <= 0)
		g->ray->draw_start = 0;
	g->ray->draw_end = g->ray->line_height / 2 + ((1080 / 2) * g->player->cam_height);
	if(g->ray->draw_end >= 1080)
		g->ray->draw_end = 1080 - 1;
}




int game_loop(t_game *g)
{
	g->ray->curr_x = 0;
		
	while(g->ray->curr_x < 1920)
	{
		init_ray_value(g);
		calculate_side(g);
		dda(g);
	}
}