#include <unistd.h>
#include <stdio.h>

void	*ft_print_memory(void *addr, unsigned int size)
{
	void **a;
	unsigned int	cnt;

	cnt = 0;
	while (cnt < size)
	{
		*a = &addr;
		write(1, a, 1);
		cnt++;
		addr++;
	}
	return 0;
}

int	main()
{
	char str[100] = "SRYOU . ~<-9 starts here! I. am./ king?~\n\n\t\"\\happy\\\"";
	printf("----ex12----\n");
	printf("%s\n  %p\n",str, str);
	ft_print_memory(str,55);
	ft_print_memory(str,0);
	ft_print_memory(str+9,13);
}		
