/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishaimou <ishaimou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 02:32:51 by ishaimou          #+#    #+#             */
/*   Updated: 2019/05/25 08:28:38 by ishaimou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

int				load_media(t_visual *v)
{
	if (!init(v))
	{
		ft_sdlclose(v);
		return (0);
	}
	if (!load_bg(v))
	{
		ft_sdlclose(v);
		return (0);
	}
	if (!load_audio(v))
	{
		ft_sdlclose(v);
		return (0);
	}
	return (1);
}

void			preset(t_visual *v, t_dlist **begin)
{
	*begin = v->lst;
	set_rectw(v);
	SDL_PauseAudioDevice(v->device_id, 0);
	draw_background(v, *begin);
	SDL_RenderPresent(v->renderer);
}

void			event_loop(t_visual *v, t_dlist **begin)
{
	while (SDL_PollEvent(&(v->e)))
	{
		if (v->e.type == SDL_QUIT)
			v->close = 1;
		if (v->e.type == SDL_KEYDOWN)
			handle_keyevents(v, begin);
	}
}

int				main(int argc, char *argv[])
{
	t_visual	v;
	t_dlist		*begin;

	(void)argc;
	(void)argv;
	if (!load_media(&v))
		return (0);
	if (!parser(&v))
		return (0);
	preset(&v, &begin);
	while (!v.close)
	{
		event_loop(&v, &begin);
		if (!v.pause)
		{
			draw_next(&v, &begin);
			SDL_Delay(1000 / 24);
		}
	}
	free_visual(&v);
	ft_sdlclose(&v);
	return (0);
}
