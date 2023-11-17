/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mneri <mneri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 16:58:48 by mneri             #+#    #+#             */
/*   Updated: 2023/11/17 18:50:08 by mneri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"



static void texture_on_img(t_game *g, t_image *tex)
{
	int scale;

	scale = g->line->y * tex->line_length
		- (1080 * g->player->cam_height) * tex->line_length / 2
		+ g->ray->line_height *  tex->line_length / 2;
	g->line->tex_y = ((scale * tex->height) / g->ray->line_height) / tex->line_length;
	g->img->data[g->line->y + g->line->x * g->img->bits_per_pixel / 8] =
		tex->data[g->line->tex_y * tex->line_length + g->line->tex_x * (tex->bits_per_pixel / 8)];
	g->img->data[(g->line->y + g->line->x * g->img->bits_per_pixel / 8) + 1] =
		tex->data[g->line->tex_y * tex->line_length + g->line->tex_x * (tex->bits_per_pixel / 8) + 1];
	g->img->data[(g->line->y + g->line->x * g->img->bits_per_pixel / 8) + 2] =
		tex->data[g->line->tex_y * tex->line_length + g->line->tex_x * (tex->bits_per_pixel / 8) + 2];   
}

void draw_texture_image(t_game *g, t_image *tex)
{
	int y;
	int y_max;
	
	if(g->line->y0 < g->line->y1)
	{
		y = g->line->y0;
		y_max = g->line->y1;
	}
	else
	{
		y = g->line->y1;
		y_max = g->line->y0;
	}
	if(y >= 0)
	{
		while(y < y_max)
		{
			texture_on_img(g, tex);
			y++;
		}
	}
}

void paint_texture_line(t_game *g)
{
	t_image *img;
	int tex_x;
	
	if(g->ray->side == EAST)
		img = g->EA_tex;
	else if(g->ray->side == NORTH)
		img = g->NO_tex;	
	else if(g->ray->side == SOUTH)
		img = g->SO_tex;	
	else if(g->ray->side == WEST)
		img = g->WE_tex;
	tex_x = (int)(wall_x * (double)img->width);
	if ((g->ray->side == WEST || g->ray->side == EAST) && g->player->dirX > 0)
		tex_x = img->width - tex_x - 1;
	else if ((g->ray->side == NORTH || g->ray->side == SOUTH) && g->player->dirY < 0)
		tex_x = img->width - tex_x - 1;
	g->line->y0 = g->ray->draw_start;
	g->line->y1 = g->ray->draw_end;
	g->line->tex_x = tex_x;
	draw_texture_image(g, img);
}

void	render(t_game *g)
{
	double wall_x;

	if(g->ray->side == WEST || g->ray->side == EAST)
		wall_x = g->player->posY + g->ray->prepWallDist * g->ray->rayDirY;
	else
		wall_x = g->player->posX + g->ray->prepWallDist * g->ray->rayDirX;
	wall_x -= floor(wall_x);
	g->line->x = g->ray->curr_x;
	if(g->map[g->mapY][g->mapX] == '1')
		paint_line();
	g->line->y0 = 0;
	g->line->y1 = g->ray->draw_start;
	paint_line();
	g->line->y0 = 1080;
	g->line->y1 = g->ray->draw_end;
	paint_line()
}	