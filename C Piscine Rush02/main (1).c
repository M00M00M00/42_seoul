/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main (1).c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukim <mukim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 16:03:50 by sangjupa          #+#    #+#             */
/*   Updated: 2022/02/19 19:24:53 by mukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int ft_strlen(char *str)
{
    int index;
    index = 0;
    while (str[index] != '\0')
    {
        index++;
    }
    return (index);
}
void put_str(char* str)
{
	while(*str)
	{
		write(1,str,1);
		str++;
	}
}
int ft_atoi(char *str)
{
    int     minus;
    int     return_value;
    minus = 1;
    return_value = 0;
    while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\v'
        || *str == '\f' || *str == '\r')
        str++;
    if (*str == '+' || *str == '-')
    {
        if (*str == '-')
            minus *= (-1);
        str++;
    }
    while (*str >= '0' && *str <= '9')
    {
        return_value = return_value * 10 + *str - '0';
        str++;
    }
    return (minus * return_value);
}
typedef struct _dict
{
    char *key;
    char *value;
}dict;
dict    *make_dict(void)
{
    char   buff[1024];
    int    fd;
    int     j;
    int     i;
    int     k;
    int     count;
    dict    *arr;
    i = 0;
    k = 0;
    count = 0;
    if ( 0 < ( fd = open( "./numbers.dict", O_RDONLY))){
        read( fd, buff, 1024);
        close( fd);
    } 
    while (buff[i])
    {
        if(buff[i] == '\n')
            count++;
        i++;
    }
    arr = (dict *)malloc(sizeof(dict) * count);
    i = 0;
    while (i < count)
    {
        arr[i].key = (char *) malloc (sizeof(char) * 100);
        arr[i].value = (char *) malloc (sizeof(char) * 100);
        i++;
    }
    i = 0;
    while (i < count)
    {
        j = 0;
        while (buff[k] != ':')
            arr[i].key[j++] = buff[k++];
        arr[i].key[j] = '\0';
        j = 0;
        k += 2; 
        while (buff[k] != '\n' && buff[k] != '\0')
            arr[i].value[j++] = buff[k++];
        arr[i].value[j] = '\0';
        k++;
        i++;
    }
    return arr;
}
void	put_digit(char now, int jari)
{
	if(now == '0')
		return ;
	if (jari / 3 == 1)
		write(1, "thousand", 8);
	else if (jari / 3 == 2)
		write(1, "million", 7);
	else if (jari / 3 == 3)
		write(1, "billion", 7);
	else if (jari / 3 == 4)
		write(1, "trillion", 8);
	else if (jari / 3 == 5)
		write(1, "quatrillion", 11);
	else if (jari / 3 == 6)
		write(1, "quintillion", 11);
	write(1, " ", 1);
}


void	put1(char prev, char now, dict* arr)
{
	if(now == '0')
		return ;
	if(prev == 0)
	{
		put_str(arr[now - '0'].value);
		write(1, " ",1);
		return ;
	}
	if(prev - '0' == 1)
		return ;
	put_str(arr[now - '0'].value); 
	write(1, " ", 1);
}

void	put2(char now, char next, dict* arr)
{
	if(now == '0')
		return ;
	else if(now - '0' == 1)
	{
		put_str(arr[10 + (next - '0')].value);
	}
	else
	{
		put_str(arr[20 + (now - '0') - 2].value); 
	}
	write(1, " ", 1);
}

void	put0(char now, dict* arr)
{
	if(now == '0')
		return ;
	put_str(arr[now - '0'].value); 
	write(1, " ", 1);
	put_str("hundred");
	write(1, " ", 1);
}

int main(int argc, char **argv) 
{
    dict    *arr;
    int len;
    int i;
    arr = make_dict();
	i = 0;
    if(argc == 2)
    {
        len = ft_strlen(argv[1]);
        while(argv[1][i])
        {
            if((len - i) % 3 == 0)
            {
				put0(argv[1][i], arr);
            }
            else if((len - i) % 3 == 1)
            {
				if(i!=0)
				{
                	put1(argv[1][i-1], argv[1][i], arr);
                	put_digit(argv[1][i], len - i);
				}
				else
				{
					put1(0,argv[1][i], arr);
            		put_digit(argv[1][i], len - i);
				}
			}
			else if((len - i) % 3 == 2)
			{
				put2(argv[1][i], argv[1][i+1], arr);
			}
			i++;
        }
    }
}
