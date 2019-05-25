/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishaimou <ishaimou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 04:57:59 by ishaimou          #+#    #+#             */
/*   Updated: 2019/05/25 05:31:41 by ishaimou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

void	draw_next(t_visual *v, t_dlist **begin)
{

	if (!(*begin)->next)
	{
		v->fin = 1;
		v->pause = 1;
		draw_background(v, *begin);
		write_result(v);
		SDL_RenderPresent(v->renderer);
	}
	if ((*begin)->next)
	{
		*begin = (*begin)->next;
		draw_background(v, *begin);
		SDL_RenderPresent(v->renderer);
	}
}

static void	draw_prev(t_visual *v, t_dlist **begin)
{
	if (v->fin)
	{
		draw_background(v, *begin);
		draw_curr(v, *begin);
		v->fin = !v->fin;
	}
	if ((*begin)->prev)
	{
		*begin = (*begin)->prev;
		draw_background(v, *begin);
		SDL_RenderPresent(v->renderer);
	}
}

static void	reset_game(t_visual *v, t_dlist **begin)
{
	(*begin) = v->lst;
	v->pause = 1;
	v->fin = 0;	
	draw_background(v, *begin);
	SDL_RenderPresent(v->renderer);
}

static void	change_color(t_visual *v, t_dlist *begin)
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

void	handle_keyevents(t_visual *v, t_dlist **begin)
{
	if (v->e.key.keysym.sym == SDLK_ESCAPE)
		v->close = 1;
	if (v->e.key.keysym.sym == SDLK_RIGHT)
		draw_next(v, begin);
	if (v->e.key.keysym.sym == SDLK_LEFT)
		draw_prev(v, begin);
	if (v->e.key.keysym.sym == SDLK_SPACE)
		v->pause = !v->pause;
	if (v->e.key.keysym.sym == SDLK_r)
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
}
