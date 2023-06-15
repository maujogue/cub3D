/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avaganay <avaganay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 15:33:07 by avaganay          #+#    #+#             */
/*   Updated: 2023/06/15 12:46:46 by avaganay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub.h"

int	ft_key(int keycode, t_all *all)
{
    (void)all;
	if (keycode == W_KEY)
        printf("W\n");
		// ft_mouv(img, W_KEY);
	else if (keycode == S_KEY)
        printf("S\n");
		// ft_mouv(img, S_KEY);
	else if (keycode == A_KEY)
        printf("A\n");
		// ft_mouv(img, A_KEY);
	else if (keycode == D_KEY)
        printf("D\n");
		// ft_mouv(img, D_KEY);
	return (0);
}

void    ft_mlx(t_all *all)
{
    check_keypress(all);
    draw_map(all);
    mlx_put_image_to_window(all->mlx, all->mlx_win, all->data->img, 0, 0);
    mlx_hook(all->mlx_win, 2, (1L << 0), ft_key, &all);
    mlx_loop(all->mlx);
}