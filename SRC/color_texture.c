/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mneri <mneri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 16:38:12 by mneri             #+#    #+#             */
/*   Updated: 2023/11/30 17:01:27 by mneri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	load_texture(t_game *g, t_image *img, char *s)
{
	int	w;
	int	h;

	h = 0;
	w = 0;
	if (!ft_strcmp(s, "NO"))
		img->img_ptr = mlx_xpm_file_to_image(g->window->mlx, g->no, &w, &h);
	else if (!ft_strcmp(s, "SO"))
		img->img_ptr = mlx_xpm_file_to_image(g->window->mlx, g->so, &w, &h);
	else if (!ft_strcmp(s, "EA"))
		img->img_ptr = mlx_xpm_file_to_image(g->window->mlx, g->ea, &w, &h);
	else if (!ft_strcmp(s, "WE"))
		img->img_ptr = mlx_xpm_file_to_image(g->window->mlx, g->we, &w, &h);
	if (!img->img_ptr)
		return (0);
	img->data = mlx_get_data_addr(img->img_ptr,
			&img->bits_per_pixel, &img->linelen, &img->endian);
	img->width = w;
	img->height = h;
	return (1);
}

int	control_num(char **s)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		while (s[i][j])
		{
			if (!ft_isdigit(s[i][j]))
				return (0);
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}

int	process_color_util(char **f_color, char **c_color, int i)
{
	if (!control_num(f_color) || !control_num(c_color))
	{
		ft_freematrix(f_color);
		ft_freematrix(c_color);
		return (0);
	}
	while (c_color[i] && f_color[i])
		i++;
	if (i != 3)
	{
		ft_freematrix(f_color);
		ft_freematrix(c_color);
		return (0);
	}
	return (1);
}

int	process_color(t_game *g)
{
	char	**f_color;
	char	**c_color;
	int		floor[3];
	int		ceil[3];
	int		i;

	i = 0;
	f_color = ft_split(g->f, ',');
	c_color = ft_split(g->c, ',');
	f_color[2] = ft_strtrim(f_color[2], " ");
	c_color[2] = ft_strtrim(c_color[2], " ");
	if (!process_color_util(f_color, c_color, i))
		return (0);
	while (i < 3)
	{
		floor[i] = ft_atoi(f_color[i]);
		ceil[i] = ft_atoi(c_color[i]);
		i++;
	}
	g->f_color = (1 << 24 | floor[0] << 16 | floor[1] << 8 | floor[2]);
	g->c_color = (1 << 24 | ceil[0] << 16 | ceil[1] << 8 | ceil[2]);
	ft_freematrix(f_color);
	ft_freematrix(c_color);
	return (1);
}

int	loadtextures(t_game *g)
{
	g->ea_tex->img_ptr = NULL;
	g->so_tex->img_ptr = NULL;
	g->we_tex->img_ptr = NULL;
	g->no_tex->img_ptr = NULL;
	if (!load_texture(g, g->ea_tex, "EA"))
		return (0);
	if (!load_texture(g, g->so_tex, "SO"))
		return (0);
	if (!load_texture(g, g->no_tex, "NO"))
		return (0);
	if (!load_texture(g, g->we_tex, "WE"))
		return (0);
	return (1);
}
