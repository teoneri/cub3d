/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfai <lfai@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 15:27:24 by mneri             #+#    #+#             */
/*   Updated: 2023/11/20 19:11:48 by lfai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


void init_ray_value(t_game *g)
{
	g->ray->cameraX = 2 * x / double(w) - 1;
	g->ray->rayDirX = g->player->dirX + g->player->planeX * g->ray->cameraX;
	g->ray->rayDirY = g->player->dirY + g->player->planeY * g->ray->cameraX;
	g->ray->mapX = int(g->player.posX);
	g->ray->mapY = int(g->player.posY);
	g->ray->deltaDistX = abs(1 / g->rayDirX);
	g->ray->deltaDistY = abs(1 / g->rayDirY);
	g->ray->hit = 0;
}

void calculate_side(t_game * g)
{
	if(g->ray->rayDirX < 0)
	{
		g->ray->stepX = -1;
		g->ray->sideDistX = (g->player->posX - g->ray->mapX) * g->ray->deltaDistX;
	}
	else
	{
		g->ray->stepX = 1;
		g->ray->sideDistX = (g->ray->mapX + 1.0 - g->player->posX) * g->ray->deltaDistX;
	}
	if(g->ray->rayDirY < 0)
	{
		g->ray->stepY = -1;
		g->ray->sideDistX = (g->player->posY - g->ray->mapY) * g->ray->deltaDistY;

	}
	else
	{
		g->ray->stepY = 1;
		g->ray->sideDistY = (g->ray->mapY + 1.0 - g->player->posY) * g->ray->deltaDistY;
	}
}

void dda(t_game *g)
{
	while(hit == 0)
	{
		if(g->ray->sideDistX < g->ray->sideDistY)
		{
			g->ray->sideDistX += g->ray->deltaDistX;
			g->ray->mapX += g->ray->stepX;
			g->ray->side = 0;
		}
		else
		{
			g->ray->sideDistY += g->ray->deltaDistY;
			g->ray->mapY += g->ray->stepY;
			g->ray->side = 1;
		}
		if(g->map[g->ray->mapX][g->ray->mapY] > 0)
			hit = 1;
	}
}


int game_loop(t_game *g)
{
	int x = 0;


	while(x < 1920)
	{
		init_ray_value(g);
		calculate_side(g);
		dda(g);
	}
}
