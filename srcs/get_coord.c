/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishaimou <ishaimou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 01:17:11 by ishaimou          #+#    #+#             */
/*   Updated: 2019/05/10 23:47:45 by ishaimou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int			get_score(t_filler *fil, int x, int y)
{
	int		i;
	int		j;
	int		tmpx;
	int		tmpy;
	int		count;

	count = 0;
	tmpx = x - fil->offset_x;
	tmpy = y - fil->offset_y;
	i = fil->offset_y - 1;
	while (++i < fil->pc_h)
	{
		j = fil->offset_x - 1;
		while (++j < fil->pc_w)
		{
			if (fil->pc[i][j] == '*')
				count += fil->hmap[tmpy + i][tmpx + j];
		}
	}
	return (count);
}

static int	get_tmp_score(t_filler *fil, int x, int y, int tmp)
{
	tmp = get_score(fil, x, y);
	if (tmp < fil->score)
	{
		fil->score = tmp;
		fil->x_coord = x;
		fil->y_coord = y;
	}
	return (tmp);
}

void		get_coord(t_filler *fil)
{
	int		i;
	int		j;
	int		x;
	int		y;
	int		tmp;

	i = -1;
	tmp = 0;
	while (++i < fil->h)
	{
		j = -1;
		while (++j < fil->w)
		{
			if (is_valid_pos(fil, j, i))
				tmp = get_tmp_score(fil, j, i, tmp);
		}
	}
	x = fil->x_coord - fil->offset_x;
	y = fil->y_coord - fil->offset_y;
	ft_printf("%d %d\n", y, x);
	fil->score = INT_MAX;
}
