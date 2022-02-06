int ft_strlen(char *str)
{
    int cnt;

    cnt = 0;
    while (*str != '\0')
    {
        cnt++;
        str++;
    }
    return (cnt);
}