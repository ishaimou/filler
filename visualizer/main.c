/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishaimou <ishaimou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 02:32:51 by ishaimou          #+#    #+#             */
/*   Updated: 2019/05/21 07:04:40 by ishaimou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

int		main(int argc, char *argv[])
{
	//SDL_Event	e;
	t_visual	v;
	int			close;
	t_dlist		*begin;

	if (!init_visual(&v))
		return (0);
	if (!load_media(&v))
		return (0);
	if (!load_audio(&v))
		return (0);
	
	//Wait five seconds
	//SDL_Delay(5000);
	
	if (!rec_game(&v))
		return (0);
	/*
	ft_printf("%d\n", ft_list_size(v.lst));
	print_list(v.lst);
	printf("p1 = %s\n", v.p1_name);
	printf("p2 = %s\n", v.p2_name);
	printf("map_h = %d\n", v.map_h);
	printf("map_w = %d\n", v.map_w);
	printf("res_p1 = %d; res_p2 = %d\n", v.res_p1, v.res_p2);
	*/
	SDL_PauseAudioDevice(v.device_id, 0);
	//SDL_RenderClear(v.renderer);
	write_p1(&v);
	write_p2(&v);
	write_vs(&v);
	begin = v.lst;
	set_rectw(&v);
	draw_curr(&v, begin);
	close = 0;
	while (!close)
	{
		while (SDL_PollEvent(&v.e))
		{
			if (v.e.type == SDL_QUIT)
				close = 1;
			if (v.e.type == SDL_KEYDOWN)
			{
				if (v.e.key.keysym.sym == SDLK_ESCAPE)
					close = 1;
				if (v.e.key.keysym.sym == SDLK_RIGHT)
					draw_next(&v, &begin);
				if (v.e.key.keysym.sym == SDLK_LEFT)
					draw_prev(&v, &begin);
				if (v.e.key.keysym.sym == SDLK_SPACE)
					v.pause = (v.pause) ? 0 : 1;
				if (v.e.key.keysym.sym == SDLK_r)
					reset_game(&v, &begin);
			}
		}
		if (begin->next && !v.pause)
		{
			draw_next(&v, &begin);
			SDL_Delay(1000 / 24);
		}
	}
	ft_sdlclose(&v);
	return (0);
}
