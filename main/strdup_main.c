#include "../libft.h"
#include <stdio.h>
#include <string.h>
#include <sys/mman.h>

void	*electric_alloc(size_t size)
{
	void	*ptr = mmap(NULL, 8192lu, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);

	memset(ptr, 'Z', 8192lu);
	mprotect(ptr + 4096, 4096, PROT_NONE);
	return (ptr + 4096 - size);
}

void str_cmp(char *result, char *expected, int n)
{
	if (!result && !expected)
		printf("\x1b[32m[OK:%d] ", n);
	else if (!strcmp(result, expected))
		printf("\x1b[32m[OK:%d] ", n);
	else
		printf("\x1b[31m[KO:%d] ", n);
}

int main()
{
	char *c = "strdup";
	printf("\x1b[39m%-14s", c);
	int i = 0;
	char	*tmp = "OUE \0 pas!";
	str_cmp(ft_strdup(tmp), tmp, ++i);

	tmp = "";
	str_cmp(ft_strdup(tmp), tmp, ++i);

	tmp = "this is a normal test";
	str_cmp(ft_strdup(tmp), tmp, ++i);

	tmp = "I malloc so I am.";
	str_cmp(ft_strdup(tmp), tmp, ++i);

	char *ptr = electric_alloc(10);
	strcpy(ptr, "\xd\xe\xa\xd\xb\xe\xe\xf.");
	mprotect(ptr - 4096 + 10, 4096, PROT_READ);
	str_cmp(ft_strdup(ptr), ptr, ++i);

	char *p = ft_strdup("lol");
	free(p);
	printf("\x1b[32m[OK:%d] ", ++i);

	printf("\n");
	return 0;


	char s[] = "strdup() function allocates sufficient memory for a copy of the string s1, does the copy, and returns a pointer to it.  The pointer may subsequently be used as an argument to the function free(3).";
	i = 33;
	while (i < 243)
	{
		if (strcmp(ft_strdup(s+i),strdup(s+i)))
		{
			printf("DIFF\n");
			return 0;
		}
		printf("ft_strdup => %s\n",(char *)ft_strdup(s+i));
		printf("   strdup => %s\n",(char *)strdup(s+i));
		i += 20;
	}
	printf("NO DIFF\n");
	/* return 0; */
	printf("\n");
	/* char *n = ""; */
	i = 36;
	while (i < 243)
	{
		char *t = ft_strdup(s+i);
		char *m = strdup(s+i);
		printf("ft_strdup => %s\n",t);
		printf("   strdup => %s\n",m);
		i += 22;
	}
}

