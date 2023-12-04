/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mneri <mneri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 16:29:30 by mneri             #+#    #+#             */
/*   Updated: 2023/12/04 15:40:27 by mneri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_init_player(t_game *g)
{
	g->player = malloc(sizeof(t_player));
	if (!g->player)
		close_x(g);
	g->player->found = 0;
	g->player->pos_x = 5;
	g->player->pos_y = 5;
	g->player->dir_x = 0;
	g->player->dir_y = 0;
	g->player->plane_x = 0;
	g->player->plane_y = 0;
	g->player->speed = 0.1;
	g->player->sens = 0.1;
}

void	ft_init_controls(t_game *g)
{
	g->controls = malloc(sizeof(t_controls));
	if (!g->controls)
		close_x(g);
	g->controls->look_left = 0;
	g->controls->look_right = 0;
	g->controls->move_left = 0;
	g->controls->move_right = 0;
	g->controls->move_up = 0;
	g->controls->move_down = 0;
}

int	map_row(char **mx)
{
	int	i;

	i = 6;
	while (mx[i] != NULL)
		i++;
	return (i);
}

int	map_colomn(char **mx)
{
	int	i;
	int	j;
	int	max;

	max = 0;
	i = 6;
	j = 0;
	while (mx[i])
	{
		while (mx[i][j])
		{
			j++;
		}
		if (j > max)
			max = j;
		i++;
	}
	return (max);
}

void	init_player(t_game *g, int i, int j, char **map)
{
	g->player->pos_x = j;
	g->player->pos_y = i;
	g->player->cam_height = 1.0;
	if (map[i][j] == 'N')
	{
		g->player->dir_x = 0.00;
		ft_set_fov(g, -1.00, 0.66, 0.00);
	}
	else if (map[i][j] == 'E')
	{
		g->player->dir_x = 1.00;
		ft_set_fov(g, 0.00, 0.00, 0.66);
	}
	else if (map[i][j] == 'W')
	{
		g->player->dir_x = -1;
		ft_set_fov(g, 0.00, 0.00, -0.66);
	}
	else if (map[i][j] == 'S')
	{
		g->player->dir_x = 0.00;
		ft_set_fov(g, 1.00, -0.66, 0.00);
	}
}
