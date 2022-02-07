int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 != '\0')
	{
		if (*s2 == '\0')
			return (*s1);
		else if (*s1 > *s2)
			return (*s1 - *s2);
		else if (*s1 < *s2)
			return (*s1 - *s2);
		else
		{
			s1++;
			s2++;
		}
	}
	if (*s2 == '\0')
		return (0);
	else
	{
		*s2 *= -1;
		return (*s2);
	}
}
