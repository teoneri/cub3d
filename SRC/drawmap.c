/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfai <lfai@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:57:39 by mneri             #+#    #+#             */
/*   Updated: 2023/11/21 19:40:11 by lfai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


void draw_square(t_game *g, int x, int y, int color)
{
    int square_size = 20; // Adjust the size as needed
    int i, j;

    for (i = 0; i < square_size; i++)
    {
        for (j = 0; j < square_size; j++)
        {
            mlx_pixel_put(g->mlx, g->win, x + j, y + i, color);
        }
    }
}


int draw2Dmap(t_game *g)
{
	int x = 0;
	int y = 6;

	while(g->map[y])
	{
		while(g->map[y][x])
		{
			if(g->map[y][x] == '1')
				draw_square(g, x * 20, y * 20, 0xFF0000);
			if(y == (int)g->player->posY && x == (int)g->player->posX )
			{
				draw_square(g, x * 20, y * 20, 0xFFFF00);
			}
			x++;
		}
		x = 0;
		y++;
	}
	return 0;
}
