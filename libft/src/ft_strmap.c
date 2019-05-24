#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	int		size;
	char	*str;

	if (s && f)
	{
		size = 0;
		while (s[size])
			size++;
		str = (char*)malloc(sizeof(*str) * (size + 1));
		if (str)
		{
			i = 0;
			while (i < size)
			{
				str[i] = (*f)(s[i]);
				i++;
			}
			str[i] = '\0';
		}
		return (str);
	}
	return (NULL);
}
