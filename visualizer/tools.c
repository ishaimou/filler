/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishaimou <ishaimou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 00:26:45 by ishaimou          #+#    #+#             */
/*   Updated: 2019/05/24 23:16:30 by ishaimou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

t_dlist	*ft_dlst_new(void)
{
	t_dlist	*node;

	if (!(node = (t_dlist*)malloc(sizeof(t_dlist))))
		return (NULL);
	node->map = NULL;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

t_dlist	*ft_dlst_addnode(t_dlist **head)
{
	t_dlist	*tmp;

	if (!*head)
	{
		*head = ft_dlst_new();
		return (*head);
	}
	tmp = *head;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = ft_dlst_new();
	tmp->next->prev = tmp;
	return (tmp->next);
}

void	set_rectw(t_visual *v)
{
	if (v->map_h <= 15)
	{
		v->rect_w = 20;
		v->start_x = (SCREEN_WIDTH - v->map_w) / 3;
		v->start_y = (SCREEN_HEIGHT - v->map_h) / 4;
	}
	else if (v->map_h > 15 && v->map_h <= 24)
	{
		v->rect_w = 15;
		v->start_x = (SCREEN_WIDTH - v->map_w) / 5;
		v->start_y = (SCREEN_HEIGHT - v->map_h) / 4;
	}
	else if (v->map_h > 24 && v->map_h <= 100)
	{
		v->rect_w = 7;
		v->start_x = (SCREEN_WIDTH - v->map_w) / 7;
		v->start_y = (SCREEN_HEIGHT - v->map_h) / 5;
	}
}

/*
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
		if (!begin->map)
			i++;
		ft_printf("\n");
		print_map(begin->map);
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
*/
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
