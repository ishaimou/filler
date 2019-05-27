/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishaimou <ishaimou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 05:01:53 by ishaimou          #+#    #+#             */
/*   Updated: 2019/05/27 05:21:33 by ishaimou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

void	print_usage(void)
{
	ft_printf("%{CYAN}   ---# FILLER VISUALIZER #---%{eoc}\n");
	ft_printf("  | Play/Pause 	 : %{GREEN}SPACE%{eoc}      |\n");
	ft_printf("  | Draw Next    : %{GREEN}RIGHT%{eoc}      |\n");
	ft_printf("  | Draw Prev	 : %{GREEN}LEFT%{eoc}       |\n");
	ft_printf("  | Speed Up     : %{GREEN}UP%{eoc}         |\n");
	ft_printf("  | Speed Down   : %{GREEN}DOWN%{eoc}       |\n");
	ft_printf("  | Change Color : %{GREEN}C%{eoc}          |\n");
	ft_printf("  | ScreenShot   : %{GREEN}S%{eoc}          |\n");
	ft_printf("  | Mute ON/OFF  : %{GREEN}M%{eoc}          |\n");
	ft_printf("  | Result       : %{GREEN}R%{eoc}          |\n");
	ft_printf("  | Reset        : %{GREEN}BackSpace%{eoc}  |\n");
	ft_printf("%{CYAN}  ----------------------------%{eoc}\n");
}

int		load_media(t_visual *v)
{
	if (!init(v))
	{
		ft_sdlclose(v);
		return (0);
	}
	if (!load_bg(v))
	{
		ft_sdlclose(v);
		return (0);
	}
	if (!load_audio(v))
	{
		ft_sdlclose(v);
		return (0);
	}
	return (1);
}

void	preset(t_visual *v, t_dlist **begin)
{
	*begin = v->lst;
	set_rectw(v);
	SDL_PauseAudioDevice(v->device_id, 0);
	draw_background(v, *begin);
	SDL_RenderPresent(v->renderer);
}

void	event_loop(t_visual *v, t_dlist **begin)
{
	while (SDL_PollEvent(&(v->e)))
	{
		if (v->e.type == SDL_QUIT)
			v->close = 1;
		if (v->e.type == SDL_KEYDOWN)
			handle_keyevents(v, begin);
	}
}
