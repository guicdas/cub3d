/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcatarin <gcatarin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 20:12:37 by mneves-l          #+#    #+#             */
/*   Updated: 2024/06/03 16:39:33 by gcatarin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cubed.h"

void	info_print(void)
{
	printf("------------ PARSING MAP_TOKENS -----------\n");
	printf("Value NO -> |%s|\n", (d()->map_NO));
	printf("Value SO -> |%s|\n", (d()->map_SO));
	printf("Value WE -> |%s|\n", (d()->map_WE));
	printf("Value EA -> |%s|\n", (d()->map_EA));
	printf("Value F  -> |%s|\n", (d()->map_F));
	printf("Value C  -> |%s|\n\n", (d()->map_C));
	printf("player_pos [x][y]= [%f][%f]\n", d()->player_x, d()->player_y);
}

void	map_print(void)
{
	int i = 0;
	
	while(d()->map[i])
	{
		int j = 0;
		while (j < d()->map_x )
			printf("[%d%d] - ", j++, i);
		printf("\n");
		i++;
	}
}

//check for wrong chars in map matriz, and return a value
int     check_char(char c)
{
	if (c != '1' && c != '0' && c != 'N' && c != 'S' && c != 'W' \
	&& c != 'E' && c != ' ' && c != '\n')
		return(1);
	if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
		return(2);
	else
		return(0);
}

//loop the entire matriz searching for chars errors, and save playerPOS
void    map_check_matriz(void)
{
	int x;
	int y;

	y = 0;
	while (d()->map[y])
	{
		x = 0;
		while(d()->map[y][x])
		{
			if (check_char(d()->map[y][x]) == 1)
				error("Error in file_to_check()\n");//printf("DEBUG check_char: |%c|\n", d()->map[y][x]);
			if (check_char(d()->map[y][x]) == 2)
			{
				d()->player_x = x*64;
				d()->player_y = y*64;
				d()->player_a = 0;
				d()->player_dx = cos(d()->player_a)*5;
				d()->player_dy = sin(d()->player_a)*5;
			}
			x++;
		//	if (ft_strlen(d()->map[y]) != d()->map_x) //verificar se funciona
			//	error("Error\nMap must be rectangular!"); // segfault
		}
		y++;
	}
	d()->map_x = ft_strlen(d()->map[y - 1]);
}

//check if the map is surrounded and if have Player exit proportions
void    map_flood_fill(int x, int y, char **map, int size)
{
	if (y < 0 || y >= size || x < 0 || map[y][x] == '1' \
	|| map[y][x] == '-' || map[y][x] == 'P')
		return ;
	if (ft_strlen(map[y]) <= x)
		return ;
	if (map[y][x] == ' ')
	{
		printf("Flood_fill found a leak in the map[%d][%d]\n", y, x);
		return;
	}
	if(check_char(map[y][x]) == 2)
	{
		printf("Flood_fill found a Player[%d][%d]\n", y, x);
		map[y][x] = 'P';
	}
	if (map[y][x] == '0')
		map[y][x] = '-';
	map_flood_fill(x + 1, y, map, size); 
	map_flood_fill(x - 1, y, map, size);
	map_flood_fill(x, y + 1, map, size);
	map_flood_fill(x, y - 1, map, size);
}
