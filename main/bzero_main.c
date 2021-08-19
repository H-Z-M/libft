#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include "../libft.h"

int main()
{
	int sz = 3;
	int diff[sz];
	while (sz--)
		diff[sz] = 0;
	int i = 0;
	char	s[20];
	char	s2[20];

	memset(s, 'a', 20);
	memset(s2, 'a', 20);
	bzero(s, 20);
	ft_bzero(s2, 20);
	if (!memcmp(s, s2, 20))
		diff[i] = 1;
	i++;

	char	buff[40];
	char	buff2[40];
	memset(buff, '\x1', sizeof(buff));
	memset(buff2, '\x1', sizeof(buff2));
	ft_bzero(buff, 0);
	bzero(buff2, (0));
	if (!memcmp(buff, buff2, 40))
		diff[i] = 1;
	i++;

	size_t	size = 1024;
	char	*str = (char *)malloc(sizeof(char) * size);
	char	*str2 = (char *)malloc(sizeof(char) * size);
	memset(str, 'a', size);
	memset(str2, 'a', size);
	bzero(str, size);
	ft_bzero(str2, size);
	if (!memcmp(str, str2, size))
		diff[i] = 1;
	i++;
	free(str);
	free(str2);

	char *c = "bzero";
	printf("\x1b[39m%-14s", c);
	i = 0;
	while (i < 3)
	{
		if (diff[i] == 1)
		{
			printf("\x1b[32m[OK:%d] ", i+1);
		}
		else if (diff[i] == 0)
		{
			printf("\x1b[31m[KO:%d] ", i+1);
		}
		else
			printf("\x1b[35m[??:%d] ", i+1);
		i++;
	}
	printf("\n");
	return 0;
	printf("SEGMENTATION FAULT\n");
	ft_bzero(NULL, 0x12);
	bzero(NULL, 0x12);
}
