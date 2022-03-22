int	is_word(char *str)
{
	int		sw;

	sw = 1;
	while (*str != '\0' && *str != ' ')
	{
		if (*str >= 'a' && *str <= 'z')
			sw *= 1;
		else if (*str >= 'A' && *str <= 'Z')
			sw *= 1;
		else if (*str >= '0' && *str <= '9')
			sw *= 1;
		else
			return(0);
		str++;
	}
	return (1);
}

#include <stdio.h>
int	main(){
	if (is_word("asdfasd"))
		printf("Word!");
	else
		printf("Not Word");
}
