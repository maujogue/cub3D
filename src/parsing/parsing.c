/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maujogue <maujogue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 14:37:36 by maujogue          #+#    #+#             */
/*   Updated: 2023/06/15 14:05:02 by maujogue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub.h"

char    *get_lst_content(t_list *lst, char *key)
{
    char    *content;
    char    *res;

    while (lst)
    {
        content = (char *)lst->content;
        res = ft_strnstr(content, key, ft_strlen(key));
        if (res)
        {
            res = ft_strtrim(res, key);
            if (!res)
                return (NULL);
            return (res);
        }
        lst = lst->next;
    }
    return (NULL);
    
}

t_list  *file_to_lst(t_list *lst, int fd)
{
    t_list  *node;
    char    *line;
    
    while (1)
    {
        line = get_next_line(fd);
        if (!line)
            break ;
        node = ft_lstnew(line);
        if (!node)
            return (NULL);
        ft_lstadd_back(&lst, node);
    }
    return (lst);
}

char	**lst_to_tab(t_list	*lst)
{
    char    **tab;
	int		i;

	i = 0;
    // printf("[%s]\n",ft_strchr(" 01", ((char *)lst->content)[0]) );
    while (ft_strchr(" 01", ((char *)lst->content)[0]) == NULL)
        lst = lst->next;
    tab = malloc(sizeof(char *) * (ft_lstsize(lst) + 1));
	while (lst)
	{
		tab[i]= ft_strtrim(lst->content, "\n ");
		if (!tab[i])
			return (free_array(tab), NULL);
		lst = lst->next;
        i++;
	}
	tab[i] = NULL;
	return (tab);
}

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
    // int i = -1;
    // while (all->pars->map[++i])
    //     printf("-->%s\n", all->pars->map[i]);
}