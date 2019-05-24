char	*ft_strstr(const char *str, const char *find)
{
	unsigned int	i;
	unsigned int	j;
	char			*pt;

	i = 0;
	if (find[i] == '\0')
		return ((char*)str);
	pt = 0;
	while (str[i] != '\0')
	{
		j = 0;
		if (str[i] == find[j])
		{
			pt = (char*)&str[i];
			while (str[i + j] == find[j])
			{
				if (find[j + 1] == '\0')
					return (pt);
				j++;
			}
			pt = 0;
		}
		i++;
	}
	return (pt);
}
