#include "../libft.h"
#include <stddef.h>
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

int main()
{
	int i = 0;
	int sz = 11;
	int diff[sz];
	while (sz--)
		diff[sz] = 0;
	char	*src = "your memmove does not work with basic input\r\n";
	char	dst1[0xF0];
	char	dst2[0xF0];
	int		size = strlen(src);

	memmove(dst1, src, size);
	ft_memmove(dst2, src, size);
	if (!memcmp(dst1, dst2, size))
		diff[i] = 1;
	i++;

	char	sr[] = "J'ai fait une copie.";
	char	buff1[22];
	char	buff2[22];
	char	*r1 = memmove(buff1, sr, 21);
	char	*r2 = ft_memmove(buff2, sr, 21);
	if (!memcmp(r1, r2, 21))
		diff[i] = 1;
	i++;

	r1 = memmove("", src, 0);
	r2 = ft_memmove("", src, 0);
	if (!memcmp(r1, r2, 0))
		diff[i] = 1;
	i++;

	char	*s = "thi\xffs i\xfas \0a g\xde\xadood \0uuuu\0s**\0 !\r\n";
	size = 33;
	char	d1[0xF0];
	char	d2[0xF0];

	memmove(d1, s, size);
	ft_memmove(d2, s, size);
	if (!memcmp(d1, d2, size))
		diff[i] = 1;
	i++;

	unsigned long	ul = 0xdeadbeef;
	size = sizeof(ul);
	unsigned long	t1;
	unsigned long	t2;

	memmove(&t1, &ul, size);
	ft_memmove(&t2, &ul, size);
	if (!memcmp(&t1, &t2, size))
		diff[i] = 1;
	i++;

	/* printf("your memmove does not support the overlap (test 1)"); */
	char	o1[0xF0];
	char	o2[0xF0];
	char	*data = "thiß ß\xde\xad\xbe\xeftriñg will be øvérlapéd !\r\n";
	size = 0xF0 - 0xF;

	memset(o1, 'A', sizeof(o1));
	memset(o2, 'A', sizeof(o2));

	memcpy(o1, data, strlen(data));
	memcpy(o2, data, strlen(data));
	memmove(o1 + 3, o1, size);
	ft_memmove(o2 + 3, o2, size);
	if (!memcmp(o1, o2, size))
		diff[i] = 1;
	i++;

	/* printf("your memmove does not support the overlap (test 2)"); */
	char	ov1[0xF0];
	char	ov2[0xF0];
	data = "thiß ß\xde\xad\xbe\xeftriñg will be øvérlapéd !\r\n";
	size = 0xF0 - 0xF;

	memset(ov1, 'A', sizeof(ov1));
	memset(ov2, 'A', sizeof(ov2));

	memcpy(ov1, data, strlen(data));
	memcpy(ov2, data, strlen(data));
	memmove(ov1, ov1 + 3, size);
	ft_memmove(ov2, ov2 + 3, size);
	if (!memcmp(ov1, ov2, size))
		diff[i] = 1;
	i++;

	size = 128 * 1024 * 1024;
	char	*dst = (char *)malloc(sizeof(char) * size);
	char	*sc = (char *)malloc(sizeof(char) * size);
	char	*dt = (char *)malloc(sizeof(char) * size);

	memset(dt, 'A', size);
	if (!dst)
		exit(0);
	char *A = ft_memmove(dst, dt, size);
	char *B = memmove(sc, dt, size);
	if (!memcmp(A, B, size))
		diff[i] = 1;
	i++;

	size = 10;
	char	*dsds = electric_alloc(size);
	char	*dtdt = electric_alloc(size);
	memset(dtdt, 'A', size);
	mprotect(dtdt - 4096 + size, 4096, PROT_WRITE);
	mprotect(dtdt - 4096 + size, 4096, PROT_READ);
	ft_memmove(dsds, dtdt, size);
	dsds = electric_alloc_rev(size);
	dtdt = electric_alloc_rev(size);
	memset(dtdt, 'A', size);
	int err = mprotect(dsds- size, 4096, PROT_WRITE);
	int err2 = mprotect(dtdt - size, 4096, PROT_READ);
	if (err || err2)
	{
		printf("mprotect\n");
		return 0;
	}
	else
	{
		ft_memmove(dsds, dtdt, size);
		diff[i] = 1;
	}
	i++;

#define		STRING_1	"J'ai fait une copie!\0 ...\r\n"
#define		STRING_2	"there is no stars in the sky"
#define		STRING_3	"test basic !"
#define		STRING_4	"phrase differente pour le test"
	char	data1[] = STRING_1;
	char	data2[] = STRING_1;
	size = strlen(STRING_1);

	memmove(data1, data1, size);
	ft_memmove(data2, data2, size);
	if (!memcmp(data1, data2, size))
		diff[i] = 1;
	i++;

	char	*cc = STRING_1;
	char	buff[0xF0];

	char *ret = ft_memmove(buff, cc, 100);
	if (ret == NULL) {
		printf("your memmove use malloc ? why ?\n");
		return 0;
	}
	else
		diff[i] = 1;
	i++;

	char *c = "memmove";
	printf("\x1b[39m%-14s", c);
	i = 0;
	while (i < 11)
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

	/* ft_memmove("", "segfaulter tu dois", 17); */
	/* memmove("", "segfaulter tu dois", 17); */
	/* ft_memmove(NULL, "segfaulter tu dois", 17); */
	/* memmove(NULL, "segfaulter tu dois", 17); */
	/* ft_memmove("            ", NULL, 17); */
	/* memmove("            ", NULL, 17); */
	return 0;


	/* char	b[0xF0]; */
	/* ft_memmove(NULL, b, 5); */
	/* ft_memmove(b, NULL, 5); */
	/* ft_memmove(NULL, NULL, 0); */
	/* ft_memmove(NULL, NULL, 5); */
    /*  */
	/* char m[] = "The memmove() function copies len bytes from string src to string dst. The two strings may overlap; the copy is always done in a non-destructive manner."; */
	/* char M[] = "The memmove() function copies len bytes from string src to string dst. The two strings may overlap; the copy is always done in a non-destructive manner."; */
	/* printf("m = %ld\n", (long)m); */
	/* printf("m-1 = %ld\n", (long)m-1); */
	/* printf("M = %ld\n", (long)M); */
	/* i = 0; */
	/* int o = 11; */
	/* while (o--) */
	/* { */
	/* 	#<{(| if (strcmp(ft_memmove(m, &m[i], i),memmove(m, &m[i], i))) |)}># */
	/* 	#<{(| { |)}># */
	/* 	#<{(| 	printf("DIFF\n"); |)}># */
	/* 	#<{(| 	return 0; |)}># */
	/* 	#<{(| } |)}># */
	/* 	#<{(| printf("ft_memmove => %s\n",(char *)ft_memmove(&M[i], m, i)); |)}># */
	/* 	#<{(| printf("   memmove => %s\n",(char *)memmove(&M[i], m, i)); |)}># */
	/* 	printf("ft_memmove => %s\n",(char *)ft_memcpy(m+1, m, i)); */
	/* 	printf("   memmove => %s\n",(char *)memcpy(m+1, m, i)); */
	/* 	#<{(| printf("ft_memmove => %s\n",(char *)ft_memmove(m+1, m, i)); |)}># */
	/* 	#<{(| printf("   memmove => %s\n",(char *)memmove(m+1, m, i)); |)}># */
	/* 	i += 8; */
	/* } */
	/* printf("NO DIFF\n"); */
	/* printf("\n"); */
	/* char *n = NULL; */
	/* char *pn = NULL; */
	/* i = 0; */
	/* while (i < (int)strlen(pn)) */
	/* { */
	/* 	printf("ft_memmove => %s\n",(char *)ft_memmove(n, pn, i)); */
	/* 	printf("   memmove => %s\n",(char *)memmove(n, pn, i)); */
	/* 	i += 1; */
	/* } */
}
