#include "../libft.h"
#include <stddef.h>
#include <stdio.h>
#include <string.h>

char	f_strmapi(unsigned i, char c) { return (c + i); }

void str_cmp(char *result, char *expected, int n)
{
	if (!result && !expected)
		printf("\x1b[32m[OK:%d] ", n);
	else if (!strcmp(result, expected))
		printf("\x1b[32m[OK:%d] ", n);
	else
		printf("\x1b[31m[KO:%d] ", n);
}

#ifdef __linux__
#include <malloc.h>
size_t allocation_size(char *ret)
{
	return (malloc_usable_size(ret));
	printf("This is linux\n");
}
#else
#include <malloc/malloc.h>
size_t allocation_size(char *ret)
{
	return (malloc_size(ret));
	printf("This is not linux\n");
}
#endif

int main()
{
	char *c = "strmapi";
	printf("\x1b[39m%-14s", c);
	int i = 0;

	char	*b = "override this !";
	char	b2[0xF0];
	size_t	size = strlen(b);

	for (size_t i = 0; i < size; i++)
		b2[i] = f_strmapi(i, b[i]);
	b2[size] = 0;
	char	*ret = ft_strmapi(b, f_strmapi);
	str_cmp(b2, ret, ++i);

	/* size_t alloc_size = allocation_size(ret); */
	/* if (alloc_size == size + 1) */
	/* 	printf("\x1b[32m[OK:%d] ", ++i); */
	/* else */
	/* 	printf("\x1b[31m[KO:%d] ", ++i); */

	char	*bb = "override this !  fffffff";
	char	n2[0xF0];
	size = strlen(bb);
	for (size_t i = 0; i < size; i++)
		n2[i] = f_strmapi(i, bb[i]);
	n2[size] = 0;
	ret = ft_strmapi(bb, f_strmapi);
	if (!memcmp(n2, ret, size + 1))
		printf("\x1b[32m[OK:%d] ", ++i);
	else
		printf("\x1b[31m[KO:%d] ", ++i);

	/* alloc_size = allocation_size(ret); */
	/* if (alloc_size == size + 1) */
	/* 	printf("\x1b[32m[OK:%d] ", ++i); */
	/* else */
	/* 	printf("\x1b[31m[KO:%d] ", ++i); */

	ft_strmapi(NULL, f_strmapi);
	ft_strmapi("o", NULL);
	ft_strmapi(NULL, NULL);
	printf("\x1b[32m[OK:%d] ", ++i);
	printf("\n");
}
