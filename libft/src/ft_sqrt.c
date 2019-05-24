int		ft_sqrt(int nb)
{
	int		i;
	int		n;

	if (nb == 0 || nb == 1)
		return (nb);
	i = 1;
	n = 1;
	while (n < nb)
	{
		i++;
		n = i * i;
	}
	if (n == nb)
		return (i);
	else
		return (0);
}
