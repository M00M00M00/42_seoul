void    ft_rev_int_tab(int *tab, int size)
{
    int i[size];
    int cnt;

    cnt = 0;
    while (cnt < size)
    {
        i[cnt] = *tab;
        cnt++;
        tab++;
    }

    tab -= size;

    while (cnt >= 0)
    {
        *tab = i[cnt - 1];
        cnt--;
        tab++;
    }
}