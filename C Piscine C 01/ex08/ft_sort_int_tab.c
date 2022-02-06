
void sorting(int arr[], int cnt)
{
    int i;
    int temp;

    i = 0;
    temp = 0;
    while (i < cnt)
    {
        if (arr[i] > arr[i + 1])
        {
            temp = arr[i];
            arr[i] = arr[i + 1];
            arr[i + 1] = temp;
        }
        i++;
    }
}

void bubble_sort(int arr[], int size)
{
    int cnt;

    cnt = size - 1;
    while (cnt > 0)
    {
        sorting(arr, cnt);
        cnt--;
    }
}

void    ft_sort_int_tab(int *tab, int size)
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

    bubble_sort(i, size);
    cnt = 0;
    tab -= size;
    while (cnt < size)
    {
        *tab = i[cnt];
        cnt++;
        tab++;
    }
}