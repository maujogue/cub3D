/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avaganay <avaganay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 13:54:47 by maujogue          #+#    #+#             */
/*   Updated: 2023/06/16 10:24:41 by avaganay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub.h"

int main(int argc, char **argv)
{
    t_all all;

    (void)argc;
    (void)argv;
    init_cub(&all);
    all.ray = malloc(sizeof(t_ray));
    init_ray(&all);
    ft_mlx(&all);
    free_exit(&all);
    return (0);
}
