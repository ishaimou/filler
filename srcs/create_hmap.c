/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_hmap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishaimou <ishaimou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 00:10:40 by ishaimou          #+#    #+#             */
/*   Updated: 2019/05/26 23:54:17 by ishaimou         ###   ########.fr       */
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
		{
			fil->hmap[i][j] = -2;
			if (fil->pos_x == -1 && fil->pos_y == -1)
			{
				fil->pos_x = j;
				fil->pos_y = i;
			}
		}
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
