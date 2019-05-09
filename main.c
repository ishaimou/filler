/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishaimou <ishaimou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 23:20:36 by ishaimou          #+#    #+#             */
/*   Updated: 2019/05/08 23:59:44 by ishaimou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	print_map(char **map)
{
	while (*map)
	{
		printf("%s\n", *map);
		map++;
	}
}

void	print_hmap(t_filler fil)
{
	int		i;
	int		j;

	i = 0;
	while (i < fil.h)
	{
		j = 0;
		while (j < fil.w)
		{
			printf("%2d ", fil.hmap[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
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


int		main(void)
{
	t_filler	fil;
	int 		i = 8;

	init_fil(&fil);
	while (i--)
	{
		get_env(&fil);
		create_hmap(&fil);
		generate_heat(&fil);
		printf("pl = %c; op = %c\n", fil.pl, fil.op);
		printf("h = %d; w = %d\n", fil.h, fil.w);
		print_map(fil.map);
		printf("\npiece before\n");
		printf("pc_h = %d; pc_w = %d\n", fil.pc_h, fil.pc_w);
		printf("offset_x = %d; offset_y = %d\n", fil.offset_x, fil.offset_y);
		print_map(fil.pc);
		craft_piece(&fil);
		printf("\npiece after\n");
		printf("pc_h = %d; pc_w = %d\n", fil.pc_h, fil.pc_w);
		printf("offset_x = %d; offset_y = %d\n", fil.offset_x, fil.offset_y);
		print_map(fil.pc);
		printf("\n\n");
		print_hmap(fil);
		printf("\n\n");
		free_dbl(&fil.map);
		free_dbl(&fil.pc);
		free_hmap(&fil.hmap, fil.h);
	}
	return (0);
}
