/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishaimou <ishaimou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 02:32:51 by ishaimou          #+#    #+#             */
/*   Updated: 2019/05/25 01:10:15 by ishaimou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

int		main(int argc, char *argv[])
{
	t_visual	v;
	int			close;
	t_dlist		*begin;
	
	if (!init_visual(&v))
		return (0);
	if (!load_media(&v))
		return (0);
	if (!load_audio(&v))
		return (0);
	
	if (!parser(&v))
		return (0);
	begin = v.lst;
	set_rectw(&v);
	SDL_PauseAudioDevice(v.device_id, 0);
	draw_background(&v);
	draw_curr(&v, begin);
	SDL_RenderPresent(v.renderer);
	close = 0;
	while (!close)
	{
		while (SDL_PollEvent(&v.e))
		{
			if (v.e.type == SDL_QUIT)
				close = 1;
			if (v.e.type == SDL_KEYDOWN)
			{
				if (v.e.key.keysym.sym == SDLK_ESCAPE)
					close = 1;
				if (v.e.key.keysym.sym == SDLK_RIGHT)
					draw_next(&v, &begin);
				if (v.e.key.keysym.sym == SDLK_LEFT)
					draw_prev(&v, &begin);
				if (v.e.key.keysym.sym == SDLK_SPACE)
					v.pause = (v.pause) ? 0 : 1;
				if (v.e.key.keysym.sym == SDLK_r)
					reset_game(&v, &begin);
				if (v.e.key.keysym.sym == SDLK_c)
					change_color(&v, begin);
				if (v.e.key.keysym.sym == SDLK_s)
					capture_screen(&v);
				if (v.e.key.keysym.sym == SDLK_m)
				{
					v.mute = (v.mute) ? 0 : 1;
					SDL_PauseAudioDevice(v.device_id, v.mute);
				}
			}
		}
		if (!v.pause)
		{
			draw_next(&v, &begin);
			SDL_Delay(1000 / 24);
		}
	}
	ft_sdlclose(&v);
	return (0);
}
