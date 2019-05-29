/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heatmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishaimou <ishaimou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/26 05:48:08 by ishaimou          #+#    #+#             */
/*   Updated: 2019/05/27 09:56:47 by ishaimou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void		heat_up(t_filler *fil, int i, int j, int x)
{
	int		k;

	k = (x == 0) ? -1 : x;
	if (i + 1 < fil->h && fil->hmap[i + 1][j] == k)
		fil->hmap[i][j] = x + 1;
	if (i - 1 >= 0 && fil->hmap[i - 1][j] == k)
		fil->hmap[i][j] = x + 1;
	if (j + 1 < fil->w && fil->hmap[i][j + 1] == k)
		fil->hmap[i][j] = x + 1;
	if (j - 1 >= 0 && fil->hmap[i][j - 1] == k)
		fil->hmap[i][j] = x + 1;
	if (i - 1 >= 0 && j - 1 >= 0 && fil->hmap[i - 1][j - 1] == k)
		fil->hmap[i][j] = x + 1;
	if (i - 1 >= 0 && j + 1 < fil->w && fil->hmap[i - 1][j + 1] == k)
		fil->hmap[i][j] = x + 1;
	if (i + 1 < fil->h && j - 1 >= 0 && fil->hmap[i + 1][j - 1] == k)
		fil->hmap[i][j] = x + 1;
	if (i + 1 < fil->h && j + 1 < fil->w && fil->hmap[i + 1][j + 1] == k)
		fil->hmap[i][j] = x + 1;
}

static void	generate_heat(t_filler *fil)
{
	int		i;
	int		j;
	int		x;
	int		**tmp;

	i = -1;
	x = -1;
	tmp = clone_hmap(fil);
	while (++x < fil->w)
	{
		while (++i < fil->h)
		{
			j = -1;
			while (++j < fil->w)
			{
				if (fil->hmap[i][j] == 0 || fil->hmap[i][j] == -2)
					heat_up(fil, i, j, x);
			}
		}
		i = -1;
	}
	merge_hmap(fil, tmp, 0);
	free_hmap(&tmp, fil->h);
}

void		heat_map(t_filler *fil)
{
	if (fil->t_y == -1 && fil->t_y == -1)
		get_target_coord(fil);
	if (fil->map[fil->t_y][fil->t_x] == '.')
		heatmap_target(fil);
	else
		generate_heat(fil);
}
