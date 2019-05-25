#include "visualizer.h"

static void	draw_blackbg(t_visual *v)
{
	SDL_Rect	rect;

	rect.x = v->start_x;
	rect.y = v->start_y;
	rect.h = v->map_h * v->rect_w + (v->map_h - 1);
	rect.w = v->map_w * v->rect_w + (v->map_w - 1);
	SDL_SetRenderDrawColor(v->renderer, 0, 0, 0, 255);
	SDL_RenderFillRect(v->renderer, &rect);
}

void	draw_background(t_visual *v, t_dlist *begin)
{
	load_bg(v);
	write_p1(v, 38);
	write_p2(v, 38);
	write_vs(v, 50);
	draw_blackbg(v);
	draw_curr(v, begin);
}


void	draw_curr(t_visual *v, t_dlist *begin)
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
