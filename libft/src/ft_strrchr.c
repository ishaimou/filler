#include <string.h>

char	*ft_strrchr(const char *str, int c)
{
	char	*pt;

	pt = (char*)str;
	if (c == '\0')
	{
		while (*pt != '\0')
			pt++;
		return (pt);
	}
	while (*str != '\0')
	{
		if (*str == (const char)c)
			pt = (char*)str;
		str++;
	}
	if (*pt == (char)c)
		return (pt);
	return (0);
}
