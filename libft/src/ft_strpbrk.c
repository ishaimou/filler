#include "libft.h"

char	*ft_strpbrk(const char *s1, const char *s2)
{
	char	*pt1;
	char	*pt2;

	if (!s1 || !s2)
		return (NULL);
	pt1 = (char*)s1;
	while (*pt1)
	{
		pt2 = (char*)s2;
		while (*pt2)
		{
			if (*pt2 == *pt1)
				return (pt1);
			pt2++;
		}
		pt1++;
	}
	return (NULL);
}
