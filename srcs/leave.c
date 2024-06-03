/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   leave.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcatarin <gcatarin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 17:45:43 by gcatarin          #+#    #+#             */
/*   Updated: 2024/06/03 16:39:10 by gcatarin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cubed.h"

void	error(char *s)
{
	ft_putendl_fd(s, 2);
	free_double(d()->map);
	free(d()->map_EA);
	free(d()->map_F);
	free(d()->map_C);
	free(d()->map_SO);
	free(d()->map_NO);
	free(d()->map_WE);

	mlx_destroy_window(d()->mlx, d()->win_ptr);
	mlx_destroy_display(d()->mlx);
	free(d()->mlx);
	exit(1);
}

int	destroy_hook()
{
	error("\nexit");
	return (1);
}
