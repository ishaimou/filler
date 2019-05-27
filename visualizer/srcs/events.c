/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishaimou <ishaimou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 04:57:59 by ishaimou          #+#    #+#             */
/*   Updated: 2019/05/27 05:00:06 by ishaimou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

static void		capture_screen(t_visual *v)
{
	int			format;
	int			width;
	int			height;
	SDL_Surface	*surface;

	format = SDL_PIXELFORMAT_RGBA32;
	width = SCREEN_WIDTH;
	height = SCREEN_HEIGHT;
	surface = SDL_CreateRGBSurfaceWithFormat(0, width, height, 32, format);
	SDL_RenderReadPixels(v->renderer, NULL,
			format, surface->pixels, surface->pitch);
	IMG_SavePNG(surface, "screenshot.png");
	SDL_FreeSurface(surface);
	SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, "Filler Visualizer",
		"Screenshot taken!\nCheck the project root folder\nEnjoy :)",
		v->window);
}

static void		change_speed(t_visual *v)
{
	if (v->e.key.keysym.sym == SDLK_UP && v->s < 7)
		v->s++;
	if (v->e.key.keysym.sym == SDLK_DOWN && v->s > 0)
		v->s--;
}

static void		reset_game(t_visual *v, t_dlist **begin)
{
	(*begin) = v->lst;
	v->pause = 1;
	v->fin = 0;
	draw_background(v, *begin);
	SDL_RenderPresent(v->renderer);
}

static void		change_color(t_visual *v, t_dlist *begin)
{
	if (v->c == 2)
		v->c = 0;
	else
		v->c++;
	draw_background(v, begin);
	if (v->fin)
		write_result(v);
	SDL_RenderPresent(v->renderer);
}

void			handle_keyevents(t_visual *v, t_dlist **begin)
{
	if (v->e.key.keysym.sym == SDLK_ESCAPE)
		v->close = 1;
	if (v->e.key.keysym.sym == SDLK_RIGHT)
		draw_next(v, begin);
	if (v->e.key.keysym.sym == SDLK_LEFT)
		draw_prev(v, begin);
	if (v->e.key.keysym.sym == SDLK_SPACE)
		v->pause = !v->pause;
	if (v->e.key.keysym.sym == SDLK_BACKSPACE)
		reset_game(v, begin);
	if (v->e.key.keysym.sym == SDLK_c)
		change_color(v, *begin);
	if (v->e.key.keysym.sym == SDLK_s)
		capture_screen(v);
	if (v->e.key.keysym.sym == SDLK_m)
	{
		v->mute = !v->mute;
		SDL_PauseAudioDevice(v->device_id, v->mute);
	}
	if (v->e.key.keysym.sym == SDLK_UP)
		change_speed(v);
	if (v->e.key.keysym.sym == SDLK_DOWN)
		change_speed(v);
	if (v->e.key.keysym.sym == SDLK_r)
		draw_result(v, begin);
}
