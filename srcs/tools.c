/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishaimou <ishaimou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 23:22:58 by ishaimou          #+#    #+#             */
/*   Updated: 2019/05/27 09:59:38 by ishaimou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int			is_dots(char *s)
{
	while (*s)
	{
		if (*s != '.')
			return (0);
		s++;
	}
	return (1);
}

void		init_fil(t_filler *fil)
{
	fil->map = NULL;
	fil->hmap = NULL;
	fil->pc = NULL;
	fil->pc_h = 0;
	fil->pc_w = 0;
	fil->offset_x = 0;
	fil->offset_y = 0;
	fil->w = 0;
	fil->h = 0;
	fil->pl = 0;
	fil->op = 0;
	fil->pos_x = -1;
	fil->pos_y = -1;
	fil->t_x = -1;
	fil->t_y = -1;
	fil->flag = 0;
	fil->x_coord = 0;
	fil->y_coord = 0;
	fil->score = INT_MAX;
}

void		reset_hmap(t_filler *fil)
{
	int		i;
	int		j;

	i = -1;
	while (++i < fil->h)
	{
		j = -1;
		while (++j < fil->w)
			fil->hmap[i][j] = 0;
	}
}

int			**clone_hmap(t_filler *fil)
{
	int		**tmp;
	int		i;
	int		j;

	tmp = (int**)ft_memalloc(sizeof(int*) * fil->h);
	i = -1;
	while (++i < fil->h)
	{
		tmp[i] = (int*)ft_memalloc(sizeof(int) * fil->w);
		j = -1;
		while (++j < fil->w)
			tmp[i][j] = fil->hmap[i][j];
	}
	return (tmp);
}

void		merge_hmap(t_filler *fil, int **tmp, int flag)
{
	int		i;
	int		j;

	i = -1;
	while (++i < fil->h)
	{
		j = -1;
		while (++j < fil->w)
		{
			if (tmp[i][j] == -2)
				fil->hmap[i][j] = -2;
			if (tmp[i][j] == -1 && flag == 1)
				fil->hmap[i][j] = -1;
		}
	}
}
