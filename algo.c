/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishaimou <ishaimou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 01:17:11 by ishaimou          #+#    #+#             */
/*   Updated: 2019/05/09 01:40:34 by ishaimou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	

void	get_coord(t_filler *fil)
{
	int		i;
	int		j;

	i = -1;
	while (++i < fil->h)
	{
		j = -1;
		while (++j < fil->w)
		{
			if (is_valid(fil, i, j))
				calculate_score();
		}
	}
}

void	put_piece(t_filler *fil)
{
	get_coord(fil);
}
