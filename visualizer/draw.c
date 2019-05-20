#include "visualizer.h"

void	draw_blank(t_visual *v)
{
	int			i;
	int			j;
	SDL_Rect	rect;
	int			start_x = 100;
	int			start_y = 100;
	int			rect_w	= 20;

	i = 0;
	rect.h = rect_w;
	rect.w = rect_w;
	SDL_SetRenderDrawColor(v->renderer, 255, 255, 255, 255);
	while (i < v->map_h)
	{
		rect.y = start_x + i * (rect.h + 2);
		j = 0;
		while (j < v->map_w)
		{
			rect.x = start_y + j * (rect.w + 2);
			SDL_RenderFillRect(v->renderer, &rect);
			j++;
		}
		i++;
	}
}
