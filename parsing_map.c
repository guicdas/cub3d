/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
<<<<<<< HEAD
/*   By: mneves-l <mneves-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 20:12:37 by mneves-l          #+#    #+#             */
/*   Updated: 2024/04/17 23:20:07 by mneves-l         ###   ########.fr       */
=======
/*   By: gcatarin <gcatarin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 20:12:37 by mneves-l          #+#    #+#             */
/*   Updated: 2024/04/29 17:56:29 by gcatarin         ###   ########.fr       */
>>>>>>> 3862364 (limpeza do codigo)
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

<<<<<<< HEAD
//debugging function that print tokens variables and the map
void    map_print(void)
{
    printf("------------ PARSING MAP_TOKENS -----------\n");
    printf("Value NO -> |%s|\n", (data()->map_NO));
    printf("Value SO -> |%s|\n", (data()->map_SO));
    printf("Value WE -> |%s|\n", (data()->map_WE));
    printf("Value EA -> |%s|\n", (data()->map_EA));
    printf("Value F  -> |%s|\n", (data()->map_F));
    printf("Value C  -> |%s|\n", (data()->map_C));
    printf("---------------- PRINT MAP ----------------\n");
    int i = 0;
    while(data()->map[i])
    {
        printf("MAP->|%s|\n", data()->map[i]);
        i++;
    }
    printf("------------------- MORE ------------------\n");
    //printf("data()->player_x = |%d|\n", data()->player_x);
    //printf("data()->player_y = |%d|\n", data()->player_y);
    //printf("data()->player_d = |%c|\n", data()->player_d);
}

//Malloc the map into data() using GET_NEXT_LINE
void    file_to_map(int fd)
{
    char *tmp;
    int flag;
    int i;

    flag = 0;
    i = 0;
    data()->map = (char **)malloc(sizeof(char *) * (data()->map_y + 1));
    //if (!data()->map)
    while ((tmp = get_next_line(fd)) != NULL)
    {
        if (flag == 1 && tmp[0] != '\n')
        {
            data()->map[i] = clean_string(tmp, 0, 0);
            i++;
        }
        if (check_for_token(tmp) == 6)
            flag = 1;
        free(tmp);
    }
    data()->map[i] = NULL;
=======
void	info_print(void)
{
	printf("------------ PARSING MAP_TOKENS -----------\n");
	printf("Value NO -> |%s|\n", (data()->map_NO));
	printf("Value SO -> |%s|\n", (data()->map_SO));
	printf("Value WE -> |%s|\n", (data()->map_WE));
	printf("Value EA -> |%s|\n", (data()->map_EA));
	printf("Value F  -> |%s|\n", (data()->map_F));
	printf("Value C  -> |%s|\n\n", (data()->map_C));
	// printf("data()->player_a = |%f|\n", data()->player_a);
	printf("player_pos [x][y]= |%c|[%f][%f]\n", data()->player_d, data()->player_x, data()->player_y);
}

void	map_print(void)
{
	printf("---------------- PRINT MAP ----------------\n");
	int i = 0;
	while(data()->map[i])
	{
		printf("MAP->|%s|\n", data()->map[i]);
		i++;
	}
	// printf("data()->player_a = |%f|\n", data()->player_a);
	printf("\nplayer_pos [x][y]= |%c|[%f][%f]\n", data()->player_d, data()->player_x, data()->player_y);
>>>>>>> 3862364 (limpeza do codigo)
}

//check for wrong chars in map matriz, and return a value
int     check_char(char c)
{
<<<<<<< HEAD
    if (c != '1' && c != '0' && c != 'N' && c != 'S' && c != 'W'
        && c != 'E' && c != ' ' && c != '\n')
        return(1);
    if ((c == 'N' || c == 'S' || c == 'W' || c == 'E'))
        return(2);
    else
        return(0);
=======
	if (c != '1' && c != '0' && c != 'N' && c != 'S' && c != 'W' \
	&& c != 'E' && c != ' ' && c != '\n')
		return(1);
	if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
		return(2);
	else
		return(0);
>>>>>>> 3862364 (limpeza do codigo)
}

//loop the entire matriz searching for chars errors, and save playerPOS
void    map_check_matriz(void)
{
<<<<<<< HEAD
    int x;
    int y;

    x = 0;
    y = 0;
    while (data()->map[y])
    {
        while(data()->map[y][x])
        {
            if (check_char(data()->map[y][x]) == 1)
            {
                printf("DEBUG check_char: |%c|\n", data()->map[y][x]);
                printf("Error in file_to_check()\n");
            }
            if (check_char(data()->map[y][x]) == 2)
            {
                data()->player_x = x;
                data()->player_y = y;
                data()->player_d = data()->map[y][x];
            } 
            x++;
        }
        x = 0;
        y++;        
    }
=======
	int x;
	int y;

	y = 0;
	while (data()->map[y])
	{
		x = 0;
		while(data()->map[y][x])
		{
			if (check_char(data()->map[y][x]) == 1)
			{
				printf("DEBUG check_char: |%c|\n", data()->map[y][x]);
				printf("Error in file_to_check()\n");
			}
			if (check_char(data()->map[y][x]) == 2)
			{
				data()->player_x = x;
				data()->player_y = y;
				data()->player_d = data()->map[y][x]; // necessario?
			} 
			x++;
		}
		y++;
	}
>>>>>>> 3862364 (limpeza do codigo)
}

//check if the map is surrounded and if have Player exit proportions
void    map_flood_fill(int x, int y, char **map, int size)
{
<<<<<<< HEAD
    if(y < 0 || y >= size || x < 0 || map[y][x] == '1' || map[y][x] == '-' || map[y][x] == 'P')
    {
        return;
    }
    if(ft_strlen(map[y]) <= x)
    {
        return;
    }
	if(map[y][x] == ' ')
    {
        printf("Flood_fill found a leak in the map[%d][%d]\n", y, x);
        return;
    }
    if(check_char(map[y][x]) == 2)
    {
        printf("Flood_fill found a Player[%d][%d]\n", y, x);
        map[y][x] = 'P';
    }
=======
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
>>>>>>> 3862364 (limpeza do codigo)
	if (map[y][x] == '0')
		map[y][x] = '-';
	map_flood_fill(x + 1, y, map, size); 
	map_flood_fill(x - 1, y, map, size);
	map_flood_fill(x, y + 1, map, size);
	map_flood_fill(x, y - 1, map, size);
}
