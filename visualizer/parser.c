/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishaimou <ishaimou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 02:39:24 by ishaimou          #+#    #+#             */
/*   Updated: 2019/05/13 03:13:28 by ishaimou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

void	get_name(t_parser *p, char *line)
{
	int		i;
	int		len;

	i = 0;
	len = 1;
	while (line[i])
		i++;
	while (line[i] != '/')
		i--;
	while (line[i + len] != '.')
		len++;
	pl->name =ft_strsub();
}

void	get_players(t_parser *p)
{
	char	*line;
	int		i;

	i = 6;
	while (i--)
	{
		get_next_line(0, &line);
		free(line);
		line = NULL;
	}
	get_next_line(0, &line);
	p->pl = ft_strstr(line, "p1") ? 'o' : 'x';
	p->op = (p->pl == 'x') ? 'o' : 'x';
	get_name(p, line);
}

int		parser(t_parser *p)
{
	get_players(p);
	get_map(p);

}

int		rec_game(t_parser *p)
{
	
}
