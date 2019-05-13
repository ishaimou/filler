/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishaimou <ishaimou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 02:34:24 by ishaimou          #+#    #+#             */
/*   Updated: 2019/05/13 07:45:34 by ishaimou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

static int		init(t_visual *v)
{
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0)
	{
		ft_printf("SDL could not initialize! SDL_ERROR: %s\n", SDL_GetError());
		return (0);
	}
	if (IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG) < 0)
	{
		ft_printf("IMG_init: %s\n", IMG_GetError());
		return (0);
	}
	v->window = SDL_CreateWindow("Filler Visualizer", SDL_WINDOWPOS_UNDEFINED,
			SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_RESIZABLE);
	if (v->window == NULL)
	{
		ft_printf("Window could not be created! SDL_ERROR: %s\n", SDL_GetError());
		return (0);
	}
	v->renderer = SDL_CreateRenderer(v->window, -1, SDL_RENDERER_ACCELERATED);
	if (v->renderer == NULL)
	{
		ft_printf("SDL_CreateRenderer: %s\n", SDL_GetError());
		return (0);
	}
	return (1);
}

int		init_visual(t_visual *v)
{
	v->window = NULL;
	v->renderer = NULL;
	v->bg_tex = NULL;
	v->wav_buffer = NULL;
	v->device_id = 0;
	v->lst = NULL;
	v->map_h = 0;
	v->map_w = 0;
	v->p1_name = NULL;
	v->p2_name = NULL;
	if (!init(v))
		return (0);
	return (1);
}
