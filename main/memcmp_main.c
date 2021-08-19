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
	char	*s1 = "\xff\xaa\xde\x12X012345";
	char	*s2 = "\xff\xaa\xde\x12X012345";
	size_t	size = 10;
	int		i1 = memcmp(s1, s2, size);
	int		i2 = ft_memcmp(s1, s2, size);
	if (i1 == i2)
		diff[i] = 1;
	i++;


	s1 = "\xff\xaa\xde\x12wxyz";
	s2 = "\xff\xaa\xde\x12macosx";
	size = 7;
	i1 = memcmp(s1, s2, size);
	i2 = ft_memcmp(s1, s2, size);
	if (i1 == i2)
		diff[i] = 1;
	i++;

	s1 = "\xff\xaa\xde\x12";
	s2 = "\xff\xaa\xde\x12MACOSAAAAA";
	size = 4;
	i1 = memcmp(s1, s2, size);
	i2 = ft_memcmp(s1, s2, size);
	if (i1 == i2)
		diff[i] = 1;
	i++;

	s1 = "\xff\xaa\xde\xff\xff";
	s2 = "\xff\xaa\xde\x02";
	size = 8;
	i1 = memcmp(s1, s2, size);
	i2 = ft_memcmp(s1, s2, size);
	if (i1 == i2)
		diff[i] = 1;
	i++;

	s1 = "vimer\0\0\0\0";
	s2 = "vimer\0abc";
	size = 8;
	i1 = memcmp(s1, s2, size);
	i2 = ft_memcmp(s1, s2, size);
	if (i1 == i2)
		diff[i] = 1;
	i++;

	s1 = "\xff\xaa\xde\200";
	s2 = "\xff\xaa\xde\0";
	size = 8;
	i1 = memcmp(s1, s2, size);
	i2 = ft_memcmp(s1, s2, size);
	if (i1 == i2)
		diff[i] = 1;
	i++;

	s1 = "\xff\0\0\xaa\0\xde\xffnon\xff";
	s2 = "\xff\0\0\xaa\0\xde\x00oui";
	size = 9;
	i1 = memcmp(s1, s2, size);
	i2 = ft_memcmp(s1, s2, size);
	if (i1 == i2)
		diff[i] = 1;
	i++;

	size = 10;
	char	*b1 = electric_alloc(size);
	char	*b2 = electric_alloc(size);
	strcpy(b1, ".........");
	strcpy(b2, ".........");
	int err = mprotect(b1 - 4096 + size, 4096, PROT_READ);
	int err2 = mprotect(b2 - 4096 + size, 4096, PROT_READ);
	if (err || err2)
	{
		printf("mprotect\n");
		return 0;
	}
	int f = ft_memcmp(b1, b2, size);
	if (!f)
		diff[i] = 1;
	i++;

	char *c = "memcmp";
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
	/* ft_memcmp(b1, NULL, 4); */
	/* memcmp(NULL, b1, 4); */
}
