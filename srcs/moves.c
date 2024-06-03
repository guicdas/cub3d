/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcatarin <gcatarin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 17:44:24 by gcatarin          #+#    #+#             */
/*   Updated: 2024/06/03 17:40:57 by gcatarin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cubed.h"

void	draw_map()
{	
	for(int y = 0; y < d()->map_y - 1; y++)
	{
		for(int x = 0; x <= d()->map_x - 1; x++)
		{
			if (d()->map[y][x] == '1')
				mlx_put_image_to_window(d()->mlx, d()->win_ptr, d()->img.wall, x * 64, y * 64);
			else if (d()->map[y][x] == 'C')
				mlx_put_image_to_window(d()->mlx, d()->win_ptr, d()->img.collectible, x * 64, y * 64);
			else if (d()->map[y][x] == 'E')
				mlx_put_image_to_window(d()->mlx, d()->win_ptr, d()->img.exit, x * 64, y * 64);
			else
				mlx_put_image_to_window(d()->mlx, d()->win_ptr, d()->img.empty, x * 64, y * 64);
		}
	}
}

int	check_move(int i, int j)
{
	if (d()->map[((int)d()->player_y + j)/64][(((int)d()->player_x +i )/64)] != 49)
		return 1;
	return 0;
}

void	move(int keypress)
{
	if (keypress == KEY_ESC)
		error("Error!\nExiting!\n");
	else if (keypress == KEY_A)	//LEFT
	{
		d()->player_a -= 0.1;
		if (d()->player_a < 0)
			d()->player_a += 2*PI;
		d()->player_dx = cos(d()->player_a)*5;
		d()->player_dy = sin(d()->player_a)*5;
	}
	else if (keypress == KEY_W && check_move(d()->player_dx, d()->player_dy) == 1)	//UP
	{
		d()->player_x += d()->player_dx;
		d()->player_y += d()->player_dy;
	}
	else if (keypress == KEY_D)	//RIGHT
	{
		d()->player_a += 0.1; 
		if (d()->player_a > 2*PI)
			d()->player_a -= 2*PI;
		d()->player_dx = cos(d()->player_a)*5;
		d()->player_dy = sin(d()->player_a)*5;
	}
	else if (keypress == KEY_S && check_move(-d()->player_dx, -d()->player_dy) == 1)	//DOWN
	{
		d()->player_x -= d()->player_dx;
		d()->player_y -= d()->player_dy;
	}
}

int	movekey_hook(int keypress)
{	
	/*
	draw_map();
	move(keypress);
	mlx_pixel_put(d()->mlx, d()->win_ptr, d()->player_x, d()->player_y, 0x00FF0000);
	draw_player_direction(d()->player_x, d()->player_y, 0x00FF0000);	
	draw_horizontal_rays();
	*/
	draw_rays();
	move(keypress);
	d()->frames++;
	return (0);
}
