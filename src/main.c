/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avaganay <avaganay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 13:54:47 by maujogue          #+#    #+#             */
/*   Updated: 2023/06/15 15:38:44 by avaganay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub.h"

int main(int argc, char **argv)
{
    t_all all;

    (void)argc;
    (void)argv;
    init_cub(&all);
    init_ray(&all);
    ft_mlx(&all);
    free_exit(&all);
    return (0);
}
