/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mneri <mneri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 15:21:17 by mneri             #+#    #+#             */
/*   Updated: 2023/11/27 17:05:40 by mneri            ###   ########.fr       */
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
	fd = open(argv, O_RDONLY);
	if(fd == -1)
		return NULL;
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

char *copy_path(char *map, int i, char *s)
{
	int len;
	char *path;
	int j;

	free(s);
	while(map[i] && (map[i] == ' '))
		i++;
	i--;
	len = ft_strlen(map) - i;
	path = malloc(sizeof(char) * len + 1);
	j = 0;
	while(map[i++])
		path[j++] = map[i];
	path[j] = '\0';
	return path;
}

void add_path_var(t_game *g, char *type, int *flag, char *map)
{
	int i;

	i = 2;
	if(!ft_strcmp(type, "NO "))
		g->NO = copy_path(map, i, g->NO);
	else if(!ft_strcmp(type, "SO "))
		g->SO = copy_path(map, i, g->SO);
	else if(!ft_strcmp(type, "WE "))
		g->WE = copy_path(map, i, g->WE);
	else if(!ft_strcmp(type, "EA "))
		g->EA = copy_path(map, i, g->EA);
	else if(!ft_strcmp(type, "F "))
	{
		i = 1;
		g->F = copy_path(map, i, g->F);
	}
	else if(!ft_strcmp(type, "C "))
	{
		i = 1;
		g->C = copy_path(map, i, g->C);
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
	while(map[i] && *flag <= 6)
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
	if(*flag != 6 || !ft_strchr(map[6], '1'))
	{
		free(flag);
		return 0;
	}	
	free(flag);
	return 1;
}

void	init_player(t_game *g, int i, int j, char **map)
{
	g->player->posX = j;
	g->player->posY = i;
	g->player->cam_height = 1.0;
	if (map[i][j] == 'N') 
	{
		g->player->dirX = 0;
		g->player->dirY = -1;
	}
	else if (map[i][j] == 'E')
	{
		g->player->dirX = 1;
		g->player->dirY = 0;
	}
	else if (map[i][j] == 'W')
	{
		g->player->dirX = -1;
		g->player->dirY = 0;
		g->player->planeY = -0.66;
		g->player->planeX = 0;

	} 
	else if (map[i][j] == 'S') 
	{
		g->player->dirX = 0;
		g->player->dirY = 1;
	}
}

int valid_char(char **map, int i, int j, t_game *g)
{
	if(map[i][j] == 'S' || map[i][j] == 'N' || map[i][j] == 'E' || map[i][j] == 'W')
	{
		if(g->player->found != 0)
			return 0;
		init_player(g, i, j, map);
		g->player->found = 1;
		return 1;
	}
	if(map[i][j] != '1' && map[i][j] != '0' && map[i][j] != ' ' && map[i][j] != '\t')
		return 0;
	return 1;
}



int check_map_maze(char **map, t_game *g)
{
	int i;
	int j;

	i = 6;
	j = 0;

	if(!valid_top_bottom(map, i, j) || !valid_top_bottom(map, map_row(map) - 1, j))
		return 0;
	i++;
	while(map[i])
	{
		if(!valid_edge(map, i, j))
			return 0;
		while(map[i][j])
		{
			if(!valid_whitespace(map, i, j) || !valid_zero(map, i, j))
			{
				return 0;
			}
			if(!valid_char(map, i , j, g))
			{
				return 0;
			}
			if(map[i + 1])
			{
				if((nosp_strlen(map[i]) > nosp_strlen(map[i - 1]) && (i) > nosp_strlen(map[i - 1])) ||
					(nosp_strlen(map[i]) > nosp_strlen(map[i + 1]) && (i) > nosp_strlen(map[i + 1])))
				{
					printf("%s\n", map[i]);
					return 0;
				}
			}
			j++;
		}
		j = 0;
		i++;
	}
	return 1;
}

int load_texture(t_game *g, t_image *img, char *s)
{
	int width;
	int height;

	height = 0;
	width = 0;
	if(!ft_strcmp(s, "NO"))
		img->img_ptr = mlx_xpm_file_to_image(g->window->mlx, g->NO, &width, &height);
	else if(!ft_strcmp(s, "SO"))
		img->img_ptr = mlx_xpm_file_to_image(g->window->mlx, g->SO, &width, &height);
	else if(!ft_strcmp(s, "EA"))
		img->img_ptr = mlx_xpm_file_to_image(g->window->mlx, g->EA, &width, &height);
	else if(!ft_strcmp(s, "WE"))
		img->img_ptr = mlx_xpm_file_to_image(g->window->mlx, g->WE, &width, &height);
	if (!img->img_ptr)
        return 0;
	img->data = mlx_get_data_addr(img->img_ptr, &img->bits_per_pixel, &img->line_length, &img->endian);
	img->width = width;
	img->height = height;
	return 1;
}

int control_num(char **s)
{
	int i;
	int j;
	i = 0;
	j = 0;
	
	if(!s)
		return 0;
	while(s[i])
	{
		while(s[i][j])
		{
			if(!ft_isdigit(s[i][j]))
				return 0;
			j++;
		}
		j = 0;
		i++;
	}
	return 1;
}

int process_color(t_game *g)
{
	char **f_color;
	char **c_color;
	int floor[3];
	int ceil[3];
	int i;

	i = 0;
	f_color = ft_split(g->F, ',');
	c_color = ft_split(g->C, ',');
	f_color[2] = ft_strtrim(f_color[2], " ");
	c_color[2] = ft_strtrim(c_color[2], " ");
	if(!control_num(f_color) || !control_num(c_color))
		return 0;
	while(c_color[i])
		i++;
	if(i != 3)
		return 0;
	i = 0;
	while(f_color[i])
		i++;
	if(i != 3)
		return 0;
	i = 0;
	while(i < 3)
	{
		floor[i] = ft_atoi(f_color[i]);
		ceil[i] = ft_atoi(c_color[i]);
		i++;
	}
	g->F_color = (1 << 24 | floor[0] << 16 | floor[1] << 8 | floor[2]);
	g->C_color = (1 << 24 | ceil[0] << 16 | ceil[1] << 8 | ceil[2]);
	ft_freematrix(f_color);
	ft_freematrix(c_color);
	return 1;
}

int loadTextures(t_game *g)
{
	if(!load_texture(g, g->EA_tex, "EA "))
	{
		return 0;
	}
	if(!load_texture(g, g->SO_tex, "SO "))
	{
		return 0;
	}
	if(!load_texture(g, g->NO_tex, "NO "))
	{
		return 0;
	}
	if(!load_texture(g, g->WE_tex, "WE "))
	{
		return 0;
	}
	return 1;
}

int check_map(char *argv, t_game *g)
{
	if(!check_mapname(argv))
	{
		free_init_game(g);
		return 0;
	}
	g->map = check_open_map(argv);
	if(!g->map || !check_map_path(g->map, g) || !check_map_maze(g->map, g) 
		|| !process_color(g))
	{
		free_init_game(g);
		free_map_pathMaze(g);
		return 0;
	}
	if(!loadTextures(g))
	{
		free_init_game(g);
		free_map_pathMaze(g);
		return 0;
	}
	return 1;
}
