/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishaimou <ishaimou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 23:20:51 by ishaimou          #+#    #+#             */
/*   Updated: 2019/05/09 01:40:35 by ishaimou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "libft/libft.h"

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
	int				flag;
}					t_filler;

void	init_fil(t_filler *fil);
void	get_env(t_filler *fil);
void	create_hmap(t_filler *fil);
void	generate_heat(t_filler *fil);
void	craft_piece(t_filler *fil);
int		is_dots(char *s);

#endif
