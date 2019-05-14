/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishaimou <ishaimou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 02:32:51 by ishaimou          #+#    #+#             */
/*   Updated: 2019/05/13 07:43:14 by ishaimou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

int		main(int argc, char *argv[])
{
	SDL_Event	event;
	t_visual	v;

	if (!init_visual(&v))
		return (0);
	if (!load_media(&v))
		return (0);
	if (!load_audio(&v))
		return (0);
	
	//Wait five seconds
	//SDL_Delay(5000);
	
	SDL_PauseAudioDevice(v.device_id, 0);
	while (1)
	{
		SDL_WaitEvent(&event);
		if (event.type == SDL_QUIT)
			break;
		SDL_RenderClear(v.renderer);
		SDL_RenderCopy(v.renderer, v.bg_tex, NULL, NULL);
		SDL_RenderPresent(v.renderer);
		if (!rec_game(&v))
			break;
	}
	ft_sdlclose(&v);
	return (0);
}
