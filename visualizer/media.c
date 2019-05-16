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
	bg_img = IMG_Load("images/bg2.jpg");
	if (!bg_img)
	{
		printf("Unable to load image \"%s\" SDL_ERROR: %s\n", "bg2.jpg", IMG_GetError());
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

int		write_names(t_visual *v)
{
	TTF_Font	*font;
	SDL_Surface	*surface1;
	SDL_Surface *surface2;
	SDL_Rect	dstrect[2];

	dstrect[0].x = 65;
	dstrect[0].y = 5,
	dstrect[1].x = 460;
	dstrect[1].y = 5;
	font = TTF_OpenFont("fonts/got.ttf", 25);
	surface1 = TTF_RenderText_Solid(font, v->p1_name, v->clr1);
	surface2 = TTF_RenderText_Solid(font, v->p2_name, v->clr1);
	v->p1_name_tex = SDL_CreateTextureFromSurface(v->renderer, surface1);
	v->p2_name_tex = SDL_CreateTextureFromSurface(v->renderer, surface2);
	SDL_QueryTexture(v->p1_name_tex, NULL, NULL, &dstrect[0].w, &dstrect[0].h);
	SDL_QueryTexture(v->p2_name_tex, NULL, NULL, &dstrect[1].w, &dstrect[1].h);
	SDL_RenderCopy(v->renderer, v->p1_name_tex, NULL, &dstrect[0]);
	SDL_RenderCopy(v->renderer, v->p2_name_tex, NULL, &dstrect[1]);
	SDL_FreeSurface(surface1);
	SDL_FreeSurface(surface2);
	TTF_CloseFont(font);
	return (1);
}







