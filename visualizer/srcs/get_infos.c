/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_infos.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishaimou <ishaimou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 23:18:36 by ishaimou          #+#    #+#             */
/*   Updated: 2019/05/25 08:25:36 by ishaimou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

static int	check_player(void)
{
	char	*line;

	get_next_line(0, &line);
	if (ft_strncmp("launched", line, 8) || !ft_strstr(line, ".filler"))
	{
		ft_printf("Error: bad player\n");
		free(line);
		line = NULL;
		return (0);
	}
	free(line);
	line = NULL;
	return (1);
}

static char	*get_name(void)
{
	int		i;
	int		len;
	char	*line;
	char	*name;

	i = 0;
	len = 0;
	get_next_line(0, &line);
	if (!ft_strstr(line, "$$$"))
	{
		ft_printf("Error: bad player\n");
		free(line);
		return (NULL);
	}
	while (line[i])
		i++;
	while (line[i] != '/')
		i--;
	while (line[i + len] != '.')
		len++;
	name = ft_strsub(&line[i + 1], 0, len - 1);
	free(line);
	line = NULL;
	return (name);
}

int			get_players(t_visual *v)
{
	char	*line;
	int		i;

	i = 5;
	while (i--)
	{
		get_next_line(0, &line);
		free(line);
		line = NULL;
	}
	if (!check_player())
		return (0);
	if (!(v->p1_name = get_name()))
		return (0);
	if (!check_player())
		return (0);
	if (!(v->p2_name = get_name()))
		return (0);
	return (1);
}

void		get_result(t_visual *v, char **s)
{
	char	*tmp;

	tmp = *s;
	while (**s && !ft_isdigit(**s))
		(*s)++;
	if (ft_strchr(tmp, 'O'))
		v->res_p1 = ft_atoi(*s);
	else if (ft_strchr(tmp, 'X'))
		v->res_p2 = ft_atoi(*s);
	free(tmp);
}
