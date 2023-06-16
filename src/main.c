/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avaganay <avaganay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 13:54:47 by maujogue          #+#    #+#             */
/*   Updated: 2023/06/16 10:39:24 by avaganay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub.h"

int	main(int argc, char **argv)
{
	t_all	all;

	if (argc == 2)
	{
		init_cub(&all, argv[1]);
    	init_ray(&all);
    	ft_mlx(&all);
		free_exit(&all, 0, "");
	}
	return (0);
}
