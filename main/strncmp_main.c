#include "../libft.h"
#include <sys/mman.h>
#include <stdio.h>
#include <string.h>

/* strcmp() and strncmp() functions return an integer greater than, 
 * equal to, or less than 0, according as the string s1 is greater than,
 * equal to, or less than the string s2.  The comparison is done using 
 * unsigned characters, so that `\200' is greater than `\0'. */

#define		STRING_1	"the cake is a lie !\0I'm hidden lol\r\n"
#define		STRING_2	"there is no stars in the sky"
#define		STRING_3	"test basic !"
#define		STRING_4	"phrase differente pour le test"

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
	char *c = "strncmp";
	printf("\x1b[39m%-14s", c);
	int i = 0;
	char	*s1 = STRING_1;
	char	*s2 = STRING_2;
	size_t	size = strlen(STRING_1);
	int		i1 = strncmp(s1, s2, size);
	int		i2 = ft_strncmp(s1, s2, size);
	if (i1 == i2)
		printf("\x1b[32m[OK:%d] ", ++i);
	else
		printf("\x1b[31m[KO:%d] ", ++i);

	s1 = "omg1||||||||||||||||";
	s2 = "omg3";
	size = 4;
	i1 = strncmp(s1, s2, size);
	i2 = ft_strncmp(s1, s2, size);
	if (i1 == i2)
		printf("\x1b[32m[OK:%d] ", ++i);
	else
		printf("\x1b[31m[KO:%d] ", ++i);

	s1 = "";
	s2 = "";
	i1 = strncmp(s1, s2, 1);
	i2 = ft_strncmp(s1, s2, 1);
	if (i1 == i2)
		printf("\x1b[32m[OK:%d] ", ++i);
	else
		printf("\x1b[31m[KO:%d] ", ++i);

	s1 = "AAAAAAAAA1";
	s2 = "AAAAAAAAA2";
	i1 = strncmp(s1, s2, 3);
	i2 = ft_strncmp(s1, s2, 3);
	if (i1 == i2)
		printf("\x1b[32m[OK:%d] ", ++i);
	else
		printf("\x1b[31m[KO:%d] ", ++i);

	s1 = "AAAAAA";
	s2 = "";
	i1 = strncmp(s1, s2, 6);
	i2 = ft_strncmp(s1, s2, 6);
	if (i1 == i2)
		printf("\x1b[32m[OK:%d] ", ++i);
	else
		printf("\x1b[31m[KO:%d] ", ++i);

	s1 = "";
	s2 = "AAAAAA";
	i1 = strncmp(s1, s2, 6);
	i2 = ft_strncmp(s1, s2, 6);
	if (i1 == i2)
		printf("\x1b[32m[OK:%d] ", ++i);
	else
		printf("\x1b[31m[KO:%d] ", ++i);

	s1 = "\200";
	s2 = "\0";
	i1 = strncmp(s1, s2, 1);
	i2 = ft_strncmp(s1, s2, 1);
	if (i1 == i2)
		printf("\x1b[32m[OK:%d] ", ++i);
	else
		printf("\x1b[31m[KO:%d] ", ++i);

	s1 = "omg1";
	s2 = "omg3                ";
	size = 100000;
	i1 = strncmp(s1, s2, size);
	i2 = ft_strncmp(s1, s2, size);
	if (i1 == i2)
		printf("\x1b[32m[OK:%d] ", ++i);
	else
		printf("\x1b[31m[KO:%d] ", ++i);

	s1 = "atoms\0\0\0\0";
	s2 = "atoms\0abc";
	size = 8;
	i1 = strncmp(s1, s2, size);
	i2 = ft_strncmp(s1, s2, size);
	if (i1 == i2)
		printf("\x1b[32m[OK:%d] ", ++i);
	else
		printf("\x1b[31m[KO:%d] ", ++i);

	s1 = "\x12\xff\x65\x12\xbd\xde\xad";
	s2 = "\x12\x02";
	size = 6;
	i1 = strncmp(s1, s2, size);
	i2 = ft_strncmp(s1, s2, size);
	if (i1 == i2)
		printf("\x1b[32m[OK:%d] ", ++i);
	else
		printf("\x1b[31m[KO:%d] ", ++i);

	char	*big = "abcdef";
	char	*little = "abcdefghijklmnop";
	size = 6;
	i1 = strncmp(big, little, size);
	i2 = ft_strncmp(big, little, size);
	if (i1 == i2)
		printf("\x1b[32m[OK:%d] ", ++i);
	else
		printf("\x1b[31m[KO:%d] ", ++i);

	size = 10;
	char	*str1 = electric_alloc(size);
	char	*str2 = electric_alloc(size);
	strcpy(str1, "{'-_-'} !");
	strcpy(str2, "{'-_-'} !");
	mprotect(str1 - 4096 + size, 4096, PROT_READ);
	mprotect(str2 - 4096 + size, 4096, PROT_READ);
	i1 = strncmp(str1, str2, size);
	i2 = ft_strncmp(str1, str2, size);
	if (i1 == i2)
		printf("\x1b[32m[OK:%d] ", ++i);
	else
		printf("\x1b[31m[KO:%d] ", ++i);

	size = 255;
	s1 = malloc(size + 1);
	s2 = malloc(size + 1);
	memset(s1, 'A', size);
	memset(s2, 'A', size);
	s1[size] = s2[size] = 0;
	i1 = strncmp(str1, str2, size);
	i2 = ft_strncmp(str1, str2, size);
	if (i1 == i2)
		printf("\x1b[32m[OK:%d] ", ++i);
	else
		printf("\x1b[31m[KO:%d] ", ++i);
}
