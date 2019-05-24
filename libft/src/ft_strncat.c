#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	size_t			i;
	unsigned int	len_dest;

	i = 0;
	len_dest = 0;
	while (dest[len_dest] != '\0')
		len_dest++;
	while ((src[i] != '\0') && (i < n))
	{
		dest[len_dest + i] = src[i];
		i++;
	}
	dest[len_dest + i] = '\0';
	return (dest);
}
