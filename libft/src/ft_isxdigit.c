int		ft_isxdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	if (c >= 65 && c <= 70)
		return (1);
	if (c >= 97 && c <= 102)
		return (1);
	return (0);
}
