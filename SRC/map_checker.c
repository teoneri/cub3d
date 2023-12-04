/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mneri <mneri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 15:21:17 by mneri             #+#    #+#             */
/*   Updated: 2023/12/04 15:33:29 by mneri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_mapname(char *argv)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	j = 0;
	tmp = ft_strdup(".cub");
	while (argv[i] != '\0' && argv[i] != '.')
		i++;
	while (argv[i] != '\0')
	{
		if (argv[i++] != tmp[j++])
		{
			free(tmp);
			return (0);
		}
	}
	free(tmp);
	return (1);
}

char	**check_open_map(char *argv)
{
	int		fd;
	char	*stash;
	char	*temp;
	char	**map;
	int		readed;

	readed = 1;
	fd = open(argv, O_RDONLY);
	if (fd == -1)
		return (NULL);
	temp = ft_calloc(sizeof(char), 2);
	stash = ft_calloc(sizeof(char), 1);
	while (readed != 0)
	{
		readed = read(fd, temp, 1);
		stash = ft_strjoin(stash, temp);
	}
	map = ft_split(stash, '\n');
	free(stash);
	free(temp);
	close(fd);
	return (map);
}

int	valid_char(char **map, int i, int j, t_game *g)
{
	if (map[i][j] == 'S' || map[i][j] == 'N'
		|| map[i][j] == 'E' || map[i][j] == 'W')
	{
		if (g->player->found != 0)
			return (0);
		init_player(g, i, j, map);
		g->player->found = 1;
		return (1);
	}
	if (map[i][j] != '1' && map[i][j] != '0'
		&& map[i][j] != ' ' && map[i][j] != '\t')
		return (0);
	return (1);
}

int	continue_valid(char **map, t_game *g, int i, int j)
{
	if (!valid_whitespace(map, i, j) || !valid_zero(map, i, j))
		return (0);
	if (!valid_char(map, i, j, g))
		return (0);
	if (map[i + 1])
	{
		if ((nosp_strlen(map[i]) > nosp_strlen(map[i - 1])
				&& (i) > nosp_strlen(map[i - 1])) || (nosp_strlen(map[i])
				> nosp_strlen(map[i + 1]) && (i) > nosp_strlen(map[i + 1])))
			return (0);
	}
	return (1);
}

int	check_map(char *argv, t_game *g)
{
	if (!check_mapname(argv))
	{
		free_init_game(g, 1);
		free(g->window);
		return (0);
	}
	g->map = check_open_map(argv);
	if (!g->map || !check_map_path(g->map, g) || !check_map_maze(g->map, g)
		|| !process_color(g))
	{
		free_init_game(g, 1);
		free_map_pathmaze(g);
		free(g->window);
		return (0);
	}
	g->window->mlx = mlx_init();
	if (!loadtextures(g))
	{
		free_init_game(g, 0);
		free_map_pathmaze(g);
		free_mlx(g);
		return (0);
	}
	return (1);
}
