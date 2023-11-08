/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mneri <mneri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 15:21:17 by mneri             #+#    #+#             */
/*   Updated: 2023/11/08 17:05:51 by mneri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int check_mapname(char *argv)
{
	int i = 0;
	int j = 0;
	char tmp[4] = ".cub";
	while(argv[i] != '\0' && argv[i] != '.')
		i++;
	while(argv[i] != '\0')
	{
		if(argv[i++] != tmp[j++])
			return 0;
	}
	return 1;
}

char **check_open_map(char *argv)
{
	int		fd;
	char	*stash;
	char	*temp;
	char	**map;
	int		readed;

	readed = 1;
	temp = ft_calloc(sizeof(char), 2);
	stash = ft_calloc(sizeof(char), 1);
	fd = open(argv, O_RDONLY);
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

char *copy_path(char *map, int i)
{
	int len;
	char *path;
	int j;

	while(map[i] && (map[i] == ' ' || map[i] == '\t'))
		i++;
	i--;
	len = ft_strlen(map) - i;
	path = malloc(sizeof(char) * len + 1);
	j = 0;
	while(map[i++])
		path[j++] = map[i];
	return path;
}

void add_path_var(t_game *g, char *type, int *flag, char *map)
{
	int i;

	i = 2;
	if(!ft_strcmp(type, "NO "))
		g->NO = copy_path(map, i);
	else if(!ft_strcmp(type, "SO "))
		g->SO = copy_path(map, i);
	else if(!ft_strcmp(type, "WE "))
		g->WE = copy_path(map, i);
	else if(!ft_strcmp(type, "EA "))
		g->EA = copy_path(map, i);
	else if(!ft_strcmp(type, "F "))
	{	
		i = 1;
		g->F = copy_path(map, i);
	}	
	else if(!ft_strcmp(type, "C "))
	{
		i = 1;
		g->C = copy_path(map, i);
	}
	(*flag)++;
}

int check_map_path(char **map, t_game *g)
{
	int i;
	int *flag;

	flag = malloc(sizeof(int));
	*flag = 0;
	i = 0;
	while(map[i] && *flag <= 6 && i <=6)
	{
		if(!ft_strncmp(map[i], "NO ", 3))
			add_path_var(g, "NO ", flag, map[i]);
		else if(!ft_strncmp(map[i], "SO ", 3))
			add_path_var(g, "SO ", flag, map[i]);
		else if(!ft_strncmp(map[i], "WE ", 3))
			add_path_var(g, "WE ", flag, map[i]);
		else if(!ft_strncmp(map[i], "EA ", 3))
			add_path_var(g, "EA ", flag, map[i]);
		else if(!ft_strncmp(map[i], "F ", 2))
			add_path_var(g, "F ", flag, map[i]);
		else if(!ft_strncmp(map[i], "C ", 2))
			add_path_var(g, "C ", flag, map[i]);
		i++;
	}
	if(*flag != 6)
		return 0;
	return 1;
}

int check_map_maze(char **map)


int check_map(char *argv, t_game *g)
{
	if(!check_mapname(argv))
		return 0;
	g->map = check_open_map(argv);
	if(!check_map_path(g->map, g))
		return 0;
	if(!check_map_maze(g->map))
	return 1;
}