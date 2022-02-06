#include <unistd.h>
#include <stdio.h>

void    ft_ft(int *nbr)
{
    int a;

    a = 42 + '0';
    nbr = &a;
    write(1, nbr, 1);
}

int main()
{
    int a = 1;

    printf("%d", a);
    ft_ft(&a);
    printf("%d", a);
}