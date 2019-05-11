/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_hmap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishaimou <ishaimou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 00:10:40 by ishaimou          #+#    #+#             */
/*   Updated: 2019/05/10 23:11:47 by ishaimou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void	init_hmap_i(t_filler *fil, int i)
{
	int		j;
	int		size;

	size = fil->w;
	j = 0;
	while (j < size)
	{
		if (*ft_strlowcase(&fil->map[i][j]) == fil->op)
			fil->hmap[i][j] = -1;
		if (*ft_strlowcase(&fil->map[i][j]) == fil->pl)
			fil->hmap[i][j] = -2;
		j++;
	}
}

void		create_hmap(t_filler *fil)
{
	int		i;

	i = 0;
	fil->hmap = (int**)ft_memalloc(sizeof(int*) * fil->h);
	while (i < fil->h)
	{
		fil->hmap[i] = (int*)ft_memalloc(sizeof(int) * fil->w);
		init_hmap_i(fil, i);
		i++;
	}
}

static void	heat_up(t_filler *fil, int i, int j, int x)
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

void		generate_heat(t_filler *fil)
{
	int		i;
	int		j;
	int		x;

	i = 0;
	x = 0;
	while (x < fil->w)
	{
		while (i < fil->h)
		{
			j = 0;
			while (j < fil->w)
			{
				if (fil->hmap[i][j] == 0)
					heat_up(fil, i, j, x);
				j++;
			}
			i++;
		}
		i = 0;
		j = 0;
		x++;
	}
}
