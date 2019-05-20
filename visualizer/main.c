/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishaimou <ishaimou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 02:32:51 by ishaimou          #+#    #+#             */
/*   Updated: 2019/05/15 03:31:02 by ishaimou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

int		main(int argc, char *argv[])
{
	SDL_Event	e;
	t_visual	v;
	int			close;

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
	draw_blank(&v);
	SDL_RenderPresent(v.renderer);
	
	close = 0;
	while (!close)
	{
		while (SDL_PollEvent(&e))
		{
			if (e.type == SDL_QUIT)
				close = 1;
			if (e.type == SDL_KEYDOWN)
				if (e.key.keysym.sym == SDLK_ESCAPE)
					close = 1;
		}
	}
	ft_sdlclose(&v);
	return (0);
}
