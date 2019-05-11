/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishaimou <ishaimou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 23:42:44 by ishaimou          #+#    #+#             */
/*   Updated: 2019/05/10 23:43:12 by ishaimou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static	int	rule1(t_filler *fil, int x, int y)
{
	int		diff_x;
	int		diff_y;

	diff_x = fil->w - x;
	diff_y = fil->h - y;
	if ((diff_x >= fil->pc_w - fil->offset_x)
			&& (diff_y >= fil->pc_h - fil->offset_y))
		return (1);
	return (0);
}

static int	rule2(t_filler *fil, int x, int y)
{
	int		i;
	int		j;
	int		tmpy;
	int		tmpx;
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
			if (fil->pc[i][j] == '*' && fil->hmap[tmpy + i][tmpx + j] == -2)
				count++;
			if (fil->hmap[tmpy + i][tmpx + j] == -1)
				return (0);
		}
		if (count > 1)
			return (0);
	}
	return ((count == 1) ? 1 : 0);
}

int			is_valid_pos(t_filler *fil, int x, int y)
{
	if (rule1(fil, x, y))
	{
		if (rule2(fil, x, y))
			return (1);
	}
	return (0);
}
