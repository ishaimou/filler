#include "libft.h"

void	ft_putendl(char const *s)
{
	int		i;

	if (s)
	{
		i = 0;
		while (s[i])
		{
			ft_putchar(s[i]);
			i++;
		}
		ft_putchar('\n');
	}
}
