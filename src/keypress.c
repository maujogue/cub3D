/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathisaujogue <mathisaujogue@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 14:25:32 by maujogue          #+#    #+#             */
/*   Updated: 2023/06/24 14:18:21 by mathisaujog      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub.h"

int	close_win(t_all *all)
{
	free_exit(all, 0, "");
	return (0);
}

int	key_press(int keycode, t_all *all)
{
	if (keycode == ESC_KEY)
        close_win(all);
    else if (keycode == W_KEY)
        all->keys[0] = 0;
    else if (keycode == S_KEY)
        all->keys[1] = 0;
    else if (keycode == A_KEY)
        all->keys[2] = 0;
    else if (keycode == D_KEY)
        all->keys[3] = 0;
	else if (keycode == L_ARROW)
        all->keys[4] = 0;
	else if (keycode == R_ARROW)
	{
        all->keys[5] = 0;
	}
	return (0);
}

int	key_release(int keycode, t_all *all)
{
    if (keycode == W_KEY)
        all->keys[0] = 1;
    else if (keycode == S_KEY)
        all->keys[1] = 1;
    else if (keycode == A_KEY)
        all->keys[2] = 1;
    else if (keycode == D_KEY)
        all->keys[3] = 1;
	else if (keycode == L_ARROW)
        all->keys[4] = 1;
	else if (keycode == R_ARROW)
	{
        all->keys[5] = 1;
	}
	return (0);
}

int	ft_mouse( int x, int y, t_all *all)
{
	(void)y;

	// if (x > all->mouse_pos)
	// 	move_nwes(all, 'E');
	// else
	// 	move_nwes(all, 'W');
	if (x > WIDTH || x < 0)
		x = WIDTH / 2;
	all->mouse_pos = x;
	return (0);
}