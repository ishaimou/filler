#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*pt;

	pt = (char*)s;
	while (*pt)
	{
		if (*pt == (char)c)
			return (pt);
		pt++;
	}
	if (c == 0 && *pt == '\0')
		return (pt);
	return (NULL);
}
