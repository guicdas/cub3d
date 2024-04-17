/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubed.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mneves-l <mneves-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 19:51:10 by mneves-l          #+#    #+#             */
/*   Updated: 2024/04/17 20:16:23 by mneves-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBED_H
# define CUBED_H

# include "./minilibx/mlx.h"
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <math.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 20
# endif

typedef struct s_data
{
    char *map_NO;
    char *map_SO;
    char *map_WE;
    char *map_EA;
    char *map_F;
    char *map_C;
    int  map_x;
    int  map_y;
    char **map;
    //parte para contar PCE flood_fill
    double player_x;
    double player_y;
    double player_a;
    char   player_d;
}	t_data;


t_data	*data(void);

//get_next_line.c
char	*get_next_line(int fd);

//lib_utils.c
int	ft_strcmp(char *s1, char *s2);
int	ft_strlen(const char *str);
void	ft_putendl_fd(char *s, int fd);
void	error(char *s);

//parsing_dir.c
void    parsing(char **av);
int file_settings(int fd);
int check_for_token(char *s);
char    *clean_string(char *s, int i, int flag);
void    start_token(char *s, int flag);

//parsing_map.c
int    file_is_cub(char *f);
void    map_print(void);
void    file_to_map(int fd);
int     check_char(char c);
void    map_check_matriz(void);
void    map_flood_fill(int x, int y, char **map, int size);




#endif