/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maujogue <maujogue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 15:33:07 by avaganay          #+#    #+#             */
/*   Updated: 2023/06/27 09:55:30 by maujogue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub.h"

void	ft_mlx(t_all *all)
{
	mlx_hook(all->mlx_win, 17, 1L << 17, close_win, all);
	mlx_hook(all->mlx_win, 2, (1L << 0), key_press, all);
	mlx_hook(all->mlx_win, 3, (1L << 1), key_release, all);
	mlx_hook(all->mlx_win, 6, (1L << 6), ft_mouse, all);
	mlx_loop_hook(all->mlx, refresh, all);
	mlx_loop(all->mlx);
}
