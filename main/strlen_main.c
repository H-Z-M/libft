#include "../libft.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <string.h>
#include <fcntl.h>
#include <time.h>
//#include <bsd/string.h> // -lbsd

//strlen() function calculates the length of the string pointed to by s,
//excluding the terminating null byte ('\0').

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

int main()
{
	char *c = "strlen";
	printf("\x1b[39m%-14s", c);
	int		i = 0;
	int		f = 1;
	int		r1;
	int		r2;
	char	buff[0x100];
	int		offset;
	int		rnd_fd = open("/dev/urandom", O_RDONLY);
	int test_count = 9001;

	if (rnd_fd < 0)
		printf("fd < 0\n");
	srand(clock());
	for (int j = 0; j < test_count; j++)
	{
		if (read(rnd_fd, buff, sizeof(buff)) > 0)
		{
			offset = rand() % sizeof(buff);
			buff[sizeof(buff) - 1] = 0;
			if ((r1 = ft_strlen(buff + offset)) != (r2 = strlen(buff + offset))) {
				printf("\x1b[31m[KO:%d] ", ++i);
				f = 0;
				break ;
			}
		}
	}
	if (f)
		printf("\x1b[32m[OK:%d] ", ++i);

	char *str = "01234567, AAAAAA, abc\xba e, ......, end of string !";
	if ((r1 = ft_strlen(str)) != (r2 = strlen(str)))
		printf("\x1b[31m[KO:%d] ", ++i);
	else
		printf("\x1b[32m[OK:%d] ", ++i);

	str = "♫♪.ılılıll|̲̅̅●̲̅̅|̲̅̅=̲̅̅|̲̅̅●̲̅̅|llılılı.♫♪";
	if ((r1 = ft_strlen(str)) != (r2 = strlen(str)))
		printf("\x1b[31m[KO:%d] ", ++i);
	else
		printf("\x1b[32m[OK:%d] ", ++i);

	char	*s = "HAHAHAHA \0 TA FAIL XD";
	if ((r1 = ft_strlen(s)) != (r2 = strlen(s)))
		printf("\x1b[31m[KO:%d] ", ++i);
	else
		printf("\x1b[32m[OK:%d] ", ++i);

	const size_t	size = 37;
	char	*p = electric_alloc(size);
	strcpy(p, "be carefull with electrical memory !");
	mprotect(p - 4096 + size, 4096, PROT_READ);
	if ((r1 = ft_strlen(p)) != (r2 = strlen(p)))
		printf("\x1b[31m[KO:%d] ", ++i);
	else
		printf("\x1b[32m[OK:%d] ", ++i);

	s = "YOLO";
	if ((unsigned long)s & 0b111)
		s++;
	if ((r1 = ft_strlen(s)) != (r2 = strlen(s)))
		printf("\x1b[31m[KO:%d] ", ++i);
	else
		printf("\x1b[32m[OK:%d] ", ++i);

	size_t sz = 0xF00 * 16;
	str = malloc(sz + 1);
	memset(str, 'A', sz);
	str[size] = 0;
	if ((r1 = ft_strlen(str)) != (r2 = strlen(str)))
		printf("\x1b[31m[KO:%d] ", ++i);
	else
		printf("\x1b[32m[OK:%d] ", ++i);

	char *empty = "";
	if ((r1 = ft_strlen(empty)) != (r2 = strlen(empty)))
		printf("\x1b[31m[KO:%d] ", ++i);
	else
		printf("\x1b[32m[OK:%d] ", ++i);

	pid_t childPid;
	switch (childPid = fork())
	{
		case -1:
			printf("fork");
			break;
		case 0:
			printf("\n\t      ");
			printf("\x1b[36m[ft_strlen(NULL)] => \x1b[39m");
			break;
		default:
			nanosleep(&request, &remaining);
			ft_strlen(NULL);
			break;
	}
	return 0;
}
