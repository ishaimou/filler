/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishaimou <ishaimou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 00:26:45 by ishaimou          #+#    #+#             */
/*   Updated: 2019/05/26 07:02:54 by ishaimou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

t_dlist			*ft_dlst_new(void)
{
	t_dlist	*node;

	if (!(node = (t_dlist*)malloc(sizeof(t_dlist))))
		return (NULL);
	node->map = NULL;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

t_dlist			*ft_dlst_addnode(t_dlist **head)
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

void			set_rectw(t_visual *v)
{
	if (v->map_h <= 15)
	{
		v->rect_w = 30;
		v->start_x = 2 * (SCREEN_WIDTH - v->map_w) / 7;
		v->start_y = (SCREEN_HEIGHT - v->map_h) / 4;
	}
	else if (v->map_h > 15 && v->map_h <= 24)
	{
		v->rect_w = 20;
		v->start_x = (SCREEN_WIDTH - v->map_w) / 5;
		v->start_y = (SCREEN_HEIGHT - v->map_h) / 4;
	}
	else if (v->map_h > 24 && v->map_h <= 100)
	{
		v->rect_w = 6;
		v->start_x = (SCREEN_WIDTH - v->map_w) / 4;
		v->start_y = (SCREEN_HEIGHT - v->map_h) / 5;
	}
}

SDL_Color		init_rgbclr(int r, int g, int b, int a)
{
	SDL_Color	clr;

	clr.r = r;
	clr.g = g;
	clr.b = b;
	clr.a = a;
	return (clr);
}
