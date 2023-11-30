/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_camera.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfai <lfai@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 16:17:18 by mneri             #+#    #+#             */
/*   Updated: 2023/11/30 17:42:00 by lfai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//setta elementi per fov e camera su screen
void	ft_set_fov(t_game *g, double dir_y, double cam_x, double cam_y)
{
	g->player->dir_y = dir_y;
	g->player->plane_x = cam_x;
	g->player->plane_y = cam_y;
}

/* change player vector direction using this matrix formula:
   [ cos(a) -sin(a) ] *
   [ sin(a)  cos(a) ]
   (a is the angle of rotation / sensitivity)*/
void	ft_look_right(t_game *game)
{
	double	prev_dir_x;
	double	prev_plane_x;
	double	sens;

	prev_dir_x = game->player->dir_x;
	prev_plane_x = game->player->plane_x;
	sens = game->player->sens;
	game->player->dir_x = game->player->dir_x
		* cos(sens) - game->player->dir_y * sin(sens);
	game->player->dir_y = prev_dir_x * sin(sens)
		+ game->player->dir_y * cos(sens);
	game->player->plane_x = game->player->plane_x
		* cos(sens) - game->player->plane_y * sin(sens);
	game->player->plane_y = prev_plane_x * sin(sens)
		+ game->player->plane_y * cos(sens);
}

void	ft_look_left(t_game *game)
{
	double	prev_dir_x;
	double	prev_plane_x;
	double	sens;

	prev_dir_x = game->player->dir_x;
	prev_plane_x = game->player->plane_x;
	sens = game->player->sens;
	game->player->dir_x = game->player->dir_x
		* cos(-sens) - game->player->dir_y * sin(-sens);
	game->player->dir_y = prev_dir_x * sin(-sens)
		+ game->player->dir_y * cos(sens);
	game->player->plane_x = game->player->plane_x
		* cos(-sens) - game->player->plane_y * sin(-sens);
	game->player->plane_y = prev_plane_x * sin(-sens)
		+ game->player->plane_y * cos(-sens);
}
