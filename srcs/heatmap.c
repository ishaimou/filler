#include "filler.h"

static void	heat_up(t_filler *fil, int i, int j, int x)
{
	int		k;

	k = (x == 0 || x == -2) ? -1 : x;
	if (i + 1 < fil->h && fil->hmap[i + 1][j] == k)
		fil->hmap[i][j] = x + 1;
	if (i - 1 >= 0 && fil->hmap[i - 1][j] == k)
		fil->hmap[i][j] = x + 1;
	if (j + 1 < fil->w && fil->hmap[i][j + 1] == k)
		fil->hmap[i][j] = x + 1;
	if (j - 1 >= 0 && fil->hmap[i][j - 1] == k)
		fil->hmap[i][j] = x + 1;
	if (i - 1 >= 0 && j - 1 >= 0 && fil->hmap[i - 1][j - 1] == k)
		fil->hmap[i][j] = x + 1;
	if (i - 1 >= 0 && j + 1 < fil->w && fil->hmap[i - 1][j + 1] == k)
		fil->hmap[i][j] = x + 1;
	if (i + 1 < fil->h && j - 1 >= 0 && fil->hmap[i + 1][j - 1] == k)
		fil->hmap[i][j] = x + 1;
	if (i + 1 < fil->h && j + 1 < fil->w && fil->hmap[i + 1][j + 1] == k)
		fil->hmap[i][j] = x + 1;
}

static int	**clone_hmap(t_filler *fil)
{
	int		**tmp;
	int		i;
	int		j;

	tmp = (int**)ft_memalloc(sizeof(int*) * fil->h);
	i = -1;
	while (++i < fil->h)
	{
		tmp[i] = (int*)ft_memalloc(sizeof(int) * fil->w);
		j = -1;
		while (++j < fil->w)
			tmp[i][j] = fil->hmap[i][j];
	}
	return (tmp);
}

static void	merge_hmap(t_filler *fil, int **tmp)
{
	int		i;
	int		j;

	i = -1;
	while (++i < fil->h)
	{
		j = -1;
		while (++j < fil->w)
		{
			if (tmp[i][j] == -2)
				fil->hmap[i][j] = -2;
		}
	}
}

void		generate_heat(t_filler *fil)
{
	int		i;
	int		j;
	int		x;
	int		**tmp;

	i = -1;
	x = -1;
	tmp = clone_hmap(fil);
	while (++x < fil->w)
	{
		while (++i < fil->h)
		{
			j = -1;
			while (++j < fil->w)
			{
				if (fil->hmap[i][j] == 0 || fil->hmap[i][j] == -2)
					heat_up(fil, i, j, x);
			}
		}
		i = -1;
	}
	merge_hmap(fil, tmp);
	free_hmap(&tmp, fil->h);
}
