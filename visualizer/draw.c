#include "visualizer.h"

void	draw_rect(t_visual *v, t_dlist *begin, int i, int j)
{
	SDL_Rect	rect;

	rect.h = v->rect_w;
	rect.w = v->rect_w;
	rect.y = v->start_y + i * (rect.h + 1);
	rect.x = v->start_x + j * (rect.w + 1);
	if (begin->map[i][j] == 'X')
	{
		//SDL_SetRenderDrawColor(v->renderer, 196, 98, 16, 255);
		SDL_SetRenderDrawColor(v->renderer,
			v->clrs[v->c].clr2.r, v->clrs[v->c].clr2.g, v->clrs[v->c].clr2.b, 255);
		SDL_RenderFillRect(v->renderer, &rect);
	}
	else if (begin->map[i][j] == 'x')
	{
		//SDL_SetRenderDrawColor(v->renderer, 255, 126, 0, 255);
		SDL_SetRenderDrawColor(v->renderer,
			v->clrs[v->c].clr22.r, v->clrs[v->c].clr22.g, v->clrs[v->c].clr22.b, 255);
		SDL_RenderFillRect(v->renderer, &rect);
	}
	else if (begin->map[i][j] == 'O')
	{
		//SDL_SetRenderDrawColor(v->renderer, 93, 138, 168, 255);
		SDL_SetRenderDrawColor(v->renderer,
			v->clrs[v->c].clr1.r, v->clrs[v->c].clr1.g, v->clrs[v->c].clr1.b, 255);
		SDL_RenderFillRect(v->renderer, &rect);
	}
	else if (begin->map[i][j] == 'o')
	{
		//SDL_SetRenderDrawColor(v->renderer, 124, 185, 232, 255);
		SDL_SetRenderDrawColor(v->renderer,
			v->clrs[v->c].clr11.r, v->clrs[v->c].clr11.g, v->clrs[v->c].clr11.b, 255);
		SDL_RenderFillRect(v->renderer, &rect);
	}
	else if (begin->map[i][j] == '.')
	{
		SDL_SetRenderDrawColor(v->renderer, 180, 186, 196, 255);
		SDL_RenderFillRect(v->renderer, &rect);
	}
}

void	loop_map(t_visual *v, t_dlist *begin)
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

void	draw_curr(t_visual *v, t_dlist *begin)
{
	if (begin)
	{
		loop_map(v, begin);
		SDL_RenderPresent(v->renderer);
	}
}

void	draw_next(t_visual *v, t_dlist **begin)
{
	if ((*begin)->next)
	{
		*begin = (*begin)->next;
		loop_map(v, *begin);
		SDL_RenderPresent(v->renderer);
	}
}

void	draw_prev(t_visual *v, t_dlist **begin)
{
	if ((*begin)->prev)
	{
		*begin = (*begin)->prev;
		loop_map(v, *begin);
		SDL_RenderPresent(v->renderer);
	}
}

void	reset_game(t_visual *v, t_dlist **begin)
{
	(*begin) = v->lst;
	v->pause = 1;
	draw_curr(v, *begin);
}

void	change_color(t_visual *v, t_dlist *begin)
{
	if (v->c == 2)
		v->c = 0;
	else
		v->c++;
	write_p1(v, 38);
	write_p2(v, 38);
	draw_curr(v, begin);
}







