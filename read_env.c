/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishaimou <ishaimou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 23:21:10 by ishaimou          #+#    #+#             */
/*   Updated: 2019/05/09 01:16:28 by ishaimou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void	get_pl(t_filler *fil)
{
	char	*line;

	get_next_line(0, &line);
	fil->pl = ft_strstr(line, "p1") ? 'o' : 'x';
	fil->op = (fil->pl == 'x') ? 'o' : 'x';
	free(line);
}

static void	get_hw(t_filler *fil)
{
	char	*line;
	char	*tmp;

	get_next_line(0, &line);
	tmp = line;
	while (*line && !ft_isdigit(*line))
		line++;
	fil->h = ft_atoi(line);
	while (ft_isdigit(*line))
		line++;
	fil->w = ft_atoi(line + 1);
	free(tmp); 
}

static void	get_map(t_filler *fil)
{
	char	*line;
	int		i;

	i = -1;
	while (++i < 1 + fil->flag)
	{
		get_next_line(0, &line);
		free(line);
		line = NULL;
	}
	i = -1;
	fil->map = (char**)ft_memalloc(sizeof(char*) * (fil->h + 1));
	fil->map[fil->h] = NULL;
	while (++i < fil->h)
	{
		get_next_line(0, &line);
		fil->map[i] = ft_strdup(line + 4);
		free(line);
		line = NULL;
	}
}

static void	get_pc(t_filler *fil)
{
	char	*line;
	char	*tmp;
	int		i;

	i = -1;
	get_next_line(0, &line);
	tmp = line;
	while (*line && !ft_isdigit(*line))
		line++;
	fil->pc_h = ft_atoi(line);
	while (*line && ft_isdigit(*line))
		line++;
	fil->pc_w = ft_atoi(line + 1);
	free(tmp);
	line = NULL;
	fil->pc = (char**)ft_memalloc(sizeof(char*) * (fil->pc_h + 1));
	fil->pc[fil->pc_h] = NULL;
	while (++i < fil->pc_h)
	{
		get_next_line(0, &line);
		fil->pc[i] = ft_strdup(line);
		free(line);
		line = NULL;
	}
}

void	get_env(t_filler *fil)
{
	if (!fil->flag)
	{
		get_pl(fil);
		get_hw(fil);
	}
	get_map(fil);
	get_pc(fil);
	fil->offset_x = 0;
	fil->offset_y = 0;
	fil->flag = 1;
}
