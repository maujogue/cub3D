/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maujogue <maujogue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 14:25:32 by maujogue          #+#    #+#             */
/*   Updated: 2023/06/21 11:15:23 by maujogue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub.h"

int	close_win(t_all *all)
{
	free_exit(all, 0, "");
	return (0);
}

int	ft_key(int keycode, t_all *all)
{
    (void)all;
    if (keycode == 65307)
    {
        exit(1);
    }
		// close_win(all);
	if (keycode == W_KEY)
	{
        // printf("W\n");
		move_nwes(all, 'N');
	}
	else if (keycode == S_KEY)
		move_nwes(all, 'S');
	else if (keycode == A_KEY)
		move_nwes(all, 'W');
        // printf("A\n");
		// ft_mouv(img, A_KEY);
	else if (keycode == D_KEY)
		move_nwes(all, 'E');
        // printf("D\n");
		// ft_mouv(img, D_KEY);
	// draw_map(all);
	// draw_cube(all,(int)all->ray->pos.x, (int)all->ray->pos.y, 'N');
	// refresh(all);
	return (0);
}

int	ft_mouse( int x, int y, t_all *all)
{
	(void)y;

	if (x > all->mouse_pos)
		move_nwes(all, 'E');
	else
		move_nwes(all, 'W');
	if (x > WIDTH || x < 0)
		x = WIDTH / 2;
	all->mouse_pos = x;
	return (0);
}