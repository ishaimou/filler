#include "libft.h"

char						*ft_ulltoa(unsigned long long int nbr)
{
	unsigned long long int	tmp;
	char					*res;
	unsigned long			size;

	size = 1;
	tmp = nbr;
	while (tmp /= 10)
		size++;
	if (!(res = (char*)malloc(sizeof(char) * (size + 1))))
		return (res);
	res[size] = '\0';
	tmp = nbr;
	while (size-- > 0)
	{
		res[size] = (tmp % 10) + 48;
		tmp /= 10;
	}
	return (res);
}
