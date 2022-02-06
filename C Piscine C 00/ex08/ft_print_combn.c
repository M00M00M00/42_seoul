#include <unistd.h>
void    ft_putchar(char c)
{
    write(1, &c, 1);
}

void    display(int is_selected[], int num_to_print)
{
    int i;
    int cnt;
    int sw;

    i = 0;
    cnt = 0;
    sw = 1;
    while (i < 10)
    {
        if (is_selected[i])
        ft_putchar(i + 48);
        i++;
    }
    while (cnt < num_to_print)
    {
        sw *= is_selected[9 - cnt];
        cnt++;
    }
    if (sw != 1)
    {
        ft_putchar(',');
        ft_putchar(' ');
    }
}

void    dfs(int idx, int cnt, int is_selected[], int num_to_print)
{
    int i;

    i = idx;
    if (cnt == num_to_print)
    {
        display(is_selected, num_to_print);
    }
    while (i < 10)
    {
        if  (is_selected[i] == 0)
        {
            is_selected[i] = 1;
            dfs(i, cnt + 1, is_selected, num_to_print);
            is_selected[i] = 0;
        }
        i++;
    }
}   

void    ft_print_combn(int n)
{
    int idx;
    int cnt;
    int num_to_print;
    int is_selected[10];
    int i;

    idx = 0;
    cnt = 0;
    i = 0;
    num_to_print = n;
    while (i < 10)
    {
        is_selected[i] = 0;
        i++;
    }
    dfs(idx, cnt, is_selected, num_to_print);
}