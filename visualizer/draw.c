#include "visualizer.h"

void	draw_blank(t_visual *v)
{
	int			i;
	int			j;
	SDL_Rect	rect;

	i = 0;
	set_rectw(v);
	rect.h = v->rect_w;
	rect.w = v->rect_w;
	SDL_SetRenderDrawColor(v->renderer, 255, 255, 255, 255);
	while (i < v->map_h)
	{
		rect.y = v->start_y + i * (rect.h + 2);
		j = 0;
		while (j < v->map_w)
		{
			rect.x = v->start_x + j * (rect.w + 2);
			SDL_RenderFillRect(v->renderer, &rect);
			j++;
		}
		i++;
	}
}

void	draw_rect(t_visual *v, t_dlist *begin)
{
	if ()
		
}

void	draw_next(t_visual *v, t_dlist **begin)
{
	int			i;
	int			j;
	SDL_Rect	rect;

	i = 0;
	rect.h = v->rect_w;
	rect.w = v->rect_w;
	while (i < v->map_h)
	{
		j = 0;
		rect.y = v->start_y + i (rect.h + 2);
		while (j < v->map_w)
		{
			rect.x = v->start_x + j * (rect.w + 2);
			if (v->map[i][j] != '.')
				draw_rect(v, *begin, &rect);
			j++;
		}
		i++;
	}
	if ((*begin)->next)
		*begin = (*begin)->next;
}

void	draw_prev(t_visual *v, t_dlist *begin)
{
	int			i;
	int			j;
	SDL_Rect	rect;

	i = 0;
	rect.h = v->rect_w;
	rect.w = v->rect_w;
	while (i < v->map_h)
	{
		j = 0;
		rect.y = v->start_y + i (rect.h + 2);
		while (j < v->map_w)
		{
			rect.x = v->start_x + j * (rect.w + 2);
			if (v->map[i][j] != '.')
				draw_rect(v, *begin, &rect);
			j++;
		}
		i++;
	}
	if ((*begin)->prev)
		*begin = (*begin)->prev;
}
