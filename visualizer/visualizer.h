/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualizer.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishaimou <ishaimou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 01:51:21 by ishaimou          #+#    #+#             */
/*   Updated: 2019/05/15 03:08:33 by ishaimou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISUALIZER_H
# define VISUALIZER_H

//Screen dimension macros
#define SCREEN_WIDTH  640 
#define SCREEN_HEIGHT 480
#define PL_FONT "/media/got.ttf"
#define BG_AUDIO "/media/Fantasia.wav"
#define BG_WALL "/media/bg2.jpg"

# include <SDL.h>
# include <SDL_image.h>
# include <SDL_ttf.h>
# include <stdio.h>
# include "libft.h"

typedef struct			s_dlist
{
	char				**map;
	char				**pc;
	int					pc_h;
	int					pc_w;
	int					curr_p;
	struct s_dlist		*next;
	struct s_dlist		*prev;
}						t_dlist;

typedef struct			s_visual
{
	SDL_Window			*window;
	SDL_Renderer		*renderer;
	SDL_AudioDeviceID	device_id;
	SDL_Color			clr_p1;
	SDL_Color			clr_p2;
	SDL_Color			clr_vs;
	Uint8				*wav_buffer;
	t_dlist				*lst;
	int					map_h;
	int					map_w;
	char				*p1_name;
	char				*p2_name;
	int					res_p1;
	int					res_p2;
	int					flag;
	int					status;
	int					last;
}						t_visual;

int		init_visual(t_visual *v);
int		load_media(t_visual *v);
int		load_audio(t_visual *v);
int		write_p1(t_visual *v);
int		write_p2(t_visual *v);
void	draw_blank(t_visual *v);
void	ft_sdlclose(t_visual *v);
int		parser(t_visual *v, t_dlist **node);
int		rec_game(t_visual *v);
void	free_node(t_dlist **node);
void	free_list(t_dlist **begin);
void	free_visual(t_visual *v);
void	print_map(char **map);
void	print_list(t_dlist *begin);
int		ft_list_size(t_dlist *begin_list);


#endif
