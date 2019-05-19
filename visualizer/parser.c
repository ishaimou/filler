/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishaimou <ishaimou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 02:39:24 by ishaimou          #+#    #+#             */
/*   Updated: 2019/05/15 03:31:00 by ishaimou         ###   ########.fr       */
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

void	get_pc(t_visual *v, t_dlist **node, char **s)
{
	char	*line;
	char	*tmp;
	int		i;

	i = -1;
	tmp = *s;
	while (**s && !ft_isdigit(**s))
		(*s)++;
	(*node)->pc_h = ft_atoi(*s);
	while (**s && ft_isdigit(**s))
		(*s)++;
	(*node)->pc_w = ft_atoi(*s + 1);
	free(tmp);
	*s = NULL;
	(*node)->pc = (char**)ft_memalloc(sizeof(char*) * ((*node)->pc_h + 1));
	while (++i < (*node)->pc_h)
	{
		get_next_line(0, &line);
		(*node)->pc[i] = ft_strdup(line);
		free(line);
		line = NULL;
	}
	(*node)->pc[i] = NULL;
}

void		get_curr_player(t_visual *v, t_dlist **node, char **s)
{
	if (ft_strstr(*s, "O"))
		(*node)->curr_p = 1;
	else if (ft_strstr(*s, "X"))
		(*node)->curr_p = 2;
	else
		(*node)->curr_p = 0;
	free(*s);
}

void	get_result(t_visual *v, char **s)
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

void	parse_line(t_visual *v, t_dlist **node, char  **line)
{
	if (ft_strstr(*line, "Plateau"))
	{
		if (!v->flag)
			get_hw(v, line);
		else
			free(*line);
		get_map(v, node);
	}
	else if (ft_strstr(*line, "Piece"))
		get_pc(v, node, line);
	else if (ft_strstr(*line, "got"))
	{
		v->status = 1;
		get_curr_player(v, node, line);
	}
	else if (ft_strstr(*line, "fin"))
	{
		get_result(v, line);
		v->last = 1;
	}
}

int		parser(t_visual *v, t_dlist **node)
{
	char *line;

	if (get_next_line(0, &line) <= 0)
	{
		free(line);
		return (0);
	}
	parse_line(v, node, &line);
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

void	fill_gaps(t_visual *v, t_dlist **node)
{
	int		i;

	i = -1;
	if (!(*node)->prev)
		return ;
	(*node)->map = (char**)malloc(sizeof(char*) * (v->map_h + 1));
	while (++i < v->map_h)
		(*node)->map[i] = ft_strdup((*node)->prev->map[i]);
	(*node)->map[i] = NULL;
}

int		rec_game(t_visual *v)
{
	t_dlist	*node;
	int		success;

	if (!get_players(v))
		return (0);
	success = 1;
	while (success)
	{	
		node = ft_dlst_addnode(&(v->lst));
		while (!v->status)
			if (!(success = parser(v, &node)))
				break;
		if (!node->map)
			fill_gaps(v, &node);
		v->status = 0;
	}
	if (v->last)
		free_node(&node);
	return (1);	
}
