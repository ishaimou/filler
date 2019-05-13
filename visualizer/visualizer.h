/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualizer.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishaimou <ishaimou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 01:51:21 by ishaimou          #+#    #+#             */
/*   Updated: 2019/05/13 02:24:29 by ishaimou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISUALIZER_H
# define VISUALIZER_H

//Screen dimension macros
#define SCREEN_WIDTH 1600
#define SCREEN_HEIGHT 900

# include <SDL.h>
# include <SDL_image.h>
# include <stdio.h>
# include "libft.h"

typedef struct			s_visual
{
	SDL_Window			*window;
	SDL_Renderer		*renderer;
	SDL_Texture			*bg_tex;
	SDL_AudioDeviceID	device_id;
	Uint8				*wav_buffer;
}						t_visual;

#endif
