/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maujogue <maujogue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 13:54:47 by maujogue          #+#    #+#             */
/*   Updated: 2023/06/15 12:46:11 by maujogue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub.h"

int	main(int argc, char **argv)
{
	t_all	all;

	if (argc == 2)
	{
		init_cub(&all, argv[1]);
		check_keypress(&all);
		mlx_loop(all.mlx);
		free_exit(&all, 0, "");
	}
	return (0);
}
