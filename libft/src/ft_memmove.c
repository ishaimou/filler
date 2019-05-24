#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	void	*pt;

	pt = ft_memalloc(len);
	if (pt == NULL)
		return (dst);
	ft_memcpy(pt, src, len);
	ft_memcpy(dst, pt, len);
	free(pt);
	return (dst);
}
