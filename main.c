/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
<<<<<<< HEAD
/*   By: mneves-l <mneves-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 20:13:44 by mneves-l          #+#    #+#             */
/*   Updated: 2024/04/17 20:13:53 by mneves-l         ###   ########.fr       */
=======
/*   By: gcatarin <gcatarin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 20:13:44 by mneves-l          #+#    #+#             */
/*   Updated: 2024/04/29 16:09:22 by gcatarin         ###   ########.fr       */
>>>>>>> 3862364 (limpeza do codigo)
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

t_data  *data(void)
{
<<<<<<< HEAD
    static t_data data;
    return(&data);
}

//function to simple check if you give a valid AC, exit program if false.
void is_ac_valid(int ac)
{
    if (ac != 2)
    {
        printf("Wrong format, you should use -> ./cub3D [path_to_map]\n");
        exit(0);
    }
=======
	static t_data data;
	return(&data);
}

//function to simple check if you give a valid AC, exit program if false.
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
>>>>>>> 3862364 (limpeza do codigo)
}

int main(int ac, char **av)
{
<<<<<<< HEAD
    is_ac_valid(ac);
    parsing(av);
    return(0);
=======
	valid_entry(ac, av[1]);
	parsing(av);
>>>>>>> 3862364 (limpeza do codigo)
}

