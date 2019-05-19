/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishaimou <ishaimou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 00:26:45 by ishaimou          #+#    #+#             */
/*   Updated: 2019/05/15 03:31:01 by ishaimou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

void	print_map(char **map)
{
	while (*map)
	{
		printf("%s\n", *map);
		map++;
	}
}

void	print_list(t_dlist *begin)
{
	int		i=0;
	while (begin)
	{
		if (!begin->map || !begin->pc)
			i++;
		print_map(begin->map);
		ft_printf("\n");
		print_map(begin->pc);
		ft_printf("\n");
		
		begin = begin->next;
	}
	printf("i=%d\n", i);
}

int		ft_list_size(t_dlist *begin_list)
{
	int		i;

	i = 0;
	while (begin_list)
	{
		begin_list = begin_list->next;
		i++;
	}
	return (i);
}

void	free_node(t_dlist **node)
{
	if (*node && (*node)->prev)
	{
		free(*node);
		(*node)->prev->next = NULL;
	}
}

void	free_dbl(char ***tab)
{
	int		i;

	i = 0;
	while ((*tab)[i])
	{
		free((*tab)[i]);
		i++;
	}
	free(*tab);
	*tab = NULL;
}

void	free_list(t_dlist **begin)
{
	t_dlist	*tmp;
	t_dlist	*current;
	
	current = *begin;
	while (current)
	{
		tmp = current;
		if (current->map)
			free_dbl(&(current->map));
		if (current->pc)
			free_dbl(&(current->pc));
		current = current->next;
		free(tmp);
	}
	*begin = NULL;
}

void	free_visual(t_visual *v)
{
	if (v->p1_name)
		free(v->p1_name);
	if (v->p2_name)
		free(v->p2_name);
}
