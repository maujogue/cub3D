/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maujogue <maujogue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 14:37:36 by maujogue          #+#    #+#             */
/*   Updated: 2023/06/26 14:09:13 by maujogue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub.h"

void    parsing(t_all *all, char *file)
{
	int     fd;
	t_list  *lst;
	
	lst = NULL;
	fd = open(file, O_RDWR);
	if (fd < 0 || ft_strlen(ft_strnstr(file, ".cub", ft_strlen(file))) != 4
		|| ft_strchr(ft_strchr(file, '.') + 1, '.') != NULL)
		free_exit(all, 1, "Error\nCannot open map\n");
	lst = file_to_lst(lst, fd);
	if (!lst)
		free_exit(all, 1, "Malloc Error\n");
	all->pars.north_wall = get_lst_content(lst, "NO ");
	all->pars.south_wall = get_lst_content(lst, "SO ");
	all->pars.west_wall = get_lst_content(lst, "WE ");
	all->pars.east_wall = get_lst_content(lst, "EA ");
	all->pars.ceiling_color = parse_color(all, lst, "C ");
	all->pars.floor_color = parse_color(all, lst, "F ");
	all->pars.map = lst_to_tab(lst);
	if (all->pars.ceiling_color == (uint32_t)-2 || all->pars.floor_color == (uint32_t)-2)
		free_exit(all, 1, "Error\nMap - invalid color \n");
	if (!all->pars.north_wall || !all->pars.south_wall || !all->pars.east_wall
		|| !all->pars.west_wall || !all->pars.map
		|| all->pars.ceiling_color == (uint32_t)-1 || all->pars.floor_color == (uint32_t)-1)
		free_exit(all, 1, "Error\nMap - missing or duplicate parameter\n");
	free_lst(lst);
}