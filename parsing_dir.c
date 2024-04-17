/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_dir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mneves-l <mneves-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 19:46:55 by mneves-l          #+#    #+#             */
/*   Updated: 2024/04/17 23:20:01 by mneves-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

//Save and check every imput before the game starts
void    parsing(char **av)
{
    if (file_is_cub(av[1]))
        error("Wrong file format, try again");
    file_settings(open(av[1], O_RDONLY));
    file_to_map(open(av[1], O_RDONLY));
    map_check_matriz();
    map_flood_fill(data()->player_x, data()->player_y, data()->map, data()->map_y);
    map_print();
}

//check and save the texture paths give by the map using GET_NEXT_LINE
//and count and save the map_y for future processing "flag and data()->"
int file_settings(int fd)
{
    char *tmp;
    int flag;
    
    flag = 0;
    if (fd < 0)
        return(0);
    while ((tmp = get_next_line(fd)) != NULL)
    {
        if(check_for_token(tmp) > 0)
        {
           start_token(tmp, check_for_token(tmp));
           if (check_for_token(tmp) == 6)
                flag = 1;
        }
        if (flag == 1)
            data()->map_y = data()->map_y + 1;
        free(tmp);
    }
    return (1);
}
//function that searchs for tokens in the map
int check_for_token(char *s)
{
  
    if (s && s[0])
    {
        if(s[0] == ' ' || s[0] == '\t')
            error("Too many spaces, remove please!");
        if (s[0] == 'N' && s[1] == 'O')
            return (1);
        else if (s[0] == 'S' && s[1] == 'O')
            return (2);
        else if (s[0] == 'W' && s[1] == 'E')
            return (3);
        else if (s[0] == 'E' && s[1] == 'A')
            return (4);
        else if (s[0] == 'F')
            return (5);
        else if (s[0] == 'C')
            return (6);
    }
    return(0);
}

//cut white spaces from the begginig and/or from the end of a string
char    *clean_string(char *s, int i, int flag)
{
    int start;
    int end;
    char *new;

    if (flag == 1)
    {
        while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
            i++;
        start = i;
    }
    else
        start = 0;
    i = ft_strlen(s) - 1;
    while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
        i--;
    new = (char *)malloc(sizeof(char *) * (i - start + 1));
    end = i;
    new[end + 1] = '\0';
    i = 0;
    while (start <= end)
        new[i++] = s[start++];
    return(new);
}

//choose the varible to store the clean_string()
void    start_token(char *s, int flag)
{   
    //printf("start token = |%s|\n", s);
    if (flag == 1)
        data()->map_NO = clean_string(s, 2, 1);
    else if (flag == 2)
        data()->map_SO = clean_string(s, 2, 1);
    else if (flag == 3)
        data()->map_WE = clean_string(s, 2, 1);
    else if (flag == 4)
        data()->map_EA = clean_string(s, 2, 1);
    else if (flag == 5)
        data()->map_F = clean_string(s, 1, 1);
    else if (flag == 6)
        data()->map_C = clean_string(s, 1, 1);
}

//check if the file is .cub
int    file_is_cub(char *f)
{
    int i;
    
    i = 0;
    while(f && f[i])
        i++;
    i--;
    if  (f[i] && (f[i] == 'b' && f[i - 1] == 'u' && f[i - 2] == 'c' && f[i - 3] == '.'))
        return(0);
    else
        return(1);
}
