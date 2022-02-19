#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

typedef struct _dict
{
	char *key;
	char *value;
}dict;

int main() {
    char   buff[1024];
    int    fd;
	int		j;
	int		i;
	int		k;
	int		count;
	dict	*arr;

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
	printf("%s\n", arr[0].key);
	printf("%s\n", arr[0].value);
	printf("%s\n", arr[10].key);
	printf("%s\n", arr[10].value);
	printf("%s\n", arr[40].key);
	printf("%s\n", arr[40].value);
}
