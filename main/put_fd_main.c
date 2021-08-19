#include <stddef.h>
#include <stdio.h>
#include "../libft.h"
#include <fcntl.h>
#include <sys/_types/_off_t.h>
#include <sys/fcntl.h>
#include <sys/stat.h>
#include <string.h>
#include <limits.h>
#include <time.h>
#include <errno.h>

#ifndef PUTCHAR_FD
#define PUTCHAR_FD 0
#endif

void ft_remove(const char *path)
{
	int err = remove(path);
	if (err)
	{
		printf("remove error => %s\n", path);
		printf("errno        => %d\n", errno);
	}
}

void putchar_fd(void)
{
	const char *dirname = "put_dir";
	int err = mkdir(dirname, S_IRWXU);
	if (err)
	{
		printf("mkdir error\n");
		printf("errno => %d\n", errno);
		return ;
	}
	const char *actual = "put_dir/putchar_fd.txt";
	const char *expected = "put_dir/expected_putchar.txt";
	int fd = open(actual, O_RDWR | O_CREAT, S_IRWXU);
	int ex = open(expected, O_RDWR | O_CREAT, S_IRWXU);
	if (fd == -1 || ex == -1)
		printf("open error\n");
	char	buff[200];
	char	buff2[200];
	for (int i = 0; i < 128; i++) {
		ft_putchar_fd(i, fd);
		ft_putchar_fd(i, ex);
		buff2[i] = i;
	}
	off_t offset = lseek(fd, 0, SEEK_SET);
	ssize_t cnt = read(fd, buff, 128);
	if (cnt <= 0 || offset == -1)
	{
		if (offset)
		{
			printf("\x1b[37mlseek error ");
			return ;
		}
		printf("\x1b[37mread error ");
		printf(": cnt => %zu\n",cnt);
	}

	char *c = "putchar_fd";
	printf("\x1b[39m%-14s", c);
	int f = 1;
	for (int i = 0; i < 128; i++){
		if (buff[i] != buff2[i]) {
			printf("\x1b[31m[KO:1] ");
			printf("diff => %d\n", i);
			f = 0;
			break ;
		}
	}
	if (f)
		printf("\x1b[32m[OK:1]\n");
	close(fd);
	close(ex);
	ft_remove(actual);
	ft_remove(expected);
	ft_remove(dirname);
}

void putstr_fd_internal(char *s, int n)
{
	char *str = malloc(0xFF);
	int i;
	for (i = 0; s[i]; i++)
		str[i] = s[i];
	size_t size = i;
	const char *dirname = "put_dir";
	int err = mkdir(dirname, S_IRWXU);
	if (err)
	{
		printf("mkdir error\n");
		printf("errno => %d\n", errno);
		return ;
	}
	const char *actual = "put_dir/putstr_fd.txt";
	int fd = open(actual, O_RDWR | O_CREAT, S_IRWXU);
	if (fd == -1)
		printf("open error\n");

	ft_putstr_fd(str, fd);

	off_t offset = lseek(fd, 0, SEEK_SET);
	char *buff = malloc(0xFF);
	ssize_t cnt = read(fd, buff, size);
	if (cnt <= 0 || offset == -1)
	{
		if (offset)
		{
			printf("\x1b[37mlseek error ");
			return ;
		}
		printf("\x1b[37mread error ");
		printf(": cnt => %zu\n",cnt);
	}
	if (n == 1)
	{
		char *c = "putstr_fd";
		printf("\x1b[39m%-14s", c);
	}
	if (strcmp(buff, str))
		printf("\x1b[31m[KO:%d] ", n);
	else
		printf("\x1b[32m[OK:%d] ", n);

	free(str);
	free(buff);
	close(fd);
	ft_remove(actual);
	ft_remove(dirname);
}

