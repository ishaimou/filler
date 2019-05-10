/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishaimou <ishaimou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 23:20:36 by ishaimou          #+#    #+#             */
/*   Updated: 2019/05/10 18:33:44 by ishaimou         ###   ########.fr       */
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

int		main(void)
{
	t_filler	fil;

	init_fil(&fil);
	while (1)
	{
		if (get_env(&fil) == -1)
			return (0);
		create_hmap(&fil);
		generate_heat(&fil);
		/*	
			printf("pl = %c; op = %c\n", fil.pl, fil.op);
			printf("h = %d; w = %d\n", fil.h, fil.w);
			print_map(fil.map);
			printf("\npiece before\n");
			printf("pc_h = %d; pc_w = %d\n", fil.pc_h, fil.pc_w);
			printf("offset_x = %d; offset_y = %d\n", fil.offset_x, fil.offset_y);
			print_map(fil.pc);
			*/
		craft_piece(&fil);
		/*
		   printf("\npiece after\n");
		   printf("pc_h = %d; pc_w = %d\n", fil.pc_h, fil.pc_w);
		   printf("offset_x = %d; offset_y = %d\n", fil.offset_x, fil.offset_y);
		   print_map(fil.pc);
		   printf("\n\n");
		   print_hmap(fil);
		   printf("\n\n");
		   */
		get_coord(&fil);
		free_fil(&fil);
	}
	return (0);
}
