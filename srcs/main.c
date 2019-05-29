/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishaimou <ishaimou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 23:20:36 by ishaimou          #+#    #+#             */
/*   Updated: 2019/05/27 09:17:16 by ishaimou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		main(void)
{
	t_filler	fil;

	init_fil(&fil);
	while (1)
	{
		if (get_env(&fil) == -1)
			return (0);
		create_hmap(&fil);
		heat_map(&fil);
		craft_piece(&fil);
		get_coord(&fil);
		free_fil(&fil);
	}
	return (0);
}
