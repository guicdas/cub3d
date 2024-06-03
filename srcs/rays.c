/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcatarin <gcatarin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 16:57:42 by gcatarin          #+#    #+#             */
/*   Updated: 2024/06/03 18:27:27 by gcatarin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cubed.h"

void	draw_vertical_line(int x, int start, int end, int color)
{
	while (start < end)
	{
		mlx_pixel_put(d()->mlx, d()->win_ptr, start, x, color);
		start += 2;
	}
}

void draw_rays(){
	
	for(int x = 0 ; x < 30 ; x++)
	{
		double rayDirX = d()->player_dx + 0 * 2 * x / (double)screenW - 1;
		double rayDirY = d()->player_dy + 0.66 * 2 * x / (double)screenW - 1;

		int mapX = (int)d()->player_x;
		int mapY = (int)d()->player_y;

		//length of ray from current position to next x or y-side
		double sideDistX;
		double sideDistY;

		double deltaDistX = (rayDirX == 0) ? 1e30 : fabs(1 / rayDirX);
		double deltaDistY = (rayDirY == 0) ? 1e30 : fabs(1 / rayDirY);
		printf("%d %f - %f\n", x, deltaDistX, deltaDistY);
		double perpWallDist;

		int stepX;
		int stepY;

		int side; //was a NS or a EW wall hit?
		
		if(rayDirX < 0)
		{
			stepX = -1;
			sideDistX = (d()->player_x - mapX) * deltaDistX;
		}
		else
		{
			stepX = 1;
			sideDistX = (mapX + 1.0 - d()->player_x) * deltaDistX;
		}
		if(rayDirY < 0)
		{
			stepY = -1;
			sideDistY = (d()->player_y - mapY) * deltaDistY;
		}
		else
		{
			stepY = 1;
			sideDistY = (mapY + 1.0 - d()->player_y) * deltaDistY;
		}
		while(1 == 1)
      	{
			if(sideDistX < sideDistY)
			{
				sideDistX += deltaDistX;
				mapX += stepX;
				side = 0;
			}
			else
			{
				sideDistY += deltaDistY;
				mapY += stepY;
				side = 1;
			}
			
			if (mapX > 0 && mapX < d()->map_x && mapY > 0 && mapY < d()->map_y)
			{
				if(d()->map[mapX][mapY] != 0)
					break;
			}
		}
		if(side == 0) 
			perpWallDist = (sideDistX - deltaDistX);
		else
			perpWallDist = (sideDistY - deltaDistY);

		int lineHeight = (int)(screenH / perpWallDist);
		int drawStart = -lineHeight / 2 + screenH / 2;
		if(drawStart < 0)
			drawStart = 0;
			
		int drawEnd = lineHeight / 2 + screenH / 2;
		if(drawEnd >= screenH)
			drawEnd = screenH - 1;
		
		draw_vertical_line(x, drawStart, drawEnd, RED);
	}

}