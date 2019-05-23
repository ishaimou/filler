/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   media.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishaimou <ishaimou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 02:32:50 by ishaimou          #+#    #+#             */
/*   Updated: 2019/05/21 05:53:12 by ishaimou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

int		load_media(t_visual *v)
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

int		write_p1(t_visual *v)
{
	TTF_Font	*font;
	SDL_Surface	*surface1;
	SDL_Texture	*p1_name_tex;
	SDL_Rect	dstrect;

	font = TTF_OpenFont(PL_FONT, 38);
	if (!font)
	{
		ft_printf("Could not open \"%s\" TTF_Error: %s\n", PL_FONT, TTF_GetError());
		return (0);
	}
	surface1 = TTF_RenderText_Solid(font, v->p1_name, v->clrs[v->c].clr1);
	p1_name_tex = SDL_CreateTextureFromSurface(v->renderer, surface1);
	SDL_QueryTexture(p1_name_tex, NULL, NULL, &dstrect.w, &dstrect.h);
	dstrect.x = (SCREEN_WIDTH - dstrect.w) / 6;
	dstrect.y = (SCREEN_HEIGHT - dstrect.h) / 20;
	SDL_RenderCopy(v->renderer, p1_name_tex, NULL, &dstrect);
	SDL_FreeSurface(surface1);
	SDL_DestroyTexture(p1_name_tex);
	TTF_CloseFont(font);
	return (1);
}

int		write_p2(t_visual *v)
{
	TTF_Font	*font;
	SDL_Surface	*surface2;
	SDL_Texture	*p2_name_tex;
	SDL_Rect	dstrect;


	font = TTF_OpenFont(PL_FONT, 38);
	if (!font)
	{
		ft_printf("Could not open \"%s\" TTF_Error: %s\n", PL_FONT, TTF_GetError());
		return (0);
	}
	surface2 = TTF_RenderText_Solid(font, v->p2_name, v->clrs[v->c].clr2);
	p2_name_tex = SDL_CreateTextureFromSurface(v->renderer, surface2);
	SDL_QueryTexture(p2_name_tex, NULL, NULL, &dstrect.w, &dstrect.h);
	dstrect.x = 5 * (SCREEN_WIDTH - dstrect.w) / 6;
	dstrect.y = (SCREEN_HEIGHT - dstrect.h) / 20;
	SDL_RenderCopy(v->renderer, p2_name_tex, NULL, &dstrect);
	SDL_FreeSurface(surface2);
	SDL_DestroyTexture(p2_name_tex);
	TTF_CloseFont(font);
	return (1);
}

int		write_vs(t_visual *v)
{
	TTF_Font	*font;
	SDL_Surface	*surface;
	SDL_Texture	*vs_tex;
	SDL_Rect	dstrect;

	font = TTF_OpenFont(VS_FONT, 48);
	if (!font)
	{
		ft_printf("Could not open \"%s\" TTF_Error: %s\n", VS_FONT, TTF_GetError());
		return (0);
	}
	surface = TTF_RenderText_Solid(font, "VS", v->clr_vs);
	vs_tex = SDL_CreateTextureFromSurface(v->renderer, surface);
	SDL_QueryTexture(vs_tex, NULL, NULL, &dstrect.w, &dstrect.h);
	dstrect.x = (SCREEN_WIDTH - dstrect.w) / 2;
	dstrect.y = (SCREEN_HEIGHT - dstrect.h) / 20;
	SDL_RenderCopy(v->renderer, vs_tex, NULL, &dstrect);
	SDL_FreeSurface(surface);
	SDL_DestroyTexture(vs_tex);
	TTF_CloseFont(font);
	return (1);
}





