int		ft_prime(int nb)
{
	int		i;

	if (nb <= 1)
		return (0);
	i = 2;
	while (i < (nb / 2) + 1)
	{
		if ((nb % i) == 0)
			return (0);
		i++;
	}
	return (1);
}
