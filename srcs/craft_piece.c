/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   craft_piece.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishaimou <ishaimou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 23:11:28 by ishaimou          #+#    #+#             */
/*   Updated: 2019/05/10 23:09:22 by ishaimou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int	get_max_w(t_filler *fil)
{
	int		i;
	int		j;
	int		max_w;

	i = -1;
	max_w = 0;
	while (++i < fil->pc_h)
	{
		if (is_dots(fil->pc[i]))
			continue;
		j = fil->pc_w - 1;
		while (j >= 0 && fil->pc[i][j] != '*')
			j--;
		(j > max_w) ? max_w = j : 0;
	}
	return (max_w);
}

static void	craft_piece_w(t_filler *fil)
{
	int		max_w;
	int		i;

	if ((max_w = get_max_w(fil)))
	{
		fil->pc_w = max_w + 1;
		i = 0;
		while (i < fil->pc_h)
		{
			fil->pc[i][max_w + 1] = '\0';
			i++;
		}
	}
}

static void	craft_piece_h(t_filler *fil)
{
	int		i;

	i = fil->pc_h;
	while (--i >= 0 && is_dots(fil->pc[i]))
	{
		free(fil->pc[i]);
		fil->pc[i] = NULL;
		fil->pc_h--;
	}
}

static void	get_offset(t_filler *fil)
{
	int		i;
	int		j;
	int		min_w;

	i = -1;
	min_w = fil->pc_w - 1;
	while (++i < fil->pc_h)
	{
		if (is_dots(fil->pc[i]))
		{
			fil->offset_y++;
			continue;
		}
		j = 0;
		while (j < fil->pc_w && fil->pc[i][j] == '.')
			j++;
		(j < min_w) ? min_w = j : 0;
	}
	fil->offset_x = (min_w != fil->pc_w - 1) ? min_w : 0;
}

void		craft_piece(t_filler *fil)
{
	craft_piece_h(fil);
	craft_piece_w(fil);
	get_offset(fil);
}
