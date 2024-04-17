/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mneves-l <mneves-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 20:12:37 by mneves-l          #+#    #+#             */
/*   Updated: 2024/04/17 23:20:07 by mneves-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

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
}

//check for wrong chars in map matriz, and return a value
int     check_char(char c)
{
    if (c != '1' && c != '0' && c != 'N' && c != 'S' && c != 'W'
        && c != 'E' && c != ' ' && c != '\n')
        return(1);
    if ((c == 'N' || c == 'S' || c == 'W' || c == 'E'))
        return(2);
    else
        return(0);
}

//loop the entire matriz searching for chars errors, and save playerPOS
void    map_check_matriz(void)
{
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
}

//check if the map is surrounded and if have Player exit proportions
void    map_flood_fill(int x, int y, char **map, int size)
{
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
	if (map[y][x] == '0')
		map[y][x] = '-';
	map_flood_fill(x + 1, y, map, size); 
	map_flood_fill(x - 1, y, map, size);
	map_flood_fill(x, y + 1, map, size);
	map_flood_fill(x, y - 1, map, size);
}
