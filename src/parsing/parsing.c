/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maujogue <maujogue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 14:37:36 by maujogue          #+#    #+#             */
/*   Updated: 2023/06/16 11:17:42 by maujogue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub.h"

void    parsing(t_all *all, char *file)
{
    int     fd;
    t_list  *lst;
    
    all->pars = malloc(sizeof(t_pars));
    if (!all->pars)
        free_exit(all, 1, "Malloc Error\n");
    lst = NULL;
    fd = open(file, O_RDONLY);
    if (fd == -1 || ft_strlen(ft_strnstr(file, ".cub", ft_strlen(file))) != 4)
		free_exit(all, 1, "Error\nCannot open map\n");
    lst = file_to_lst(lst, fd);
    if (!lst)
        free_exit(all, 1, "Malloc Error\n");
    all->pars->north_wall = get_lst_content(lst, "NO ");
    all->pars->south_wall = get_lst_content(lst, "SO ");
    all->pars->west_wall = get_lst_content(lst, "WE ");
    all->pars->east_wall = get_lst_content(lst, "EA ");
    all->pars->ceiling_color = parse_color(all, lst, "C ");
    all->pars->floor_color = parse_color(all, lst, "F ");
    printf("%d %d\n",all->pars->ceiling_color,all->pars->floor_color );
    all->pars->map = lst_to_tab(lst);
    if (!all->pars->north_wall || !all->pars->south_wall || !all->pars->east_wall
        || !all->pars->west_wall || !all->pars->map
        || all->pars->ceiling_color == (uint32_t)-1 || all->pars->floor_color == (uint32_t)-1)
        free_exit(all, 1, "Map error - missing map parameter\n");
}