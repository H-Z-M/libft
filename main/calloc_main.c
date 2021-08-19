#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include "../libft.h"
#include <string.h>
#include <ctype.h>
#include <limits.h>

#define ALLOCATE_SIZE   (10)
int main()
{
	int i = 0;
	int sz = 6;
	int diff[sz];
	while (sz--)
		diff[sz] = 0;

	char *ptr = ft_calloc(4, 20);
	if (ptr)
		diff[i] = 1;
	i++;
	free(ptr);

	char *str = ft_calloc(0, 0);
	if (str != NULL)
		diff[i] = 1;
	i++;
	free(str);

	int size = 999;
	void * d1 = ft_calloc(size, sizeof(int));
	void * d2 = calloc(size, sizeof(int));
	if (!memcmp(d1, d2, size * sizeof(int)))
		diff[i] = 1;
	i++;
	free(d1);
	free(d2);

	/* void *d3 = ft_calloc(LONG_MAX, sizeof(char)); */
	void *d3 = ft_calloc(ULONG_MAX, sizeof(char));
	void *d4 = ft_calloc(UINT_MAX, 2);
	void *d44 = calloc(UINT_MAX, 2);
	/* void *d4 = ft_calloc(2, 1073741829); */
	void *d5 = ft_calloc(1, ULONG_MAX);
	/* void *d44 = calloc(2, 1073741829); // overflow the int max */
	/* printf("ULONG_MAX  %lu\n", ULONG_MAX); */
	/* printf("LONG_MAX   %ld\n", LONG_MAX); */
	/* printf("UINT_MAX   %u\n", UINT_MAX); */
	/* printf("INT_MAX    %d\n", INT_MAX); */
	/* printf("SIZE_MAX   %lu\n", SIZE_MAX); */
	if (d3 == NULL)
		diff[i] = 1;
	i++;
	/* if (!memcmp(d4, d44, (size_t)(2 * UINT_MAX))) */
	if (d4 && d44)
		diff[i] = 1;
	i++;
	if (d5 == NULL)
		diff[i] = 1;
	i++;
	free(d3);
	free(d4);
	free(d5);
	free(d44);

	char *c = "calloc";
	printf("\x1b[39m%-14s", c);
	i = 0;
	while (i < 6)
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
}
