#include "../libft.h"
#include <sys/mman.h>
#include <stdio.h>
#include <string.h>

void	*electric_alloc(size_t size)
{
	void	*ptr = mmap(NULL, 8192lu, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);

	memset(ptr, 'Z', 8192lu);
	mprotect(ptr + 4096, 4096, PROT_NONE);
	return (ptr + 4096 - size);
}

void	f(unsigned i, char *s) { *s = i + '0'; }

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
	int i = 0;
	char *c = "striteri";
	printf("\x1b[39m%-14s", c);
	char	b[] = "override this !";
	char	b2[0xF0];
	size_t	size = strlen(b);

	for (size_t i = 0; i < size; i++)
		f(i, b2 + i);
	b2[size] = 0;
	ft_striteri(b, f);
	str_cmp(b, b2, ++i);

	size = 10;
	char	*o = electric_alloc(size);
	strcpy(o, "123456789");
	ft_striteri(o, f);
	printf("\x1b[32m[OK:%d] ", ++i);

	ft_striteri(NULL, f);
	printf("\x1b[32m[OK:%d] ", ++i);

	ft_striteri("you should not ...", NULL);
	printf("\x1b[32m[OK:%d] ", ++i);

	ft_striteri(NULL, NULL);
	printf("\x1b[32m[OK:%d] ", ++i);

	printf("\n");
	return 0;


	char s[] = "Applies the function f to each character of the string passed as argument, and passing its index as first argument.  Each character is passed by address to f to be modified if necessary";
	i = 0;
	while (i < 18)
	{
		ft_striteri(s+i, f);
		printf("|%s|\n",s+i);
		i += 1;
	}
	printf("\n");
	char t[] = "Applies the function f to each character of the string passed as argument, and passing its index as first argument.  Each character is passed by address to f to be modified if necessary";
	i = 160;
	while (i < 185)
	{
		ft_striteri(t+i, f);
		printf("|%s|\n",t+i);
		i += 2;
	}
}
