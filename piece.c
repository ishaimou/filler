#include "filler.h"

static int		is_dots(char *s)
{
	while (*s)
	{
		if (*s != '.')
			return (0);
		s++;	
	}
	return (1);
}

static void	craft_piece_h(t_filler *fil)
{
	int		i;

	i = fil->pc_h;
	while (--i >= 0 &&  is_dots(fil->pc[i]))
	{
		free(fil->pc[i]);
		fil->pc[i] = NULL;
		fil->pc_h--;
	}
}

static int	get_max_w(t_filler *fil)
{
	int		i;
	int		j;
	int		max_w;
	
	i = 0;
	max_w = 0;
	while (i < fil->pc_h)
	{
		if (is_dots(fil->pc[i]))
			continue;
		j = fil->pc_w - 1;
		while (j >= 0 && fil->pc[i][j] != '*')
			j--;
		(j > max_w) ? max_w = j : 0;
		i++;
	}
	return (max_w);
}

static void	craft_piece_w(t_filler *fil)
{
	int		max_w;
	int		i;

	if ((max_w = get_max_w(fil)))
	{
		printf("max_w = %d\n", max_w);
		fil->pc_w = max_w + 1;
		i = 0;
		while (i < fil->pc_h)
		{
			fil->pc[i][max_w + 1] = '\0';
			i++;
		}
	}
}

void	craft_piece(t_filler *fil)
{
	craft_piece_h(fil);
	craft_piece_w(fil);
}
