/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   result.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishaimou <ishaimou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 04:05:25 by ishaimou          #+#    #+#             */
/*   Updated: 2019/05/25 04:15:52 by ishaimou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

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

SDL_Surface			*write_winner_surface(t_visual *v, int size)
{
	SDL_Surface		*surface;
	char			*string;

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
	free(string);
	TTF_CloseFont(v->font);
	return (surface);	
}

void	write_winner(t_visual *v, int size)
{
	SDL_Rect	dstrect;
	SDL_Texture	*tex;
	SDL_Surface	*surface;

	surface = write_winner_surface(v, size);
	tex = SDL_CreateTextureFromSurface(v->renderer, surface);
	SDL_QueryTexture(tex, NULL, NULL, &dstrect.w, &dstrect.h);
	dstrect.x = (SCREEN_WIDTH - dstrect.w) / 2;
	dstrect.y = 8 * (SCREEN_HEIGHT - dstrect.h) / 10;
	SDL_RenderCopy(v->renderer, tex, NULL, &dstrect);
	SDL_FreeSurface(surface);
	SDL_DestroyTexture(tex);
}

void	write_result(t_visual *v)
{
	write_score_p1(v, 38);
	write_score_p2(v, 38);
	write_winner(v, 38);
}
