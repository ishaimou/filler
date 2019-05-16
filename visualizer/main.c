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
	SDL_Event	event;
	t_visual	v;

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
	SDL_RenderCopy(v.renderer, v.bg_tex, NULL, NULL);
	SDL_RenderPresent(v.renderer);
	write_names(&v);
	while (1)
	{
		SDL_WaitEvent(&event);
		if (event.type == SDL_QUIT)
			break;
		//SDL_RenderClear(v.renderer);
	}
	//ft_sdlclose(&v);
	return (0);
}
