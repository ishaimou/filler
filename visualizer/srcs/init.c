/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishaimou <ishaimou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 02:34:24 by ishaimou          #+#    #+#             */
/*   Updated: 2019/05/25 08:27:49 by ishaimou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

SDL_Color		init_rgbclr(int r, int g, int b, int a)
{
	SDL_Color	clr;

	clr.r = r;
	clr.g = g;
	clr.b = b;
	clr.a = a;
	return (clr);
}

void			init_color(t_visual *v)
{
	v->clrs[0].clr1 = init_rgbclr(93, 138, 168, 255);
	v->clrs[0].clr11 = init_rgbclr(124, 185, 232, 255);
	v->clrs[0].clr2 = init_rgbclr(196, 98, 16, 255);
	v->clrs[0].clr22 = init_rgbclr(255, 126, 0, 255);
	v->clrs[1].clr1 = init_rgbclr(171, 39, 79, 255);
	v->clrs[1].clr11 = init_rgbclr(241, 156, 187, 255);
	v->clrs[1].clr2 = init_rgbclr(59, 122, 87, 255);
	v->clrs[1].clr22 = init_rgbclr(90, 186, 133, 255);
	v->clrs[2].clr1 = init_rgbclr(145, 121, 0, 255);
	v->clrs[2].clr11 = init_rgbclr(204, 169, 0, 255);
	v->clrs[2].clr2 = init_rgbclr(81, 46, 115, 255);
	v->clrs[2].clr22 = init_rgbclr(145, 83, 207, 255);
}

void			init_visual(t_visual *v)
{
	v->font = NULL;
	v->window = NULL;
	v->renderer = NULL;
	v->wav_buffer = NULL;
	v->device_id = 0;
	v->clr_vs = init_rgbclr(239, 222, 205, 255);
	init_color(v);
	v->lst = NULL;
	v->map_h = 0;
	v->map_w = 0;
	v->rect_w = 0;
	v->c = 0;
	v->pause = 1;
	v->mute = 0;
	v->close = 0;
	v->fin = 0;
	v->start_x = 0;
	v->start_y = 0;
	v->p1_name = NULL;
	v->p2_name = NULL;
	v->res_p1 = 0;
	v->res_p2 = 0;
	v->flag = 0;
}

int				init_window(t_visual *v)
{
	v->window = SDL_CreateWindow("filler visualizer", SDL_WINDOWPOS_UNDEFINED,
			SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH,
			SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	if (v->window == NULL)
	{
		ft_printf("window could not be created! SDL_ERROR: %s\n",
				SDL_GetError());
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

int				init(t_visual *v)
{
	init_visual(v);
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
	if (TTF_Init() < 0)
	{
		ft_printf("TTF_INIT: %s\n", TTF_GetError());
		return (0);
	}
	if (!init_window(v))
		return (0);
	return (1);
}
