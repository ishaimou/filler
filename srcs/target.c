/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishaimou <ishaimou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 09:40:50 by ishaimou          #+#    #+#             */
/*   Updated: 2019/05/27 09:41:23 by ishaimou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	heatmap_target(t_filler *fil)
{
	int		i;
	int		j;
	int		x;
	int		**tmp;

	i = -1;
	x = -1;
	tmp = clone_hmap(fil);
	reset_hmap(fil);
	fil->hmap[fil->t_y][fil->t_x] = -1;
	while (++x < fil->w)
	{
		while (++i < fil->h)
		{
			j = -1;
			while (++j < fil->w)
				if (fil->hmap[i][j] == 0)
					heat_up(fil, i, j, x);
		}
		i = -1;
	}
	fil->hmap[fil->t_y][fil->t_x] = 1;
	merge_hmap(fil, tmp, 1);
	free_hmap(&tmp, fil->h);
}

void	set_target_xy(t_filler *fil, int a, int b)
{
	if (a > b)
	{
		fil->t_x = fil->w / 2;
		fil->t_y = fil->h - 1;
	}
	else
	{
		fil->t_x = fil->w / 2;
		fil->t_y = 0;
	}
}

void	get_target_coord(t_filler *fil)
{
	int		diff_y1;
	int		diff_y2;

	diff_y1 = fil->h - fil->pos_y - 1;
	diff_y2 = fil->pos_y;
	if (fil->h >= 24)
		set_target_xy(fil, diff_y2, diff_y1);
	else
		set_target_xy(fil, diff_y1, diff_y2);
}
