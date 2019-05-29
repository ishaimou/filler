/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishaimou <ishaimou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 23:20:51 by ishaimou          #+#    #+#             */
/*   Updated: 2019/05/27 09:56:11 by ishaimou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include "libft.h"

typedef struct		s_filler
{
	char			**map;
	int				**hmap;
	char			**pc;
	int				pc_h;
	int				pc_w;
	int				offset_x;
	int				offset_y;
	int				w;
	int				h;
	char			pl;
	char			op;
	int				pos_x;
	int				pos_y;
	int				t_x;
	int				t_y;
	int				flag;
	int				score;
	int				x_coord;
	int				y_coord;
}					t_filler;

void				init_fil(t_filler *fil);
int					get_env(t_filler *fil);
void				reset_hmap(t_filler *fil);
void				create_hmap(t_filler *fil);
void				heat_map(t_filler *fil);
void				heatmap_target(t_filler *fil);
int					**clone_hmap(t_filler *fil);
void				heat_up(t_filler *fil, int i, int j, int x);
void				merge_hmap(t_filler *fil, int **tmp, int flag);
void				craft_piece(t_filler *fil);
void				get_target_coord(t_filler *fil);
void				get_coord(t_filler *fil);
int					is_valid_pos(t_filler *fil, int x, int y);
int					is_dots(char *s);
void				free_hmap(int ***tab, int size);
void				free_fil(t_filler *fil);

#endif
