/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   media.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishaimou <ishaimou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 02:32:50 by ishaimou          #+#    #+#             */
/*   Updated: 2019/05/13 02:33:25 by ishaimou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

int		load_media(t_visual *v)
{
	SDL_Surface	*bg_img;

	bg_img = NULL;
	bg_img = IMG_Load("images/bg1.jpg");
	if (!bg_img)
	{
		printf("Unable to load image \"%s\" SDL_ERROR: %s\n", "bg1.jpg", IMG_GetError());
		return (0);
	}
	v->bg_tex = SDL_CreateTextureFromSurface(v->renderer, bg_img);
	SDL_FreeSurface(bg_img);
	bg_img = NULL;
	return (1);
}

int		load_audio(t_visual *v)
{
	SDL_AudioSpec		wav_spec;
	Uint32				wav_length;
	int					success;
		
	if (!SDL_LoadWAV("audio/Fantasia.wav", &wav_spec, &(v->wav_buffer), &wav_length))
	{
		printf("Could not open \"%s\" SDL_ERROR: %s\n", "Fantasia.wav", SDL_GetError()); 
		return (0);
	}
	v->device_id = SDL_OpenAudioDevice(NULL, 0, &wav_spec, NULL, 0);
	success = SDL_QueueAudio(v->device_id, v->wav_buffer, wav_length);
	return (1);
}
