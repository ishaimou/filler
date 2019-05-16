/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishaimou <ishaimou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 07:36:35 by ishaimou          #+#    #+#             */
/*   Updated: 2019/05/13 07:36:56 by ishaimou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

void	ft_sdlclose(t_visual *v)
{
	SDL_CloseAudioDevice(v->device_id);
	SDL_FreeWAV(v->wav_buffer);
	v->wav_buffer = NULL;
	SDL_DestroyTexture(v->bg_tex);
	SDL_DestroyTexture(v->p1_name_tex);
	SDL_DestroyTexture(v->p2_name_tex);
	v->bg_tex = NULL;
	SDL_DestroyRenderer(v->renderer);
	v->renderer = NULL;
	SDL_DestroyWindow(v->window);
	v->window = NULL;
	IMG_Quit();
	TTF_Quit();
	SDL_Quit();
}
