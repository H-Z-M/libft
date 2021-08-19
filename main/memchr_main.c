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

int main()
{
	int i = 0;
	int sz = 8;
	int diff[sz];
	while (sz--)
		diff[sz] = 0;
	char	src[] = "/|faaaaa\x12\xff\x09\x42\042\42|\\";
	int		size = sizeof(src);
	if (memchr(src, '\x42', size) == ft_memchr(src, '\x42', size))
		diff[i] = 1;
	i++;

	char src2[] = "/|\x12\xff\x09\\200\x42\2002\42|\\";
	size = sizeof(src);
	if (memchr(src2, '\200', size) == ft_memchr(src2, '\200', size))
		diff[i] = 1;
	i++;

	char	src3[] = "/|\x12\xff\x09\x42\042\42|\\";
	size = 2;
	if (memchr(src3, '\x42', size) == ft_memchr(src3, '\x42', size))
		diff[i] = 1;
	i++;

	char	src4[] = "/|\x12\xff\x09\x42\042\42|\\";
	size = sizeof(src);
	if (memchr(src4, '\xde', size) == ft_memchr(src4, '\xde', size))
		diff[i] = 1;
	i++;

	char	src5[] = "nnnnnnniawhf\200wf208awfh\xakufi21f4\x42w7fwa1f";
	size = sizeof(src);
	if (memchr(src5, '\x42', size) == ft_memchr(src5, '\x42', size))
		diff[i] = 1;
	i++;

	size = 15;
	char	*s = electric_alloc(size);
	strcpy(s, ":(){ :|: & };:");
	int err = mprotect(s - 4096 + size, 4096, PROT_READ);
	if (!err)
		diff[i] = 1;
	else
	{
		printf("your memchr crash because it read too many bytes from s or attempt to write on s !\n");
		return 0;
	}
	i++;

	char	src6[] = "/|\x12\xff\\f\x09\0\x42\042\0\42|\\";
	size = 12;
	if (memchr(src6, '\0', size) == ft_memchr(src6, '\0', size))
		diff[i] = 1;
	i++;

	size = 17;
	char	*src7 = malloc(size);
	memset(src, 'A', size);
	if (memchr(src7, '\xde', size) == ft_memchr(src7, '\xde', size))
		diff[i] = 1;
	i++;

	char *c = "memchr";
	printf("\x1b[39m%-14s", c);
	i = 0;
	while (i < 8)
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
	/* memchr(NULL, '\0', 0x20); */
	ft_memchr(NULL, '\0', 0x20);
}
