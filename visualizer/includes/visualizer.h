/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualizer.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishaimou <ishaimou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 01:51:21 by ishaimou          #+#    #+#             */
/*   Updated: 2019/05/26 07:04:45 by ishaimou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISUALIZER_H
# define VISUALIZER_H

# define SCREEN_WIDTH  1280
# define SCREEN_HEIGHT 1096
# define FONT	"/media/arial.ttf"
# define PL_FONT "/media/got.ttf"
# define VS_FONT "/media/chinese.ttf"
# define BG_AUDIO "/media/Fantasia.wav"
# define BG_WALL "/media/bg1.jpg"
# define NB_COLOR 3

# include <SDL.h>
# include <SDL_image.h>
# include <SDL_ttf.h>
# include <stdio.h>
# include "libft.h"

typedef struct			s_dlist
{
	char				**map;
	struct s_dlist		*next;
	struct s_dlist		*prev;
}						t_dlist;

typedef struct			s_color
{
	SDL_Color			clr1;
	SDL_Color			clr11;
	SDL_Color			clr2;
	SDL_Color			clr22;
}						t_color;

typedef struct			s_visual
{
	TTF_Font			*font;
	SDL_Window			*window;
	SDL_Renderer		*renderer;
	SDL_Event			e;
	SDL_AudioDeviceID	device_id;
	SDL_Color			clr_vs;
	t_color				clrs[NB_COLOR];
	int					speed[8];
	Uint8				*wav_buffer;
	t_dlist				*lst;
	int					map_h;
	int					map_w;
	int					rect_w;
	int					c;
	int					s;
	int					pause;
	int					mute;
	int					close;
	int					fin;
	int					start_x;
	int					start_y;
	char				*p1_name;
	char				*p2_name;
	int					res_p1;
	int					res_p2;
	int					flag;
}						t_visual;

t_dlist					*ft_dlst_new(void);
t_dlist					*ft_dlst_addnode(t_dlist **head);
SDL_Color				init_rgbclr(int r, int g, int b, int a);
int						parser(t_visual *v);
int						get_players(t_visual *v);
void					get_result(t_visual *v, char **s);
void					draw_curr(t_visual *v, t_dlist *begin);
void					draw_next(t_visual *v, t_dlist **begin);
void					draw_prev(t_visual *v, t_dlist **begin);
void					draw_rect(t_visual *v, t_dlist *begin, int i, int j);
void					set_rectw(t_visual *v);
int						init(t_visual *v);
int						load_bg(t_visual *v);
int						load_audio(t_visual *v);
int						write_p1(t_visual *v, int size);
int						write_p2(t_visual *v, int size);
int						write_vs(t_visual *v, int size);
void					write_result(t_visual *v);
void					draw_background(t_visual *v, t_dlist *begin);
void					handle_keyevents(t_visual *v, t_dlist **begin);
void					free_visual(t_visual *v);
void					ft_sdlclose(t_visual *v);

#endif
