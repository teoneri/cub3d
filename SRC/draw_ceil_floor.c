/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_ceil_floor.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mneri <mneri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 16:33:25 by mneri             #+#    #+#             */
/*   Updated: 2023/11/30 16:53:08 by mneri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	paint_ceil_floor(int rgb, int x, int y, t_image *img)
{
	int	r;
	int	b;
	int	g;

	r = (rgb >> 16) & 0xFF;
	g = (rgb >> 8) & 0xFF;
	b = rgb & 0xFF;
	img->data[y * img->linelen + x * img->bits_per_pixel / 8] = b;
	img->data[y * img->linelen + x * img->bits_per_pixel / 8 + 1] = g;
	img->data[y * img->linelen + x * img->bits_per_pixel / 8 + 2] = r;
}

void	paint_line(t_game *g, t_line *line, int rgb)
{
	int	y_max;
	int	y;

	if (line->y0 < line->y1)
	{
		y = line->y0;
		y_max = line->y1;
	}
	else
	{
		y = line->y1;
		y_max = line->y0;
	}
	if (y >= 0)
	{
		while (y < y_max)
		{
			paint_ceil_floor(rgb, line->x, y, g->img);
			y++;
		}
	}
}
