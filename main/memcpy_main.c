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

int main()
{
	int i = 0;
	int sz = 7;
	int diff[sz];
	while (sz--)
		diff[sz] = 0;
	char	src[] = "J'ai fait une copie.";
	char	buff1[22];
	char	buff2[22];

	memcpy(buff1, src, 21);
	ft_memcpy(buff2, src, 21);
	if (!memcmp(buff1, buff2, 21))
		diff[i] = 1;
	i++;

	char	*r1 = memcpy(buff1, src, 21);
	char	*r2 = ft_memcpy(buff1, src, 21);
	if (!memcmp(r1, r2, 21))
		diff[i] = 1;
	i++;

	r1 = memcpy("", src, 0);
	r2 = ft_memcpy("", src, 0);
	if (!memcmp(r1, r2, 0))
		diff[i] = 1;
	i++;

#define		STRING_1	"J'ai fait une copie!\0 ...\r\n"
#define		STRING_2	"there is no stars in the sky"
#define		STRING_3	"test basic !"
#define		STRING_4	"phrase differente pour le test"

	char	buff[] = "test 0 du memcpy !";
	char	*src4 = STRING_4;
	char	buff4[] = STRING_4;

	ft_memcpy(buff4, buff, 0);
	if (!memcmp(src4, buff4, strlen(buff4)))
		diff[i] = 1;
	i++;

	char	src3[] = STRING_3;
	char	buff5[] = STRING_1;
	char	buff6[] = STRING_1;

	memcpy(buff5, src3, strlen(src3));
	ft_memcpy(buff6, src3, strlen(src3));
	if (!memcmp(buff5, buff6, strlen(buff6)))
		diff[i] = 1;
	i++;

typedef struct	s_tests {
	char					data[128];
	void					*ptr;
	unsigned long long int	olol;
	int						flags;
}				t_test;

	t_test test = { "uuuuu®sssssus",
					(void*)0xdeadbeef,
					0x42424242424242L,
					0b1010100010 };
	char	b1[0xF00];
	char	b2[0xF00];
	memcpy(b1, &test, sizeof(test));
	ft_memcpy(b2, &test, sizeof(test));
	if (!memcmp(b1, b2, strlen(b2)))
		diff[i] = 1;
	i++;

	const size_t	size = 10;
	char	*s = electric_alloc(size);
	char	*b = electric_alloc(size);

	strcpy(s, "UUUZZZZZZ");

	int err = mprotect(b - 4096 + size, 4096, PROT_WRITE);
	int err2 = mprotect(s - 4096 + size, 4096, PROT_READ);
	if (err || err2)
	{
		printf("mprotect\n");
		return 0;
	}
	else
	{
		ft_memcpy(b, s, size);
		diff[i] = 1;
	}
	i++;


	char *c = "memcpy";
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

	ft_memcpy(NULL, NULL, 0);
	memcpy(NULL, NULL, 0);
	ft_memcpy(NULL, NULL, 3);
	memcpy(NULL, NULL, 3);

	/* ft_memcpy("", "segfaulter tu dois", 17); */
	/* memcpy("", "segfaulter tu dois", 17); */
	/* ft_memcpy(NULL, "segfaulter tu dois", 17); */
	/* memcpy(NULL, "segfaulter tu dois", 17); */
	/* ft_memcpy("            ", NULL, 17); */
	/* memcpy("            ", NULL, 17); */
	return 0;
}
