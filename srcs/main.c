/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcatarin <gcatarin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 16:31:05 by gcatarin          #+#    #+#             */
/*   Updated: 2024/06/03 17:47:43 by gcatarin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cubed.h"
#include "../minilibx-linux/mlx.h"	

t_data  *d(void)
{
	static t_data data;
	return(&data);
}

void valid_entry(int ac, char *str)
{
	if (ac != 2)
		error("Error\nWrong input -> ./cub3d [path_to_map]\n");
	if (ft_strlen(str) <= 4 )
		error("Error\nEmpty map name\n");
	while(*str && *str != '.')
		str++;
	if (ft_strcmp(str, ".cub") != 0)
		error("Error\nWrong file format -> [map.cub]\n");
}

void	assets(void *mlx_ptr)
{
	d()->img.wall = mlx_xpm_file_to_image(mlx_ptr, "textures/wall.xpm", \
	&d()->img.width, &d()->img.height);
	d()->img.empty = mlx_xpm_file_to_image(mlx_ptr, "textures/floor.xpm", \
	&d()->img.width, &d()->img.height);
	d()->img.collectible = mlx_xpm_file_to_image(mlx_ptr, "textures/collect.xpm", \
	&d()->img.width, &d()->img.height);
	d()->img.exit = mlx_xpm_file_to_image(mlx_ptr, "textures/exit.xpm", \
	&d()->img.width, &d()->img.height);
}

int main(int ac, char **av)
{
	valid_entry(ac, av[1]);
	parsing(av);

	d()->mlx = mlx_init();
	d()->win_ptr = mlx_new_window(d()->mlx, d()->map_x * 64 * 2, (d()->map_y - 1) * 64 * 2, "CUBED"); // cuidado com -1
	/*
	d()->img = mlx_new_image(d()->win_ptr, 250, 250);
	if (d()->img == NULL)
		return;

	d()->addr = (int *)mlx_get_data_addr(image.img, &image.bpp,
	&image.line_length, &image.endian);
 
	// Assign RGB value to a pixel
	image.addr[y * (image.line_length / 4) + x] = 0x00FF00;
	*/
	if (!d()->mlx || !d()->win_ptr)
		error("Error!\n Cub3d not initialized!\n");

	assets(d()->mlx);
	//mlx_hook(d()->win_ptr, 17, 0, destroy_hook, d);
	mlx_hook(d()->win_ptr,  2, 1L<<0, movekey_hook, &d);
	//mlx_key_hook(d()->win_ptr, movekey_hook, d);
	mlx_loop(d()->mlx);

}

