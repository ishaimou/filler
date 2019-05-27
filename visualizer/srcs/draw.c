/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishaimou <ishaimou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 08:18:12 by ishaimou          #+#    #+#             */
/*   Updated: 2019/05/27 05:00:28 by ishaimou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

void			draw_background(t_visual *v, t_dlist *begin)
{
	load_bg(v);
	write_p1(v, 38);
	write_p2(v, 38);
	write_vs(v, 50);
	draw_blackbg(v);
	draw_curr(v, begin);
}

void			draw_curr(t_visual *v, t_dlist *begin)
{
	int			i;
	int			j;

	i = 0;
	while (i < v->map_h)
	{
		j = 0;
		while (j < v->map_w)
		{
			draw_rect(v, begin, i, j);
			j++;
		}
		i++;
	}
}

void			draw_next(t_visual *v, t_dlist **begin)
{
	if (!(*begin)->next)
	{
		v->fin = 1;
		v->pause = 1;
		draw_background(v, *begin);
		write_result(v);
		SDL_RenderPresent(v->renderer);
	}
	if ((*begin)->next)
	{
		*begin = (*begin)->next;
		draw_background(v, *begin);
		SDL_RenderPresent(v->renderer);
	}
}

void			draw_prev(t_visual *v, t_dlist **begin)
{
	if (v->fin)
	{
		draw_background(v, *begin);
		draw_curr(v, *begin);
		v->fin = !v->fin;
	}
	if ((*begin)->prev)
	{
		*begin = (*begin)->prev;
		draw_background(v, *begin);
		SDL_RenderPresent(v->renderer);
	}
}

void			draw_result(t_visual *v, t_dlist **begin)
{
	while ((*begin)->next)
		*begin = (*begin)->next;
	draw_background(v, *begin);
	write_result(v);
	SDL_RenderPresent(v->renderer);
}
