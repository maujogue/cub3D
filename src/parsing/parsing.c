/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maujogue <maujogue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 14:37:36 by maujogue          #+#    #+#             */
/*   Updated: 2023/06/15 16:26:59 by maujogue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub.h"

void    parsing(t_all *all, char *file)
{
    int     fd;
    t_list  *lst;
    
    all->pars = malloc(sizeof(t_pars));
    lst = NULL;
    fd = open(file, O_RDONLY);
    lst = file_to_lst(lst, fd);
    if (!lst)
        free_exit(all, 1, "Malloc Error\n");
    all->pars->north_wall = get_lst_content(lst, "NO ");
    all->pars->south_wall = get_lst_content(lst, "SO ");
    all->pars->west_wall = get_lst_content(lst, "WE ");
    all->pars->east_wall = get_lst_content(lst, "EA ");
    all->pars->ceiling_color = parse_color(all, lst, "C ");
    all->pars->floor_color = parse_color(all, lst, "F ");
    all->pars->map = lst_to_tab(lst);
}