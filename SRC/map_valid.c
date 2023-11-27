/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_valid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mneri <mneri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 14:30:29 by mneri             #+#    #+#             */
/*   Updated: 2023/11/27 15:24:28 by mneri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	map_row(char **mx)
{
	int	i;

	i = 6;
	while (mx[i] != NULL)
		i++;
	return (i);
}

int map_colomn(char **mx)
{
	int i;
	int j;
	int max;

	max = 0;
	i = 6;
	j = 0;
	while(mx[i])
	{
		while(mx[i][j])
		{
			j++;
		}
		if(j > max)
			max = j;
		i++;
	}
	return max;
}


int nosp_strlen(char *str)
{
	int i;
	int j;
	int len;

	len = ft_strlen(str) - 1;
	j = 0;
	i = 0;

	if(!str)
		return 0;
	while(str[i] == ' ' || str[i] == '\t' )
		i++;
	j = i;
	while(str[len] == ' ' || str[len] == '\t')
	{
		len--;
		j++;
	}
	while(str[i])
		i++;
	return i - j;
}


int	valid_whitespace(char **map, int i, int j)
{
	if (map[i][j] != ' ')
		return (1);
if(j < 0 && i < 0 && (map[i][j - 1] == '0' || map[i - 1][j] == '0'))
		return 0;
if(j + 1 < (int)ft_strlen(map[i]) && i + 1 < ft_matrixlen(map) &&
   (map[i][j + 1] == '0' || map[i + 1][j] == '0'))
		return 0;
	return (1);
}


int	valid_zero(char **map, int i, int j)
{
	if (map[i][j] != '0')
		return (1);
	if(j > (int)(ft_strlen(map[i - 1]) - 1) && j > (int)(ft_strlen(map[i + 1] - 1)))
		return 0;
	return (1);
}

int valid_top_bottom(char **map, int i, int j)
{
	while(map[i][j] && (map[i][j] == ' ' || map[i][j] == '\t'))
		j++;
	while(map[i][j])
	{
		if(map[i][j] != '1' && map[i][j] != ' ' && map[i][j] != '\t')
			return 0;
		j++;
	}
	return 1;
}

int valid_edge(char **map, int i, int j)
{
	int len;

	len = ft_strlen(map[i]) - 1;
	while(map[i][len] == ' ' || map[i][len] == '\t')
		len--;
	while(map[i][j] && (map[i][j] == ' ' || map[i][j] == '\t'))
		j++;
	if(map[i][j] != '1' || map[i][len] != '1')
	{
		printf("11111111111");
		return 0;
	}
	return 1;
}
