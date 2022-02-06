#include "./ex00/ft_ft.c"
#include "./ex01/ft_ultimate_ft.c"
#include "./ex02/ft_swap.c"
#include "./ex03/ft_div_mod.c"
#include "./ex04/ft_ultimate_div_mod.c"
#include "./ex05/ft_putstr.c"
#include "./ex06/ft_strlen.c"
#include "./ex07/ft_rev_int_tab.c"
//#include "./ex08/ft_sort_int_tab.c"
#include <stdio.h>

int main(){
	int a = 1;
	printf("ex00\nbefore ft_ft : %d\n",a);
	ft_ft(&a);
	printf("after ft_ft : %d\n\n",a);

	int b = -1;
	int *ft_b = &b;
	int **ft2_b = &ft_b;
	int ***ft3_b = &ft2_b;
	int ****ft4_b = &ft3_b;
	int *****ft5_b = &ft4_b;
	int ******ft6_b = &ft5_b;
	int *******ft7_b = &ft6_b;
	int ********ft8_b = &ft7_b;
	printf("ex01\nbefore ft_ultimate_ft : %d\n",********ft8_b);
	ft_ultimate_ft(&ft8_b);
	printf("after ft_ultimate_ft : %d\n\n",********ft8_b);
	
	int first = 12;
	int second = 24;
	printf("ex02\nbefore ft_swap : %d, %d\n",first, second);
	ft_swap(&first, &second);
	printf("after ft_swap : %d, %d\n\n",first, second);

	int div=1;
	int mod=1;
	printf("ex03\nbefore ft_div_mod : %d, %d\n",div, mod);
	ft_div_mod(13, 5, &div, &mod);
	printf("after ft_div_mod : %d, %d\n\n",div, mod); // 2, 3

	int ult_div=120;
	int ult_mod=11;
	printf("ex04\nbefore ft_ultimate_div_mod : %d, %d\n",ult_div, ult_mod);
	ft_ultimate_div_mod(&ult_div, &ult_mod);
	printf("after ft_ultimate_div_mod : %d, %d\n\n",ult_div, ult_mod);

	ft_putstr("ex05\nHello This file is made my sryou...\n");
	char *charr1 = "HEllO!!\n";
	char charr2[10] = {'a','b','c','d','e','\n','f'};
	ft_putstr(charr1);
	ft_putstr(charr2);
	printf("\n\n");

	printf("ex06\n");
	
	printf("17 : %d\n", ft_strlen("Len will be 14"));
	printf("8 : %d\n",ft_strlen(charr1));//8
	printf("7 : %d\n\n",ft_strlen(charr2));//7
	
	int intarr1[20] = {1,2,3,4,5,6,7,8,9,10,11,12,100,2};
	int intarr2[20] = {};
	
	
	printf("ex07\n");
	for(int i=0;i<14;i++){
		printf("%d ",intarr1[i]);
	}
	printf("\n");
	for(int i=0;i<9;i++){
		printf("%d ",intarr2[i]);
	}
	printf("\nWill Turn To...\n");
	ft_rev_int_tab(intarr1, 14);
	ft_rev_int_tab(intarr2, 9);
	for(int i=0;i<14;i++){
		printf("%d ",intarr1[i]);
	}
	printf("\n");
	for(int i=0;i<9;i++){
		printf("%d ",intarr2[i]);
	}
	
	/*
	printf("ex08\n");
	for(int i=0;i<14;i++){
		printf("%d ",intarr1[i]);
	}
	printf("\n");
	for(int i=0;i<9;i++){
		printf("%d ",intarr2[i]);
	}
	printf("\nWill Turn To...\n");
	ft_sort_int_tab(intarr1, 14);
	ft_sort_int_tab(intarr2, 0);
	for(int i=0;i<14;i++){
		printf("%d ",intarr1[i]);
	}
	printf("\n");
	for(int i=0;i<9;i++){
		printf("%d ",intarr2[i]);
	}*/
	


	return 0;
}
