/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mneri <mneri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 16:58:48 by mneri             #+#    #+#             */
/*   Updated: 2023/11/30 16:33:36 by mneri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	texture_on_img(t_game *g, t_image *tex, t_line *line, t_ray *ray)
{
	int	scale;

	scale = line->y * tex->linelen
		- (WIN_HEIGHT * g->player->cam_height) * tex->linelen / 2
		+ ray->line_height * tex->linelen / 2;
	line->tex_y = ((scale * tex->height) / ray->line_height) / tex->linelen;
	g->img->data[line->y * g->img->linelen + line->x
		* g->img->bits_per_pixel / 8] = tex->data[line->tex_y
		* tex->linelen + line->tex_x * (tex->bits_per_pixel / 8)];
	g->img->data[line->y * g->img->linelen + line->x
		* g->img->bits_per_pixel / 8 + 1] = tex->data[line->tex_y
		* tex->linelen + line->tex_x * (tex->bits_per_pixel / 8) + 1];
	g->img->data[line->y * g->img->linelen + line->x
		* g->img->bits_per_pixel / 8 + 2] = tex->data[line->tex_y
		* tex->linelen + line->tex_x * (tex->bits_per_pixel / 8) + 2];
}

void	draw_texture_image(t_game *g, t_image *tex, t_line *line, t_ray *ray)
{
	int	y_max;

	if (line->y0 < line->y1)
	{
		line->y = line->y0;
		y_max = line->y1;
	}
	else
	{
		line->y = line->y1;
		y_max = line->y0;
	}
	if (line->y >= 0)
	{
		line->y--;
		while (++line->y < y_max)
		{
			texture_on_img(g, tex, line, ray);
		}
	}
}

void	paint_texture_line(t_game *g, double wall_x, t_line *line, t_ray *ray)
{
	t_image	*img;
	int		tex_x;

	img = NULL;
	if (ray->side == EAST)
		img = g->ea_tex;
	else if (ray->side == NORTH)
		img = g->no_tex;
	else if (ray->side == SOUTH)
		img = g->so_tex;
	else if (ray->side == WEST)
		img = g->we_tex;
	tex_x = (int)(wall_x * (double)img->width);
	if ((ray->side == WEST || ray->side == EAST) && g->player->dir_x > 0)
		tex_x = img->width - tex_x - 1;
	else if ((ray->side == NORTH || ray->side == SOUTH) && g->player->dir_y < 0)
		tex_x = img->width - tex_x - 1;
	line->y0 = ray->draw_start;
	line->y1 = ray->draw_end;
	line->tex_x = tex_x;
	draw_texture_image(g, img, line, ray);
}

void	render(t_game *g, t_ray *ray)
{
	double	wall_x;
	t_line	*line;

	line = malloc(sizeof(t_line));
	if (ray->side == WEST || ray->side == EAST)
		wall_x = g->player->pos_y + ray->perpwalldist * ray->raydir_y;
	else
		wall_x = g->player->pos_x + ray->perpwalldist * ray->raydir_x;
	wall_x -= floor(wall_x);
	line->x = ray->curr_x;
	if (g->map[g->map_y][g->map_x] == '1')
		paint_texture_line(g, wall_x, line, ray);
	line->y0 = 0;
	line->y1 = ray->draw_start;
	paint_line(g, line, g->f_color);
	line->y0 = WIN_HEIGHT;
	line->y1 = ray->draw_end;
	paint_line(g, line, g->c_color);
	free(line);
}
