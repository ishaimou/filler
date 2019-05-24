#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;

	if (s != NULL)
	{
		sub = (char*)malloc(sizeof(*sub) * (len + 1));
		if (sub == NULL)
			return (NULL);
		i = 0;
		while (i < len && s[start + i] != '\0')
		{
			sub[i] = s[start + i];
			i++;
		}
		sub[i] = '\0';
		return (sub);
	}
	return (NULL);
}
