/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishaimou <ishaimou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 23:22:58 by ishaimou          #+#    #+#             */
/*   Updated: 2019/05/10 18:33:37 by ishaimou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		is_dots(char *s)
{
	while (*s)
	{
		if (*s != '.')
			return (0);
		s++;	
	}
	return (1);
}

void	init_fil(t_filler *fil)
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
	fil->flag = 0;
	fil->score = INT_MAX;
}

void	free_dbl(char ***tab)
{
	int		i;

	i = 0;
	while ((*tab)[i])
	{
		free((*tab)[i]);
		i++;
	}
	free(*tab);
	*tab = NULL;
}

void	free_hmap(int ***tab, int size)
{
	int				i;

	i = 0;
	while (i < size)
	{
		free((*tab)[i]);
		i++;
	}
	free(*tab);
	*tab = NULL;
}

void	free_fil(t_filler *fil)
{
	free_dbl(&fil->map);
	free_dbl(&fil->pc);
	free_hmap(&fil->hmap, fil->h);
}
