/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avaganay <avaganay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 13:54:53 by maujogue          #+#    #+#             */
/*   Updated: 2023/06/15 15:39:21 by avaganay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include <math.h>
# include "../minilibx_linux/mlx.h"

# include "typedef.h"

//-----------------------Init--------------//
void    init_cub(t_all *all);
void    init_ray(t_all *all);

//-----------------------FREE--------------//

void    free_exit(t_all *all);

//-----------------------Boucle--------------//
void	ft_mlx(t_all *all);


//-----------------------MiniMAP--------------//

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	draw_map(t_all *all);

//-----------------------KEYPRESS--------------//
int	close_win(t_all *all);
int	ft_key(int keycode, t_all *all);

//-----------------------RAYCASTING--------------//
int	raycasting(t_all *all);



#endif