void putendl_fd_internal(char *s, int n)
{
	char *str = malloc(0xFF);
	int i;
	for (i = 0; s[i]; i++)
		str[i] = s[i];
	size_t size = i;
	const char *dirname = "put_dir";
	int err = mkdir(dirname, S_IRWXU);
	if (err)
	{
		printf("mkdir error\n");
		printf("errno => %d\n", errno);
		return ;
	}
	const char *actual = "put_dir/putendl_fd.txt";
	int fd = open(actual, O_RDWR | O_CREAT, S_IRWXU);
	if (fd == -1)
		printf("open error\n");

	ft_putstr_fd(str, fd);

	off_t offset = lseek(fd, 0, SEEK_SET);
	char *buff = malloc(0xFF);
	ssize_t cnt = read(fd, buff, size);
	if (cnt <= 0 || offset == -1)
	{
		if (offset)
		{
			printf("\x1b[37mlseek error ");
			return ;
		}
		printf("\x1b[37mread error ");
		printf(": cnt => %zu\n",cnt);
	}
	if (n == 1)
	{
		char *c = "putendl_fd";
		printf("\x1b[39m%-14s", c);
	}
	if (strcmp(buff, str))
		printf("\x1b[31m[KO:%d] ", n);
	else
		printf("\x1b[32m[OK:%d] ", n);

	free(str);
	free(buff);
	close(fd);
	ft_remove(actual);
	ft_remove(dirname);
}

void putnbr_fd_internal(int nbr,int n)
{
	int i = 1;
	if (nbr < 0)
		i++;
	for (int tmp = nbr; tmp; i++)
		tmp /= 10;
	size_t size = i;
	const char *dirname = "put_dir";
	int err = mkdir(dirname, S_IRWXU);
	if (err)
	{
		printf("mkdir error\n");
		printf("errno => %d\n", errno);
		return ;
	}
	const char *actual = "put_dir/putnbr_fd.txt";
	int fd = open(actual, O_RDWR | O_CREAT, S_IRWXU);
	if (fd == -1)
		printf("open error\n");

	ft_putnbr_fd(nbr, fd);

	off_t offset = lseek(fd, 0, SEEK_SET);
	char *buff = malloc(0xFF);
	ssize_t cnt = read(fd, buff, size);
	if (cnt <= 0 || offset == -1)
	{
		if (offset)
		{
			printf("\x1b[37mlseek error ");
			return ;
		}
		printf("\x1b[37mread error ");
		printf(": cnt => %zu\n",cnt);
	}
	if (n == 1)
	{
		char *c = "putnbr_fd";
		printf("\x1b[39m%-14s", c);
	}
	char *str = malloc(0xFF);
	sprintf(str, "%d", nbr);
	/* printf("str    |%s|\n",str); */
	/* printf("buff   |%s|\n",buff); */
	if (strcmp(buff, str))
		printf("\x1b[31m[KO:%d] ", n);
	else
		printf("\x1b[32m[OK:%d] ", n);

	free(str);
	free(buff);
	close(fd);
	ft_remove(actual);
	ft_remove(dirname);
}

void putstr_fd(void)
{
	char *str = "Outputs the string ’s’ to the given filedescriptor.";
	putstr_fd_internal(str, 1);
	str = "string \x01 of \x63 non \x0a ascii \x12 chars\x1d";
	putstr_fd_internal(str, 2);
	wchar_t	*buff1 = L"よくやった";
	putstr_fd_internal((char*)buff1, 3);
	/* putstr_fd_internal(NULL, 4); */
	printf("\n");
}

void putendl_fd(void)
{
	char *str = "Outputs the string ’s’ to the given filedescriptor.";
	putendl_fd_internal(str, 1);
	str = "string \x01 of \x63 non \x0a ascii \x12 chars\x1d";
	putendl_fd_internal(str, 2);
	wchar_t	*buff1 = L"よくやった";
	putendl_fd_internal((char*)buff1, 3);
	/* putendl_fd_internal(NULL, 4); */
	printf("\n");
}

void putnbr_fd(void)
{
	putnbr_fd_internal(10, 1);
	putnbr_fd_internal(INT_MAX, 2);
	putnbr_fd_internal(INT_MIN, 3);
	int nbr;
	for (int i = 4; i < 10; i++)
	{
		srand(clock());
		nbr = rand();
		putnbr_fd_internal(nbr, i);
	}
	printf("\n");
}

int main()
{
	/* if (PUTCHAR_FD) */
	putchar_fd();
	putstr_fd();
	putendl_fd();
	putnbr_fd();
}
