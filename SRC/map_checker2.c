/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mneri <mneri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 16:36:09 by mneri             #+#    #+#             */
/*   Updated: 2023/11/30 17:11:44 by mneri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*copy_path(char *map, int i, char *s)
{
	int		len;
	char	*path;
	int		j;

	free(s);
	while (map[i] && (map[i] == ' '))
		i++;
	i--;
	len = ft_strlen(map) - i;
	path = malloc(sizeof(char) * len + 1);
	j = 0;
	while (map[i++])
		path[j++] = map[i];
	path[j] = '\0';
	return (path);
}

void	add_path_var(t_game *g, char *type, int *flag, char *map)
{
	int	i;

	i = 2;
	if (!ft_strcmp(type, "NO "))
		g->no = copy_path(map, i, g->no);
	else if (!ft_strcmp(type, "SO "))
		g->so = copy_path(map, i, g->so);
	else if (!ft_strcmp(type, "WE "))
		g->we = copy_path(map, i, g->we);
	else if (!ft_strcmp(type, "EA "))
		g->ea = copy_path(map, i, g->ea);
	else if (!ft_strcmp(type, "F "))
	{
		i = 1;
		g->f = copy_path(map, i, g->f);
	}
	else if (!ft_strcmp(type, "C "))
	{
		i = 1;
		g->c = copy_path(map, i, g->c);
	}
	(*flag)++;
}

void	find_path(char **map, t_game *g, int *flag, int i)
{
	if (!ft_strncmp(map[i], "NO ", 3))
		add_path_var(g, "NO ", flag, map[i]);
	else if (!ft_strncmp(map[i], "SO ", 3))
		add_path_var(g, "SO ", flag, map[i]);
	else if (!ft_strncmp(map[i], "WE ", 3))
		add_path_var(g, "WE ", flag, map[i]);
	else if (!ft_strncmp(map[i], "EA ", 3))
		add_path_var(g, "EA ", flag, map[i]);
	else if (!ft_strncmp(map[i], "F ", 2))
		add_path_var(g, "F ", flag, map[i]);
	else if (!ft_strncmp(map[i], "C ", 2))
		add_path_var(g, "C ", flag, map[i]);
}

int	check_map_path(char **map, t_game *g)
{
	int	i;
	int	*flag;

	flag = malloc(sizeof(int));
	*flag = 0;
	i = 0;
	while (map[i] && *flag <= 6)
	{
		find_path(map, g, flag, i);
		i++;
	}
	if (*flag != 6 || !ft_strchr(map[6], '1'))
	{
		free(flag);
		return (0);
	}
	free(flag);
	return (1);
}

int	check_map_maze(char **map, t_game *g)
{
	int	i;
	int	j;

	i = 6;
	j = 0;
	if (!valid_top_bottom(map, i, j)
		|| !valid_top_bottom(map, map_row(map) - 1, j))
		return (0);
	while (map[++i])
	{
		if (!valid_edge(map, i, j))
			return (0);
		while (map[i][j])
		{
			if (!continue_valid(map, g, i, j))
				return (0);
			j++;
		}
		j = 0;
	}
	return (1);
}
