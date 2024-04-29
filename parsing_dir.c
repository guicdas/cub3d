/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_dir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
<<<<<<< HEAD
/*   By: mneves-l <mneves-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 19:46:55 by mneves-l          #+#    #+#             */
/*   Updated: 2024/04/17 23:20:01 by mneves-l         ###   ########.fr       */
=======
/*   By: gcatarin <gcatarin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 19:46:55 by mneves-l          #+#    #+#             */
/*   Updated: 2024/04/29 17:57:04 by gcatarin         ###   ########.fr       */
>>>>>>> 3862364 (limpeza do codigo)
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

//Save and check every imput before the game starts
void    parsing(char **av)
{
<<<<<<< HEAD
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
=======
	int	fd;
	int	fd2;

	fd = open(av[1], O_RDONLY , 0700);
	if (fd < 0)
		error("Error\nCouldn't open map\n");
	fd2 = open(av[1], O_RDONLY , 0700);
	if (fd2 < 0)
		error("Error\nCouldn't open map\n");
	load_map(fd, fd2);/*verificar o clean string*//*close fd1*/
	map_check_matriz();
	map_print();
	map_flood_fill(data()->player_x, data()->player_y, data()->map, data()->map_y);
	map_print();
	info_print();
}

void load_map(int fd, int fd2)
{
	char	*tmp;
	int		i;

	i = 0;
	while ((tmp = get_next_line(fd)) != NULL)
	{
		check_for_element(tmp);
		if (data()->map_EA && data()->map_NO && data()->map_SO && data()->map_WE \
		&& data()->map_C && data()->map_F)
		{
			if (tmp[0] != '\n')
				data()->map_y++;
		}
		free(tmp);
	}
	data()->map = ft_calloc(sizeof(char **),data()->map_y); // o y tem que ser decrementado ent nao meter ( + 1)
	while ((tmp = get_next_line(fd2)) != NULL)
	{
		if (check_for_element(tmp) == 2 && tmp[0] != '\n')
				data()->map[i++] = clean_string(tmp, 0, 0);	
		free(tmp);
	}
	data()->map[i] = NULL;
}
//function that searchs for tokens in the map
int check_for_element(char *s)
{
	if (s && s[0])
	{
		if(s[0] == ' ' || s[0] == '\t')
			error("Error\nFound spaces before elements\n");
		if (s[0] == 'N' && s[1] == 'O')
			data()->map_NO = clean_string(s, 2, 1);
		else if (s[0] == 'S' && s[1] == 'O')
			data()->map_SO = clean_string(s, 2, 1);
		else if (s[0] == 'W' && s[1] == 'E')
			data()->map_WE = clean_string(s, 2, 1);
		else if (s[0] == 'E' && s[1] == 'A')
			data()->map_EA = clean_string(s, 2, 1);
		else if (s[0] == 'F')
			data()->map_F = clean_string(s, 1, 1);
		else if (s[0] == 'C')
			data()->map_C = clean_string(s, 1, 1);
		else if (s[0] == '1')
			return (2);		// temporario, isto da erro provavelmente
		return (1);
	}
	return(0);
>>>>>>> 3862364 (limpeza do codigo)
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
<<<<<<< HEAD
    new = (char *)malloc(sizeof(char *) * (i - start + 1));
=======
    new = ft_calloc(sizeof(char *), i - start + 1);
>>>>>>> 3862364 (limpeza do codigo)
    end = i;
    new[end + 1] = '\0';
    i = 0;
    while (start <= end)
        new[i++] = s[start++];
    return(new);
}
<<<<<<< HEAD

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
=======
>>>>>>> 3862364 (limpeza do codigo)
