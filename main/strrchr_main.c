#include "../libft.h"
#include <stdio.h>
#include <string.h>
#include <sys/mman.h>
/*
 * strrchr() function is identical to strchr(), 
 * except it locates the last occurrence of c.
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

void	*electric_alloc_rev(size_t size)
{
	void	*ptr = mmap(NULL, 8192lu, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);

	memset(ptr, 'Z', 8192lu);
	mprotect(ptr, 4096, PROT_NONE);
	return (ptr + 4096 + size);
}

void cmp(char *result, char *expected, int n)
{
	if (result == expected)
		printf("\x1b[32m[OK:%d] ", n);
	else
		printf("\x1b[31m[KO:%d] ", n);
}

#define		STRING_1	"the cake is a lie !\0I'm hidden lol\r\n"
#define		STRING_2	"there is no stars in the sky"
#define		STRING_3	"test basic !"
#define		STRING_4	"phrase differente pour le test"

int main()
{
	char *c = "strrchr";
	printf("\x1b[39m%-14s", c);
	int i = 0;
	char	*src = STRING_1;
	char	*d1 = strrchr(src, ' ');
	char	*d2 = ft_strrchr(src, ' ');
	cmp(d1, d2, ++i);

	src = "abbbbbbbb";
	d1 = strrchr(src, 'a');
	d2 = ft_strrchr(src, 'a');
	cmp(d1, d2, ++i);

	src = "the cake is a lie !\0I'm hidden lol\r\n";
	d1 = strrchr(src, ' ');
	d2 = ft_strrchr(src, ' ');
	cmp(d1, d2, ++i);

	src = "īœ˙ˀ˘¯ˇ¸¯.œ«‘––™ª•¡¶¢˜ˀ";
	d1 = strrchr(src, L'–');
	d2 = ft_strrchr(src, L'–');
	cmp(d1, d2, ++i);

	src = "there is so \0ma\0ny \0 \\0 in t\0his stri\0ng !\0\0\0\0";
	d1 = strrchr(src, '\0');
	d2 = ft_strrchr(src, '\0');
	cmp(d1, d2, ++i);

	src = "\0";
	d1 = strrchr(src, 'a');
	d2 = ft_strrchr(src, 'a');
	cmp(d1, d2, ++i);

	src = electric_alloc(10);
	strcpy(src, "123456789");
	mprotect(src - 4096 + 10, 4096, PROT_READ);
	ft_strrchr(src, 'a');
	src = electric_alloc_rev(10);
	strcpy(src, "123456789");
	mprotect(src - 10, 4096, PROT_READ);
	d1 = strrchr(src, 'a');
	d2 = ft_strrchr(src, 'a');
	cmp(d1, d2, ++i);

	size_t	size = 1000;
	char	*s = malloc(size + 1);
	memset(s, 'A', size);
	s[size] = 0;
	d1 = strrchr(s, 'B');
	d2 = ft_strrchr(s, 'B');
	cmp(d1, d2, ++i);

	pid_t childPid;
	switch (childPid = fork())
	{
		case -1:
			printf("fork");
			break;
		case 0:
			printf("\n\t      ");
			printf("\x1b[36m[ft_strrchr(NULL, '\\0')] => \x1b[39m");
			break;
		default:
			nanosleep(&request, &remaining);
			ft_strrchr(NULL, '\0');
			break;
	}
	/* ft_strrchr(((void *)0), '\0'); */
}
