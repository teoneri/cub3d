/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mneri <mneri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 16:23:49 by mneri             #+#    #+#             */
/*   Updated: 2023/11/30 16:25:47 by mneri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_move_fwd(t_game *game)
{
	t_player	*player;

	player = game->player;
	if (game->map[(int)(player->pos_y)]
		[(int)(player->pos_x + player->dir_x * ceil(player->speed))] != '1')
		player->pos_x += (player->speed * player->dir_x);
	if (game->map[(int)(player->pos_y + player->dir_y * ceil(player->speed))]
			[(int)(player->pos_x)] != '1')
		player->pos_y += (player->speed * player->dir_y);
}

void	ft_move_bwd(t_game *game)
{
	t_player	*player;

	player = game->player;
	if (game->map[(int)(player->pos_y)]
		[(int)(player->pos_x - player->dir_x * ceil(player->speed))] != '1')
		player->pos_x -= (player->speed * player->dir_x);
	if (game->map[(int)(player->pos_y - player->dir_y * ceil(player->speed))]
		[(int)(player->pos_x)] != '1')
		player->pos_y -= (player->speed * player->dir_y);
}

void	ft_move_left(t_game *game)
{
	t_player	*player;

	player = game->player;
	if (game->map[(int)(player->pos_y)]
		[(int)(player->pos_x - player->plane_x * ceil(player->speed))] != '1')
		player->pos_x -= (player->speed * player->plane_x);
	if (game->map[(int)(player->pos_y - player->plane_y * ceil(player->speed))]
		[(int)(player->pos_x)] != '1')
		player->pos_y -= (player->speed * player->plane_y);
}

void	ft_move_right(t_game *game)
{
	t_player	*player;

	player = game->player;
	if (game->map[(int)(player->pos_y)]
		[(int)(player->pos_x + player->plane_x * ceil(player->speed))] != '1')
		player->pos_x += (player->speed * player->plane_x);
	if (game->map[(int)(player->pos_y + player->plane_y * ceil(player->speed))]
		[(int)(player->pos_x)] != '1')
		player->pos_y += (player->speed * player->plane_y);
}
