/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishaimou <ishaimou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 00:26:45 by ishaimou          #+#    #+#             */
/*   Updated: 2019/05/25 04:21:23 by ishaimou         ###   ########.fr       */
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

void	capture_screen(t_visual *v)
{
	int			format;
	int			width;
	int			height;
	SDL_Surface	*surface;

	format = SDL_PIXELFORMAT_RGBA32;
	width = SCREEN_WIDTH;
	height = SCREEN_HEIGHT;
	surface = SDL_CreateRGBSurfaceWithFormat(0, width, height, 32, format);
	SDL_RenderReadPixels(v->renderer, NULL, format, surface->pixels, surface->pitch);
	IMG_SavePNG(surface, "screenshot.png");
	SDL_FreeSurface(surface);
	SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION,"Filler Visualizer",
		"Screenshot taken!\nCheck the project root folder\nEnjoy :)", v->window);
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
