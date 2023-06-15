/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maujogue <maujogue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 13:54:53 by maujogue          #+#    #+#             */
/*   Updated: 2023/06/15 16:29:15 by maujogue         ###   ########.fr       */
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

void    init_cub(t_all *all, char *map);

void	check_keypress(t_all *all);

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

void    free_exit(t_all *all, int exit_code, char *error_message);
void	free_array(char **tab);
void	free_lst(t_list *lst);
#endif
