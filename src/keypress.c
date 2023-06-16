/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avaganay <avaganay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 14:25:32 by maujogue          #+#    #+#             */
/*   Updated: 2023/06/16 10:37:47 by avaganay         ###   ########.fr       */
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
