#include "../libft.h"
#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <sys/mman.h>
/* #include <bsd/string.h> // -lbsd */

/* strlcpy() appends string src to the end of dst.  It will append at most dstsize - strlen(dst) - 1 characters.   */
/* It will then NUL-terminate, unless dstsize is 0 or the original dst string was longer than dstsize */
/* (in practice this should not happen as it means that either dstsize is incorrect or that dst is not a proper string). */

void	*electric_alloc(size_t size)
{
	void	*ptr = mmap(NULL, 8192lu, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);

	memset(ptr, 'Z', 8192lu);
	mprotect(ptr + 4096, 4096, PROT_NONE);
	return (ptr + 4096 - size);
}

void mem_cmp(char *result, char *expected, int len, int n)
{
	if (!result && !expected)
		printf("\x1b[32m[OK:%d] ", n);
	else if (!memcmp(result, expected, len))
		printf("\x1b[32m[OK:%d] ", n);
	else
		printf("\x1b[31m[KO:%d] ", n);
}

void strlcpy_internal(char *str, size_t n)
{
	static int i;
	char	buff1[0xF0];
	char	buff2[0xF0];
	memset(buff1, 'A', n);
	memset(buff2, 'A', n);
	buff1[0xF0 - 1] = 0;
	buff2[0xF0 - 1] = 0;
	strlcpy(buff1, str, n);
	ft_strlcpy(buff2, str, n);
	mem_cmp(buff1, buff2, strlen(str) + 1, ++i);
}

int nanosleep(const struct timespec *request, struct timespec *remain);

enum
{
	SECS_TO_SLEEP = 0,
	NSEC_TO_SLEEP = 100000000
};
struct timespec remaining, request = {SECS_TO_SLEEP, NSEC_TO_SLEEP};

#define		STRING_1	"the cake is a lie !\0I'm hidden lol\r\n"

int main()
{
	char *c = "strlcpy";
	printf("\x1b[39m%-14s", c);
	char	*str = STRING_1;
	strlcpy_internal(str, 0xF0 - 1);

	strlcpy_internal(str, 0xF0);

	str = "hello !";
	strlcpy_internal(str, 20);

	str = "";
	strlcpy_internal(str, 20);

	str = "BBBB";
	strlcpy_internal(str, 20);

	strlcpy_internal(str, 0);

	pid_t childPid;
	switch (childPid = fork())
	{
		case -1:
			printf("fork");
			break;
		case 0:
			printf("\n\t      ");
			printf("\x1b[36m[ft_strlcpy(NULL, str, 10)] => \x1b[39m");
			break;
		default:
			nanosleep(&request, &remaining);
			ft_strlcpy(NULL, str, 10);
			/* ft_strlcpy(str, NULL, 10); */
			/* strlcpy(NULL, NULL, 10); */
			break;
	}
	return 0;
}
