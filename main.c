/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mneves-l <mneves-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 20:13:44 by mneves-l          #+#    #+#             */
/*   Updated: 2024/04/17 20:13:53 by mneves-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

t_data  *data(void)
{
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
}

int main(int ac, char **av)
{
    is_ac_valid(ac);
    parsing(av);
    return(0);
}

