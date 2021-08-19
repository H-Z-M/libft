#include "../libft.h"
#include <stdio.h>
#include <string.h>
#include <sys/mman.h>

/*
 * strnstr() function locates the first occurrence of the null-terminated 
 * string needle in the string haystack, where not more than len characters are
 * searched.  Characters that appear after a `\0' character are not searched.
 * Since the strnstr() function is a FreeBSD specific API, it should only be used
 * when portability is not a concern.
*/

int nanosleep(const struct timespec *request, struct timespec *remain);

enum
{
	SECS_TO_SLEEP = 0,
	NSEC_TO_SLEEP = 100000000
};
struct timespec remaining, request = {SECS_TO_SLEEP, NSEC_TO_SLEEP};

void	*electric_alloc(size_t size)
{
	void	*ptr = mmap(NULL, 8192lu, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);

	memset(ptr, 'Z', 8192lu);
	mprotect(ptr + 4096, 4096, PROT_NONE);
	return (ptr + 4096 - size);
}

void cmp(char *result, char *expected, int n)
{
	if (result == expected)
		printf("\x1b[32m[OK:%d] ", n);
	else
		printf("\x1b[31m[KO:%d] ", n);
}

int main()
{
	char *c = "strnstr";
	printf("\x1b[39m%-14s", c);
	int i = 0;
	char *s1 = "see FF your FF return FF now FF";
	char *s2 = "FF";
	size_t max = strlen(s1);
	char *i1 = strnstr(s1, s2, max);
	char *i2 = ft_strnstr(s1, s2, max);
	cmp(i1, i2, ++i);

	s1 = "FF";
	s2 = "see F your F return F now F";
	max = strlen(s2);
	i1 = strnstr(s1, s2, max);
	i2 = ft_strnstr(s1, s2, max);
	cmp(i1, i2, ++i);

	s1 = "MZIRIBMZIRIBMZE123";
	s2 = "MZIRIBMZE";
	max = strlen(s2);
	i1 = strnstr(s1, s2, max);
	i2 = ft_strnstr(s1, s2, max);
	cmp(i1, i2, ++i);

	char *big = "abcdef";
	char *little = "abcdefghijklmnop";
	max = strlen(big);
	i1 = strnstr(big, little, max);
	i2 = ft_strnstr(big, little, max);
	cmp(i1, i2, ++i);

	big = "123456789";
	little = "9";
	max = 8;
	i1 = strnstr(big, little, max);
	i2 = ft_strnstr(big, little, max);
	cmp(i1, i2, ++i);

	s1 = "";
	s2 = "oh no not the empty string !";
	max = strlen(s2);
	i1 = strnstr(s1, s2, max);
	i2 = ft_strnstr(s1, s2, max);
	cmp(i1, i2, ++i);

	s1 = "oh no not the empty string !";
	s2 = "";
	max = strlen(s1);
	i1 = strnstr(s1, s2, max);
	i2 = ft_strnstr(s1, s2, max);
	cmp(i1, i2, ++i);

	s1 = "oh no not the empty string !";
	s2 = "";
	max = 0;
	i1 = strnstr(s1, s2, max);
	i2 = ft_strnstr(s1, s2, max);
	cmp(i1, i2, ++i);

	s1 = "AAAAAAAAAAAAA";
	max = strlen(s1);
	i1 = strnstr(s1, s1, max);
	i2 = ft_strnstr(s1, s1, max);
	cmp(i1, i2, ++i);

	s1 = "A";
	i1 = strnstr(s1, s1, 2);
	i2 = ft_strnstr(s1, s1, 2);
	cmp(i1, i2, ++i);

	s1 = "A";
	i1 = strnstr(s1, s1, 2);
	i2 = ft_strnstr(s1, s1, 2);
	cmp(i1, i2, ++i);

	size_t size = 20;
	s1 = electric_alloc(size);
	s2 = electric_alloc(size);
	strcpy(s1, "is there a nyacat ?");
	strcpy(s2, "is there a nyacat ?");
	mprotect(s1 - 4096 + size, 4096, PROT_READ);
	mprotect(s2 - 4096 + size, 4096, PROT_READ);
	i1 = ft_strnstr(s1, s2, size);
	i2 = strnstr(s1, s2, size);
	cmp(i1, i2, ++i);

	size = 255;
	char	*p2 = "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAB";
	char	*p1 = malloc(size + 1);
	memset(p1, 'A', size);
	p1[size] = 0;
	i1 = strnstr(p1, p2, size);
	i2 = ft_strnstr(p1, p2, size);
	cmp(i1, i2, ++i);

	pid_t childPid;
	switch (childPid = fork())
	{
		case -1:
			printf("fork");
			break;
		case 0:
			printf("\n\t      ");
			printf("\x1b[36m[ft_strnstr(NULL, \"fake\", 3)] => \x1b[39m");
			break;
		default:
			nanosleep(&request, &remaining);
			ft_strnstr(NULL, "fake", 3);
			/* ft_strnstr("fake", NULL, 3); */
			break;
	}
	/* ft_strnstr("fake", ((void *)0), 3); */
	/* ft_strnstr(((void *)0), "fake", 3); */
}
