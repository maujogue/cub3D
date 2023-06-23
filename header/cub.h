/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maujogue <maujogue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 13:54:53 by maujogue          #+#    #+#             */
/*   Updated: 2023/06/23 13:54:36 by maujogue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include <math.h>
# include "../libft/libft.h"
# include "../minilibx_linux/mlx.h"

# include "typedef.h"

//-----------------------Init--------------//
void    init_cub(t_all *all, char *map);
void    init_ray(t_all *all);

//-----------------------FREE--------------//
void    free_exit(t_all *all, int exit_code, char *error_message);
void	free_array(char **tab);
void	free_lst(t_list *lst);
/**************************************Parsing**************************************/

void    parsing(t_all *all, char *map);
char    *get_lst_content(t_list *lst, char *key);
t_list  *file_to_lst(t_list *lst, int fd);
char	**lst_to_tab(t_list	*lst);

int     parse_color(t_all *all, t_list *lst, char *key);
int	    get_r(int trgb);
int	    get_g(int trgb);
int	    get_b(int trgb);

void	check_map(t_all *all);

int     ft_strlen_array(char **str);

/**************************************Free*****************************************/

//-----------------------Boucle--------------//

void	ft_mlx(t_all *all);
int     refresh(t_all *all);

//-----------------------MiniMAP--------------//

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	draw_minimap(t_all *all);
void	set_player_position(t_all *all);

//-----------------------KEYPRESS--------------//
int		close_win(t_all *all);
int		ft_mouse( int x, int y, t_all *all);
int		move_player(t_all *all);
int		key_release(int keycode, t_all *all);
int		key_press(int keycode, t_all *all);

//-----------------------RAYCASTING--------------//



#endif
