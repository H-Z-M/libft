#include "../libft.h"
#include <stdio.h>
#include <string.h>
#include <sys/mman.h>

/* Allocates (with malloc(3)) and returns a copy of/
* ’s1’ with the characters specified in ’set’ removed/
* from the beginning and the end of the string.
*/

void	*electric_alloc(size_t size)
{
	void	*ptr = mmap(NULL, 8192lu, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);

	memset(ptr, 'Z', 8192lu);
	mprotect(ptr + 4096, 4096, PROT_NONE);
	return (ptr + 4096 - size);
}

void str_ncmp(char *result, char *expected, int len, int n)
{
	if (!(strncmp(result, expected, len)))
		printf("\x1b[32m[OK:%d] ", n);
	else
		printf("\x1b[31m[KO:%d] ", n);
}

int main()
{
	char *c = "substr";
	printf("\x1b[39m%-14s", c);
	int i = 0;

	char *str = "i just want this part #############";
	size_t size = 22;
	char *ret = ft_substr(str, 0, size);
	str_ncmp(ret, str, size, ++i);


	str = "i just want this part #############";
	size = 20;
	ret = ft_substr(str, 5, size);
	str_ncmp(ret, str+5, size, ++i);

	str = "";
	size = 0;
	ret = ft_substr(str, 5, size);
	str_ncmp(ret, str+5, size, ++i);

	str = "i just want this part #############";
	size = 10;
	ret = ft_substr(str, 5, size);
	str_ncmp(ret, str+5, size, ++i);

	char p[] = "i just want this part #############";
	size = 20;
	ret = ft_substr(str, 5, size);
	p[size + 5] = 0;
	if (!memcmp(ret, p + 5, size + 1))
		printf("\x1b[32m[OK:%d] ", ++i);
	else
		printf("\x1b[31m[KO:%d] ", ++i);


	char *s = "malloc protection !";
	ret = ft_substr(s, 0, 5);
	free(ret);
	ret = NULL;
	if (ret == ((void *)0))
		printf("\x1b[32m[OK:%d] ", ++i);
	else
		printf("\x1b[31m[KO:%d] ", ++i);

	s = "all of this !";
	size = strlen(s);
	ret = ft_substr(s, 0, size);
	if (!strcmp(s, ret))
		printf("\x1b[32m[OK:%d] ", ++i);
	else
		printf("\x1b[31m[KO:%d] ", ++i);

	size = 10;
	str = electric_alloc(size);
	strcpy(str, "YOLO !!!!");
	ret = ft_substr(str, 0, size);
	if (!strcmp(str, ret))
		printf("\x1b[32m[OK:%d] ", ++i);
	else
		printf("\x1b[31m[KO:%d] ", ++i);

	str = "01234";
	size = 10;
	ret = ft_substr(str, 10, size);
	str_ncmp(ret, "", size, ++i);

	ft_substr(NULL, 0, 12);
	printf("\n");
	return 0;
}
