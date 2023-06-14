/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maujogue <maujogue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 14:25:32 by maujogue          #+#    #+#             */
/*   Updated: 2023/06/14 14:30:11 by maujogue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub.h"

int	close_win(t_all *all)
{
	free_exit(all);
	return (0);
}

int	ft_keypress(int keycode, t_all *all)
{
	if (keycode == 65307)
		close_win(all);
	// if (keycode == 119 && game->map[game->p_pos->y - 1][game->p_pos->x] != '1'
	// 	&& (game->map[game->p_pos->y - 1][game->p_pos->x] != 'E'
	// 		|| game->win == 1))
	// 	move_bro(game, 'U');
	// if (keycode == 115 && game->map[game->p_pos->y + 1][game->p_pos->x] != '1'
	// 	&& (game->map[game->p_pos->y + 1][game->p_pos->x] != 'E'
	// 		|| game->win == 1))
	// 	move_bro(game, 'D');
	// if (keycode == 97 && game->map[game->p_pos->y][game->p_pos->x - 1] != '1'
	// 	&& (game->map[game->p_pos->y][game->p_pos->x - 1] != 'E'
	// 		|| game->win == 1))
	// 	move_bro(game, 'L');
	// if (keycode == 100 && game->map[game->p_pos->y][game->p_pos->x + 1] != '1'
	// 	&& (game->map[game->p_pos->y][game->p_pos->x + 1] != 'E'
	// 		|| game->win == 1))
	// 	move_bro(game, 'R');
	// if (keycode == 100 || keycode == 97 || keycode == 115 || keycode == 119)
	// 	if (draw_count(game) == 1)
	// 		return (1);
	return (0);
}



void	check_keypress(t_all *all)
{
	mlx_hook(all->mlx_win, 17, 1L << 17, close_win, all);
	mlx_hook(all->mlx_win, 2, 1L << 0, ft_keypress, all);
}
