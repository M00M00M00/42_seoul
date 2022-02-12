#include "./ex00/ft_strlen.c"
#include "./ex01/ft_putstr.c"
#include "./ex02/ft_putnbr.c"
#include "./ex03/ft_atoi.c"
#include "./ex04/ft_putnbr_base.c"
#include "./ex05/ft_atoi_base.c"
#include <stdio.h>

int main()
{
	{
		char *str1 = "42Stdheader this len will be = 33";
		char str2[15] = {0,};
		char str3[15] = {-1, -2, 0, 1, 0,};
		printf("----ex00----\n");
		printf("33, 0, 2 : %d, %d, %d\n", ft_strlen(str1), ft_strlen(str2), ft_strlen(str3));
	}
	printf("\n");
	{
		char *str1 = "Hello Thanks for using this testcase";
		char str2[15] = {0,};
		printf("----ex1----\n");
		printf("%s : \n", str1);
		ft_putstr(str1);
		printf("\n");
		printf("[NO PRINT] : \n");
		ft_putstr(str2);
		printf("\n");
	}
	printf("\n");
	{
		printf("----ex02----\n");
		printf("0 : \n");
		ft_putnbr(-0);
		printf("\n");
		printf("2147483647 : \n");
		ft_putnbr(2147483647);
		printf("\n");
		printf("-2147483648 : \n");
		ft_putnbr(-2147483648);
		printf("\n");
		printf("-4242 : \n");
		ft_putnbr(-4242);
		printf("\n");
		printf("123456789 : \n");
		ft_putnbr(123456789);
		printf("\n");
	}
	printf("\n");
	{
		printf("----ex03----\n");
		char *str1 = "   ---+--+1234ab567";
		char *str2 = "  \n \ta-a";
		char *str3 = " \v  ++2147483647";
		char *str4 = " \f  -----+-+001458 24567";
		char *str5 = "\r  \n -+-++-+2147483648";
		printf("%s : %d\n", str1, ft_atoi(str1));
		printf("%s : %d\n", str2, ft_atoi(str2));
		printf("%s : %d\n", str3, ft_atoi(str3));
		printf("%s : %d\n", str4, ft_atoi(str4));
		printf("%s : %d\n", str5, ft_atoi(str5));
	}
	printf("\n");
	{
		printf("----ex04----\n");
		printf("8867\n");
		ft_putnbr_base(1132, "9876543210");
		printf("\n");
		printf("1132: %d\n", ft_atoi_base("8867", "9876543210"));
		printf("\n");

		printf("[SHOULD NOT PRINT]\n");
		ft_putnbr_base(1132, "");
		printf("\n");
		printf("0: %d\n", ft_atoi_base("8867", ""));
		printf("\n");

		printf("[SHOULD NOT PRINT]\n");
		ft_putnbr_base(1132, "aabc!");
		printf("\n");
		printf("0: %d\n", ft_atoi_base("8867", "aabc!"));
		printf("\n");

		printf("-bDBbFjci\n");
		ft_putnbr_base(-2147483648, "abcdefghijABCDEFGHIJ"); // 20base
		printf("\n");
		printf("-2147483648: %d\n", ft_atoi_base("-bDBbFjci", "abcdefghijABCDEFGHIJ"));
		printf("\n");

		printf("*///////\n");
		ft_putnbr_base(2147483647, "!@#$%^&*()<>,.?/"); // 16base
		printf("\n");
		printf("2147483647: %d\n", ft_atoi_base("*///////", "!@#$%^&*()<>,.?/"));
		printf("\n");

		printf("-@@#!\n");
		ft_putnbr_base(-42, "!@#"); // 3base
		printf("\n");
		printf("-42: %d\n", ft_atoi_base("-@@#!", "!@#"));
		printf("\n");
	}
	printf("\n");
}
