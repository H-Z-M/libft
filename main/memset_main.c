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
void	*electric_alloc_rev(size_t size)
{
	void	*ptr = mmap(NULL, 8192lu, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);

	memset(ptr, 'Z', 8192lu);
	mprotect(ptr, 4096, PROT_NONE);
	return (ptr + 4096 + size);
}

#define BSIZE 0xff
int main()
{
	int i = 0;
	int sz = 7;
	int diff[sz];
	while (sz--)
		diff[sz] = 0;
	int	size = 20;
	char	b1[BSIZE];
	char	b2[BSIZE];
	memset(b1, 'B', BSIZE);
	memset(b2, 'B', BSIZE);
	memset(b1, 'A', size);
	ft_memset(b2, 'A', size);
	if (!memcmp(b1, b2, BSIZE))
		diff[i] = 1;
	i++;

	size = 22;
	memset(b1, 'B', BSIZE);
	memset(b2, 'B', BSIZE);
	memset(b1, '\200', size);
	ft_memset(b2, '\200', size);
	if (!memcmp(b1, b2, BSIZE))
		diff[i] = 1;
	i++;

	size = 18;
	memset(b1, 'B', BSIZE);

	char	*r1 = memset(b1, 'A', size);
	char	*r2 = ft_memset(b1, 'A', size);
	if (!memcmp(r1, r2, BSIZE))
		diff[i] = 1;
	i++;
	r1 = memset("", 'A', (0));
	r2 = ft_memset("", 'A', 0);
	if (!memcmp(r1, r2, BSIZE))
		diff[i] = 1;
	i++;

#define BFSIZE 0xfff
	char	*bf1 = (char*)malloc(sizeof(char) * (BFSIZE + 1));
	char	*bf2 = (char*)malloc(sizeof(char) * (BFSIZE + 1));
	*bf1 = 0;
	*bf2 = 0;
	memset(bf1, '\5', BFSIZE);
	ft_memset(bf2, '\5', BFSIZE);
	if (!memcmp(bf1, bf2, BFSIZE))
	{
		free(bf1);
		free(bf2);
		diff[i] = 1;
	}
	i++;

	char	buff[BSIZE];
	char	buff2[BSIZE];
	memset(buff, 0, sizeof(buff));
	memset(buff2, 0, sizeof(buff2));
	ft_memset(buff, '\xff', 0);
	memset(buff2, '\xff', (0));
	if (!memcmp(buff, buff2, BSIZE))
		diff[i] = 1;
	i++;

	size = 10;
	char	*bff = electric_alloc(size);
	memset(bff, 0, size);
	int err = mprotect(bff - 4096 + size, 4096, PROT_WRITE);
	if (!err)
	{
		ft_memset(bff, '\xff', size);
		diff[i] = 1;
	}
	i++;

	char *c = "memset";
	printf("\x1b[39m%-14s", c);
	i = 0;
	while (i < 7)
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

	/* ft_memset(NULL, 'a', 12); */
	/* memset(NULL, 'a', 12); */
}
