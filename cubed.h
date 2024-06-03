/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubed.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcatarin <gcatarin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 19:51:10 by mneves-l          #+#    #+#             */
/*   Updated: 2024/06/03 18:22:23 by gcatarin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include "minilibx-linux/mlx.h"
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <math.h>

# define KEY_W 119
# define KEY_D 100
# define KEY_S 115
# define KEY_A 97
# define KEY_ESC 65307

# define RED 0xE40000
# define GREEN 0x3BFC3B
# define YELLOW 0xF4FF49
# define ORANGE 0xff8000

# define screenH 120
# define screenW 120

# define PI 3.14159265359
# define DR 0.0174533

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 20
# endif

typedef struct s_img
{
	void	*empty;
	void	*wall;
	void	*collectible;
	void	*exit;
	int		height;
	int		width;
}t_img;

typedef struct s_data
{
	void	*mlx;
	void	*win_ptr;
	t_img	img;
	int		frames;
	
	void	*addr;

	char	*map_NO;
	char	*map_SO;
	char	*map_WE;
	char	*map_EA;
	char	*map_F;
	char	*map_C;
	int		map_x;
	int		map_y;
	char	**map;
	double	player_x;
	double	player_y;
	double	player_a;
	double	player_dx;
	double	player_dy;
}	t_data;

t_data	*d(void);

//get_next_line.c
char	*get_next_line(int fd);

//lib_utils.c
void	*ft_calloc(size_t nmemb, size_t size);
int		ft_strcmp(char *s1, char *s2);
int		ft_strlen(const char *str);
void	ft_putendl_fd(char *s, int fd);
void	error(char *s);

//parsing_dir.c
void    parsing(char **av);
void	load_map(int fd, int fd2);
int		check_for_element(char *s);
char    *clean_string(char *s, int i, int flag);

//parsing_map.c
void    map_print(void);
void	info_print(void);
int     check_char(char c);
void    map_check_matriz(void);
void    map_flood_fill(int x, int y, char **map, int size);

/////////////////
int		destroy_hook();
int		movekey_hook(int keypress);

void	draw_player_direction(int x1, int y1, int color);
void	draw_horizontal_rays();
void	draw_map();
void 	draw_rays();
void	draw_vertical_line(int x, int start, int end, int color);

//		LEAVE
void	error(char *s);
int		destroy_hook();
int		free_double(char **map);