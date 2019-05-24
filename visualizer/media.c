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

void	write_score_p1(t_visual *v, int size)
{
	SDL_Rect	dstrect;
	SDL_Surface	*surface;
	SDL_Texture	*tex;
	char		*string;
	char		*score;
	
	score = ft_itoa(v->res_p1);
	string = ft_strjoin("Score: ", score);
	v->font = TTF_OpenFont(FONT, size);
	surface = TTF_RenderText_Solid(v->font, string, v->clrs[v->c].clr1);
	tex = SDL_CreateTextureFromSurface(v->renderer, surface);
	SDL_QueryTexture(tex, NULL, NULL, &dstrect.w, &dstrect.h);
	dstrect.x = (SCREEN_WIDTH - dstrect.w) / 6;
	dstrect.y = 3 * (SCREEN_HEIGHT - dstrect.h) / 20;
	SDL_RenderCopy(v->renderer, tex, NULL, &dstrect);
	SDL_FreeSurface(surface);
	SDL_DestroyTexture(tex);
	TTF_CloseFont(v->font);
	free(score);
	free(string);
}

void	write_score_p2(t_visual *v, int size)
{
	SDL_Rect	dstrect;
	SDL_Surface	*surface;
	SDL_Texture	*tex;
	char		*string;
	char		*score;
	
	score = ft_itoa(v->res_p2);
	string = ft_strjoin("Score: ", score);
	v->font = TTF_OpenFont(FONT, size);
	surface = TTF_RenderText_Solid(v->font, string, v->clrs[v->c].clr2);
	tex = SDL_CreateTextureFromSurface(v->renderer, surface);
	SDL_QueryTexture(tex, NULL, NULL, &dstrect.w, &dstrect.h);
	dstrect.x = 5 * (SCREEN_WIDTH - dstrect.w) / 6;
	dstrect.y = 3 * (SCREEN_HEIGHT - dstrect.h) / 20;
	SDL_RenderCopy(v->renderer, tex, NULL, &dstrect);
	SDL_FreeSurface(surface);
	SDL_DestroyTexture(tex);
	TTF_CloseFont(v->font);
	free(score);
	free(string);
}

void	write_winner(t_visual *v, int size)
{
	SDL_Rect	dstrect;
	char		*string;
	SDL_Texture	*tex;
	SDL_Surface	*surface;

	v->font = TTF_OpenFont(PL_FONT, size);
	if (v->res_p1 > v->res_p2)
	{
		string = ft_strjoin("WINNER IS ", v->p1_name);
		surface = TTF_RenderText_Solid(v->font, string, v->clrs[v->c].clr1);
	}
	else if (v->res_p2 > v->res_p1)
	{
		string = ft_strjoin("WINNER IS ", v->p2_name);
		surface = TTF_RenderText_Solid(v->font, string, v->clrs[v->c].clr2);
	}
	else
	{
		string = ft_strdup("Draw match");
		surface = TTF_RenderText_Solid(v->font, string, v->clr_vs);
	}	
	tex = SDL_CreateTextureFromSurface(v->renderer, surface);
	SDL_QueryTexture(tex, NULL, NULL, &dstrect.w, &dstrect.h);
	dstrect.x = (SCREEN_WIDTH - dstrect.w) / 2;
	dstrect.y = 8 * (SCREEN_HEIGHT - dstrect.h) / 10;
	SDL_RenderCopy(v->renderer, tex, NULL, &dstrect);
	SDL_FreeSurface(surface);
	SDL_DestroyTexture(tex);
	TTF_CloseFont(v->font);
	free(string);
}

void	capture_screen(t_visual *v)
{
	int			format;
	int			width;
	int			height;
	SDL_Surface	*surface;

	format = SDL_PIXELFORMAT_ARGB32;
	width = SCREEN_WIDTH;
	height = SCREEN_HEIGHT;
	surface = SDL_CreateRGBSurfaceWithFormat(0, width, height, 32, format);
	SDL_RenderReadPixels(v->renderer, NULL, format, surface->pixels, surface->pitch);
	IMG_SavePNG(surface, "screenshot.png");
	SDL_FreeSurface(surface);
	SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION,"Filler Visualizer",
		"Screenshot taken!\nCheck the project root folder\nEnjoy :)", v->window);
}

void	write_result(t_visual *v)
{
	write_score_p1(v, 38);
	write_score_p2(v, 38);
	write_winner(v, 38);
}
