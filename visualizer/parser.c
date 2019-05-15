/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishaimou <ishaimou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 02:39:24 by ishaimou          #+#    #+#             */
/*   Updated: 2019/05/15 01:10:22 by ishaimou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

int			check_player(void)
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

char	*get_name(void)
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

int	get_hw(t_visual *v)
{
	char	*line;
	char	*tmp;

	get_next_line(0, &line);
	if (!ft_strstr(line, "Plateau"))
	{
		ft_printf("Error reading map dimensions\n");
		free(line);
		return (0);
	}
	tmp = line;
	while (*line && !ft_isdigit(*line))
		line++;
	v->map_h = ft_atoi(line);
	while (ft_isdigit(*line))
		line++;
	v->map_w = ft_atoi(line + 1);
	free(tmp);
	return (1);
}

int	get_map(t_visual *v, t_dlist *node)
{
	char	*line;
	int		i;

	i = -1;
	while (++i < 1 + v->flag)
	{
		if (get_next_line(0, &line) <= 0)
		{
			free(line);
			return (-1);
		}
		free(line);
		line = NULL;
	}
	i = -1;
	node->map = (char**)ft_memalloc(sizeof(char*) * (v->map_h + 1));
	node->map[v->map_h] = NULL;
	while (++i < v->map_h)
	{
		get_next_line(0, &line);
		node->map[i] = ft_strdup(line + 4);
		free(line);
		line = NULL;
	}
	return (1);
}

void	get_pc(t_visual *v, t_dlist *node)
{
	char	*line;
	char	*tmp;
	int		i;

	i = -1;
	get_next_line(0, &line);
	tmp = line;
	while (*line && !ft_isdigit(*line))
		line++;
	node->pc_h = ft_atoi(line);
	while (*line && ft_isdigit(*line))
		line++;
	node->pc_w = ft_atoi(line + 1);
	free(tmp);
	line = NULL;
	node->pc = (char**)ft_memalloc(sizeof(char*) * (node->pc_h + 1));
	node->pc[node->pc_h] = NULL;
	while (++i < node->pc_h)
	{
		get_next_line(0, &line);
		node->pc[i] = ft_strdup(line);
		free(line);
		line = NULL;
	}
}

int		get_curr_player(t_visual *v, t_dlist *node)
{
	char	*tmp;
	char	*line;

	get_next_line(0, &line);
	if (!ft_strstr(line, "got"))
	{
		free(line);
		return (0);
	}
	tmp = line;
	while (*line && (*line != 'O' || *line != 'X'))
		line++;
	if (!*line)
	{
		free(tmp);
		return (0);
	}
	if (*line == 'O')
		node->curr_p = 1;
	else if (*line == 'X')
		node->curr_p = 2;
	else
		node->curr_p = 0;
	free(tmp);
	return (1);	
}

int		parser(t_visual *v, t_dlist *node)
{
	char *line;
	int	success;

	if (!v->flag)
	{
		if (!get_players(v))
			return (0);
		if (!get_hw(v))
			return (0);
	}
	if (!(success = get_map(v, node)))
		return (0);
	if (success == -1)
		return (-1);
	get_pc(v, node);
	if (!get_curr_player(v, node))
		return (0);
	v->flag = 1;
	return (1);
}

t_dlist	*ft_dlst_new(void)
{
	t_dlist	*node;

	if (!(node = (t_dlist*)malloc(sizeof(t_dlist))))
		return (NULL);
	node->map = NULL;
	node->pc = NULL;
	node->pc_h = 0;
	node->pc_w = 0;
	node->curr_p = 0;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

t_dlist	*ft_dlst_addnode(t_dlist **head)
{
	t_dlist	*tmp;

	if (!*head)
	{
		*head = ft_dlst_new();
		return (*head);
	}
	tmp = *head;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = ft_dlst_new();
	tmp->next->prev = tmp;
	return (tmp->next);
}

int		rec_game(t_visual *v)
{
	t_dlist	*node;
	int		success;

	while (1)
	{	
		node = ft_dlst_addnode(&(v->lst));
		if (!(success = parser(v, node)))
			return (0);
		if (success == -1)
			break;
	}
	return (1);	
}
