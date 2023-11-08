/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mneri <mneri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 15:20:20 by mneri             #+#    #+#             */
/*   Updated: 2023/11/08 16:14:23 by mneri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int main(int argc, char **argv)
{
	t_game g;

	if(argc == 2)
	{
		int i =0;
		if(!check_map(argv[1], &g))
			printf("Error\n");
		char **map;
		map = check_open_map(argv[1]);
		while(map[i])
			printf("%s\n", map[i++]);
		printf("%s\n", g.EA);
		printf("%s\n", g.WE);
		printf("%s\n", g.SO);
		printf("%s\n", g.NO);
		printf("%s\n", g.F);
		printf("%s\n", g.C);
	}
}