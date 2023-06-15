/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avaganay <avaganay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 14:25:32 by maujogue          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/06/15 12:46:04 by maujogue         ###   ########.fr       */
=======
/*   Updated: 2023/06/15 11:10:25 by avaganay         ###   ########.fr       */
>>>>>>> Axel
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub.h"

int	close_win(t_all *all)
{
	free_exit(all, 0, "");
	return (0);
}

int	ft_keypress(int keycode, t_all *all)
{
	if (keycode == 65307)
		close_win(all);
	// if (keycode == 119)
	// 	move_bro(all, 'U');
	// if (keycode == 115)
	// 	move_bro(all, 'D');
	// if (keycode == 97)
	// 	move_bro(all, 'L');
	// if (keycode == 100)
	// 	move_bro(all, 'R');
	return (0);
}

void	check_keypress(t_all *all)
{
	mlx_hook(all->mlx_win, 17, 1L << 17, close_win, all);
	mlx_hook(all->mlx_win, 2, 1L << 0, ft_keypress, all);
}
