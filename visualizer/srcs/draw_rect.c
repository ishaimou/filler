/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_rect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishaimou <ishaimou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 05:17:23 by ishaimou          #+#    #+#             */
/*   Updated: 2019/05/25 08:22:38 by ishaimou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

static void		draw_rect_cap_x(t_visual *v, SDL_Rect rect)
{
	SDL_SetRenderDrawColor(v->renderer,
		v->clrs[v->c].clr2.r, v->clrs[v->c].clr2.g,
		v->clrs[v->c].clr2.b, 255);
	SDL_RenderFillRect(v->renderer, &rect);
}

static void		draw_rect_x(t_visual *v, SDL_Rect rect)
{
	SDL_SetRenderDrawColor(v->renderer,
		v->clrs[v->c].clr22.r, v->clrs[v->c].clr22.g,
		v->clrs[v->c].clr22.b, 255);
	SDL_RenderFillRect(v->renderer, &rect);
}

static void		draw_rect_cap_o(t_visual *v, SDL_Rect rect)
{
	SDL_SetRenderDrawColor(v->renderer,
		v->clrs[v->c].clr1.r, v->clrs[v->c].clr1.g,
		v->clrs[v->c].clr1.b, 255);
	SDL_RenderFillRect(v->renderer, &rect);
}

static void		draw_rect_o(t_visual *v, SDL_Rect rect)
{
	SDL_SetRenderDrawColor(v->renderer,
		v->clrs[v->c].clr11.r, v->clrs[v->c].clr11.g,
		v->clrs[v->c].clr11.b, 255);
	SDL_RenderFillRect(v->renderer, &rect);
}

void			draw_rect(t_visual *v, t_dlist *begin, int i, int j)
{
	SDL_Rect	rect;

	rect.h = v->rect_w;
	rect.w = v->rect_w;
	rect.y = v->start_y + i * (rect.h + 1);
	rect.x = v->start_x + j * (rect.w + 1);
	if (begin->map[i][j] == 'X')
		draw_rect_cap_x(v, rect);
	else if (begin->map[i][j] == 'x')
		draw_rect_x(v, rect);
	else if (begin->map[i][j] == 'O')
		draw_rect_cap_o(v, rect);
	else if (begin->map[i][j] == 'o')
		draw_rect_o(v, rect);
	else if (begin->map[i][j] == '.')
	{
		SDL_SetRenderDrawColor(v->renderer, 180, 186, 196, 255);
		SDL_RenderFillRect(v->renderer, &rect);
	}
}
