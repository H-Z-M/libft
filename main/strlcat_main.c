#include "../libft.h"
#include <stdio.h>
#include <string.h>
#include <sys/mman.h>

#ifdef __linux__
#include <bsd/string.h> // -lbsd
#endif

/* strlcat() appends string src to the end of dst.  It will append at most dstsize - strlen(dst) - 1 characters.   */
/* It will then NUL-terminate, unless dstsize is 0 or the original dst string was longer than dstsize */
/* (in practice this should not happen as it means that either dstsize is incorrect or that dst is not a proper string). */

void	*electric_alloc(size_t size)
{
	void	*ptr = mmap(NULL, 8192lu, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);

	memset(ptr, 'Z', 8192lu);
	mprotect(ptr + 4096, 4096, PROT_NONE);
	return (ptr + 4096 - size);
}

int nanosleep(const struct timespec *request, struct timespec *remain);

enum
{
	SECS_TO_SLEEP = 0,
	NSEC_TO_SLEEP = 100000000
};
struct timespec remaining, request = {SECS_TO_SLEEP, NSEC_TO_SLEEP};

#define		STRING_1	"the cake is a lie !\0I'm hidden lol\r\n"
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
	char *c = "strlcat";
	printf("\x1b[39m%-14s", c);

	char			*str = STRING_1;
	char	buff1[0xF00] = "overlap.";
	char	buff2[0xF00] = "overlap.";
	size_t	max = strlen(str) + 4;
	int b1 = strlcat(buff1, str, max);
	int b2 = ft_strlcat(buff2, str, max);
	str_cmp(buff1, buff2, ++i);

	if (b1 == b2)
		printf("\x1b[32m[OK:%d] ", ++i);
	else
		printf("\x1b[31m[KO:%d] ", ++i);

	char	s1[4] = "";
	char	s2[4] = "";
	b1 = strlcat(s1, "thx to ntoniolo for this test !", 4);
	b2 = ft_strlcat(s2, "thx to ntoniolo for this test !", 4);
	if (b1 == b2)
		printf("\x1b[32m[OK:%d] ", ++i);
	else
		printf("\x1b[31m[KO:%d] ", ++i);

	char	bf1[0xF00] = "If the src and dst strings overlap, the behavior is undefined.";
	char	bf2[0xF00] = "If the src and dst strings overlap, the behavior is undefined.";
	max = 0;
	b1 = strlcat(bf1, str, max);
	b2 = ft_strlcat(bf2, str, max);
	str_cmp(bf1, bf2, ++i);

	max = strlen(str) + strlen(str);
	b1 = strlcat(bf1, str, max);
	b2 = ft_strlcat(bf2, str, max);
	str_cmp(bf1, bf2, ++i);


	char	f1[0xF00] = STRING_1;
	char	f2[0xF00] = STRING_1;
	strlcat(f1, str, max);
	ft_strlcat(f2, str, max);
	str_cmp(f1, f2, ++i);

	str = "";
	char	bff1[0xF00] = STRING_1;
	char	bff2[0xF00] = STRING_1;
	max = strlen(STRING_1) + 1;
	strlcat(bff1, str, max);
	ft_strlcat(bff2, str, max);
	str_cmp(bff1, bff2, ++i);

	str = STRING_1;
	char	em1[0xF00] = "";
	char	em2[0xF00] = "";
	max = strlen(STRING_1) + 1;
	strlcat(em1, str, max);
	ft_strlcat(em2, str, max);
	str_cmp(em1, em2, ++i);

	str = "n\0AA";
	char	n1[0xF00] = "\0AAAAAAAAAAAAAAAA";
	char	n2[0xF00] = "\0AAAAAAAAAAAAAAAA";
	max = 10;
	strlcat(n1, str, max);
	ft_strlcat(n2, str, max);
	str_cmp(n1, n2, ++i);

	const size_t	size = 10;
	char	*s = electric_alloc(size);
	char	*b = electric_alloc(size);
	strcpy(b, "AB");
	strcpy(s, "CDEFGHI");
	mprotect(s - 4096 + size, 4096, PROT_READ);
	ft_strlcat(b, s, 10);
	printf("\x1b[32m[OK:%d] ", ++i);

	pid_t childPid;
	switch (childPid = fork())
	{
		case -1:
			printf("fork");
			break;
		case 0:
			printf("\n\t      ");
			printf("\x1b[36m[ft_strlcat(NULL, str, 10)] => \x1b[39m");
			break;
		default:
			nanosleep(&request, &remaining);
			ft_strlcat(NULL, str, 10);
			break;
	}
	return 0;
}
