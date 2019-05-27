/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishaimou <ishaimou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 02:32:51 by ishaimou          #+#    #+#             */
/*   Updated: 2019/05/27 05:20:13 by ishaimou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

int				main(int argc, char *argv[])
{
	t_visual	v;
	t_dlist		*begin;

	(void)argc;
	(void)argv;
	if (!load_media(&v))
		return (0);
	if (!parser(&v))
		return (0);
	preset(&v, &begin);
	print_usage();
	while (!v.close)
	{
		event_loop(&v, &begin);
		if (!v.pause)
		{
			draw_next(&v, &begin);
			SDL_Delay(1000 / v.speed[v.s]);
		}
	}
	free_visual(&v);
	ft_sdlclose(&v);
	return (0);
}
