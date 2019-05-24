#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*pt;

	if (len == 0)
		return (b);
	pt = (unsigned char*)b;
	i = 0;
	while (i < len)
	{
		*pt = (unsigned char)c;
		pt++;
		i++;
	}
	return (b);
}
