#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void			*ret;

	ret = (void*)malloc(sizeof(size_t) * size);
	if (ret == NULL)
		return (NULL);
	ft_bzero(ret, size);
	return (ret);
}
