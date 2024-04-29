/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubed.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
<<<<<<< HEAD
/*   By: mneves-l <mneves-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 19:51:10 by mneves-l          #+#    #+#             */
/*   Updated: 2024/04/17 20:16:23 by mneves-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBED_H
# define CUBED_H

# include "./minilibx/mlx.h"
=======
/*   By: gcatarin <gcatarin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 19:51:10 by mneves-l          #+#    #+#             */
/*   Updated: 2024/04/29 17:56:50 by gcatarin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include "./minilibx-linux/mlx.h"
>>>>>>> 3862364 (limpeza do codigo)
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
<<<<<<< HEAD
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


=======
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

>>>>>>> 3862364 (limpeza do codigo)
t_data	*data(void);

//get_next_line.c
char	*get_next_line(int fd);

//lib_utils.c
<<<<<<< HEAD
int	ft_strcmp(char *s1, char *s2);
int	ft_strlen(const char *str);
=======
void	*ft_calloc(size_t nmemb, size_t size);
int		ft_strcmp(char *s1, char *s2);
int		ft_strlen(const char *str);
>>>>>>> 3862364 (limpeza do codigo)
void	ft_putendl_fd(char *s, int fd);
void	error(char *s);

//parsing_dir.c
void    parsing(char **av);
<<<<<<< HEAD
int file_settings(int fd);
int check_for_token(char *s);
char    *clean_string(char *s, int i, int flag);
void    start_token(char *s, int flag);

//parsing_map.c
int    file_is_cub(char *f);
void    map_print(void);
void    file_to_map(int fd);
=======
void	load_map(int fd, int fd2);
int		check_for_element(char *s);
char    *clean_string(char *s, int i, int flag);

//parsing_map.c
void    map_print(void);
void	info_print(void);
>>>>>>> 3862364 (limpeza do codigo)
int     check_char(char c);
void    map_check_matriz(void);
void    map_flood_fill(int x, int y, char **map, int size);

<<<<<<< HEAD



#endif
=======
>>>>>>> 3862364 (limpeza do codigo)
