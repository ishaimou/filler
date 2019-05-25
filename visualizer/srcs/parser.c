/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishaimou <ishaimou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 02:39:24 by ishaimou          #+#    #+#             */
/*   Updated: 2019/05/25 05:39:37 by ishaimou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

void	get_hw(t_visual *v, char **s)
{
	char	*tmp;

	tmp = *s;
	while (**s && !ft_isdigit(**s))
		(*s)++;
	v->map_h = ft_atoi(*s);
	while (ft_isdigit(**s))
		(*s)++;
	v->map_w = ft_atoi(*s + 1);
	free(tmp);
	*s = NULL;
}

void	get_map(t_visual *v, t_dlist **node)
{
	char	*line;
	int		i;

	get_next_line(0, &line);
	free(line);
	line = NULL;
	i = -1;
	(*node)->map = (char**)ft_memalloc(sizeof(char*) * (v->map_h + 1));
	while (++i < v->map_h)
	{
		get_next_line(0, &line);
		(*node)->map[i] = ft_strdup(line + 4);
		free(line);
		line = NULL;
	}
	(*node)->map[i] = NULL;
}

void	parse_line(t_visual *v, char  **line)
{
	t_dlist		*node;

	node = NULL;
	if (ft_strstr(*line, "Plateau"))
	{
		node = ft_dlst_addnode(&(v->lst));
		if (!v->flag)
			get_hw(v, line);
		else
			free(*line);

		get_map(v, &node);
	}
	else if (ft_strstr(*line, "fin"))
		get_result(v, line);
	else
		free(*line);
}

int		parser(t_visual *v)
{
	char *line;
	
	if (!get_players(v))
		return (0);
	while (1)
	{
		if (get_next_line(0, &line) <= 0)
		{
			free(line);
			return (1);
		}
		parse_line(v, &line);
		v->flag = 1;
	}
	return (1);
}
