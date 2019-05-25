/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishaimou <ishaimou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 07:36:35 by ishaimou          #+#    #+#             */
/*   Updated: 2019/05/25 08:25:02 by ishaimou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

static void	free_dbl(char ***tab)
{
	int		i;

	i = 0;
	while ((*tab)[i])
	{
		free((*tab)[i]);
		i++;
	}
	free(*tab);
	*tab = NULL;
}

static void	free_list(t_dlist **begin)
{
	t_dlist	*tmp;
	t_dlist	*current;

	current = *begin;
	while (current)
	{
		tmp = current;
		if (current->map)
			free_dbl(&(current->map));
		current = current->next;
		free(tmp);
	}
	*begin = NULL;
}

void		free_visual(t_visual *v)
{
	if (v->p1_name)
		free(v->p1_name);
	if (v->p2_name)
		free(v->p2_name);
	free_list(&(v->lst));
}

void		ft_sdlclose(t_visual *v)
{
	SDL_CloseAudioDevice(v->device_id);
	SDL_FreeWAV(v->wav_buffer);
	v->wav_buffer = NULL;
	SDL_DestroyRenderer(v->renderer);
	v->renderer = NULL;
	SDL_DestroyWindow(v->window);
	v->window = NULL;
	IMG_Quit();
	TTF_Quit();
	SDL_Quit();
}
