#include "../libft.h"
#include <stdio.h>
#include <string.h>
#include <sys/mman.h>
/*
 * strchr() function locates the first occurrence of c (converted to a char)
 * in the string pointed to by s.  The terminating null character is considered
 * to be part of the string; therefore if c is `\0', the functions locate the terminating `\0'.
 */

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
	char *c = "strchr";
	printf("\x1b[39m%-14s", c);
	int i = 0;
	char *src = "the cake is a lie !\0I'm hidden lol\r\n";
	str_cmp(ft_strchr(src, ' '), strchr(src, ' '), ++i);

	str_cmp(ft_strchr(src, 't'), strchr(src, 't'), ++i);

	str_cmp(ft_strchr(src, '!'), strchr(src, '!'), ++i);

	str_cmp(ft_strchr(src, 'x'), strchr(src, 'x'), ++i);

	src = "īœ˙ˀ˘¯ˇ¸¯.œ«‘––™ª•¡¶¢˜ˀ";
	str_cmp(ft_strchr(src, L'–'), strchr(src, L'–'), ++i);

	src = "AA\0B";
	str_cmp(ft_strchr(src, 'B'), strchr(src, 'B'), ++i);

	src = "there is so \0ma\0ny \0 \\0 in t\0his stri\0ng !\0\0\0\0";
	str_cmp(ft_strchr(src, '\0'), strchr(src, '\0'), ++i);

	src = "\0";
	str_cmp(ft_strchr(src, 'a'), strchr(src, 'a'), ++i);

	char	*s = electric_alloc(10);
	strcpy(s, "123456789");
	mprotect(s - 4096 + 10, 4096, PROT_READ);
	str_cmp(ft_strchr(s, 'a'), strchr(s, 'a'), ++i);

	size_t	size = 0xF * 16;
	char	*f = malloc(size + 1);
	memset(f, 'A', size);
	f[size] = 0;
	str_cmp(ft_strchr(f, 'B'), strchr(f, 'B'), ++i);
}
