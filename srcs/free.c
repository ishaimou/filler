/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishaimou <ishaimou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 09:36:18 by ishaimou          #+#    #+#             */
/*   Updated: 2019/05/27 10:01:03 by ishaimou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

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
