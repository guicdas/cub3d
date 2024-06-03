/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_dir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcatarin <gcatarin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 19:46:55 by mneves-l          #+#    #+#             */
/*   Updated: 2024/06/03 16:39:31 by gcatarin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cubed.h"

//Save and check every imput before the game starts
void    parsing(char **av)
{
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
	map_flood_fill(d()->player_x, d()->player_y, d()->map, d()->map_y);
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
		if (d()->map_EA && d()->map_NO && d()->map_SO && d()->map_WE \
		&& d()->map_C && d()->map_F)
		{
			if (tmp[0] != '\n')
				d()->map_y++;
		}
		free(tmp);
	}
	d()->map = ft_calloc(sizeof(char **),d()->map_y); // o y tem que ser decrementado ent nao meter ( + 1)
	while ((tmp = get_next_line(fd2)) != NULL)
	{
		if (check_for_element(tmp) == 2 && tmp[0] != '\n')
			d()->map[i++] = clean_string(tmp, 0, 0);	
		free(tmp);
	}
	d()->map[i] = NULL;
}
//mexer nisto
int check_for_element(char *s)
{
	if (s && s[0])
	{
		if(s[0] == ' ' || s[0] == '\t')
			error("Error\nFound spaces before elements\n");
		if (s[0] == 'N' && s[1] == 'O')
		{	
			if (!d()->map_NO)
				d()->map_NO = clean_string(s, 2, 1);
		}
		else if (s[0] == 'S' && s[1] == 'O')
		{
			if (!d()->map_SO)
				d()->map_SO = clean_string(s, 2, 1);
		}
		else if (s[0] == 'W' && s[1] == 'E')
		{
			if (!d()->map_WE)
				d()->map_WE = clean_string(s, 2, 1);
		}
		else if (s[0] == 'E' && s[1] == 'A')
		{
			if (!d()->map_EA)
				d()->map_EA = clean_string(s, 2, 1);
		}
		else if (s[0] == 'F')
		{
			if (!d()->map_F)
				d()->map_F = clean_string(s, 1, 1);
		}
		else if (s[0] == 'C')
		{
			if (d()->map_C)
				free(d()->map_C);
			d()->map_C = clean_string(s, 1, 1);
		}
		else if (s[0] == '1')
			return (2);	// temporario, isto da erro provavelmente
		return (1);
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
    new = ft_calloc(sizeof(char *), i - start + 1);
    end = i;
    new[end + 1] = '\0';
    i = 0;
    while (start <= end)
        new[i++] = s[start++];
    return(new);
}
