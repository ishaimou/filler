#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*pdst;
	unsigned char	*psrc;

	pdst = (unsigned char*)dst;
	psrc = (unsigned char*)src;
	while (n > 0)
	{
		if (*psrc == (unsigned char)c)
		{
			*pdst = (unsigned char)c;
			pdst++;
			return (pdst);
		}
		*pdst = *psrc;
		pdst++;
		psrc++;
		n--;
	}
	return (NULL);
}
