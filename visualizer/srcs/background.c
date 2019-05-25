/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   players.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishaimou <ishaimou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 04:16:51 by ishaimou          #+#    #+#             */
/*   Updated: 2019/05/25 04:26:37 by ishaimou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

int		load_bg(t_visual *v)
{
	SDL_Surface	*bg_img;
	SDL_Texture	*bg_tex;

	bg_img = NULL;
	bg_img = IMG_Load(BG_WALL);
	if (!bg_img)
	{
		printf("Unable to load image \"%s\" SDL_ERROR: %s\n", BG_WALL, IMG_GetError());
		return (0);
	}
	bg_tex = SDL_CreateTextureFromSurface(v->renderer, bg_img);
	SDL_RenderCopy(v->renderer, bg_tex, NULL, NULL);
	SDL_FreeSurface(bg_img);
	SDL_DestroyTexture(bg_tex);
	bg_img = NULL;
	return (1);
}

int		load_audio(t_visual *v)
{
	SDL_AudioSpec		wav_spec;
	Uint32				wav_length;
	int					success;
		
	if (!SDL_LoadWAV(BG_AUDIO, &wav_spec, &(v->wav_buffer), &wav_length))
	{
		printf("Could not open \"%s\" SDL_ERROR: %s\n", BG_AUDIO, SDL_GetError()); 
		return (0);
	}
	v->device_id = SDL_OpenAudioDevice(NULL, 0, &wav_spec, NULL, 0);
	success = SDL_QueueAudio(v->device_id, v->wav_buffer, wav_length);
	return (1);
}

int		write_p1(t_visual *v, int size)
{
	SDL_Surface	*surface;
	SDL_Texture	*tex;
	SDL_Rect	dstrect;

	v->font = TTF_OpenFont(PL_FONT, size);
	if (!v->font)
	{
		ft_printf("Could not open \"%s\" TTF_Error: %s\n", PL_FONT, TTF_GetError());
		return (0);
	}
	surface = TTF_RenderText_Solid(v->font, v->p1_name, v->clrs[v->c].clr1);
	tex = SDL_CreateTextureFromSurface(v->renderer, surface);
	SDL_QueryTexture(tex, NULL, NULL, &dstrect.w, &dstrect.h);
	dstrect.x = (SCREEN_WIDTH - dstrect.w) / 6;
	dstrect.y = (SCREEN_HEIGHT - dstrect.h) / 20;
	SDL_RenderCopy(v->renderer, tex, NULL, &dstrect);
	SDL_FreeSurface(surface);
	SDL_DestroyTexture(tex);
	TTF_CloseFont(v->font);
	return (1);
}

int		write_p2(t_visual *v, int size)
{
	SDL_Surface	*surface;
	SDL_Texture	*tex;
	SDL_Rect	dstrect;


	v->font = TTF_OpenFont(PL_FONT, size);
	if (!v->font)
	{
		ft_printf("Could not open \"%s\" TTF_Error: %s\n", PL_FONT, TTF_GetError());
		return (0);
	}
	surface = TTF_RenderText_Solid(v->font, v->p2_name, v->clrs[v->c].clr2);
	tex = SDL_CreateTextureFromSurface(v->renderer, surface);
	SDL_QueryTexture(tex, NULL, NULL, &dstrect.w, &dstrect.h);
	dstrect.x = 5 * (SCREEN_WIDTH - dstrect.w) / 6;
	dstrect.y = (SCREEN_HEIGHT - dstrect.h) / 20;
	SDL_RenderCopy(v->renderer, tex, NULL, &dstrect);
	SDL_FreeSurface(surface);
	SDL_DestroyTexture(tex);
	TTF_CloseFont(v->font);
	return (1);
}

int		write_vs(t_visual *v, int size)
{
	SDL_Surface	*surface;
	SDL_Texture	*tex;
	SDL_Rect	dstrect;

	v->font = TTF_OpenFont(VS_FONT, size);
	if (!v->font)
	{
		ft_printf("Could not open \"%s\" TTF_Error: %s\n", VS_FONT, TTF_GetError());
		return (0);
	}
	surface = TTF_RenderText_Solid(v->font, "VS", v->clr_vs);
	tex = SDL_CreateTextureFromSurface(v->renderer, surface);
	SDL_QueryTexture(tex, NULL, NULL, &dstrect.w, &dstrect.h);
	dstrect.x = (SCREEN_WIDTH - dstrect.w) / 2;
	dstrect.y = (SCREEN_HEIGHT - dstrect.h) / 20;
	SDL_RenderCopy(v->renderer, tex, NULL, &dstrect);
	SDL_FreeSurface(surface);
	SDL_DestroyTexture(tex);
	TTF_CloseFont(v->font);
	return (1);
}
