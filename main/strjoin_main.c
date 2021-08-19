#include "../libft.h"
#include <stdio.h>
#include <string.h>

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
	char *c = "strjoin";
	printf("\x1b[39m%-14s", c);
	char	*s1 = "my favorite animal is";
	char	*s2 = " ";
	char	*s3 = "the cat";
	char	*res = ft_strjoin(ft_strjoin(s1, s2), s3);
	str_cmp(res, "my favorite animal is the cat", ++i);
	free(res);

	char	*t = ft_strjoin(s1, s2);
	char	*r = ft_strjoin(t, s3);
	str_cmp(r, "my favorite animal is the cat", ++i);
	free(t);
	free(r);

	s1 = "my favorite animal is ";
	s2 = s1 + 20;
	char	*ptr = ft_strjoin(s2, s1);
	str_cmp(ptr, "s my favorite animal is ", ++i);
	free(ptr);

	s1 = "where is my ";
	s2 = "malloc ???";
	char	*e = ft_strjoin(s2, s1);
	free(e);
	e = NULL;
	if (e == NULL)
		printf("\x1b[32m[OK:%d] ", ++i);
	else
		printf("\x1b[31m[KO:%d] ", ++i);

	s1 = "where is my ";
	s2 = "malloc ???";
	s3 = "where is my malloc ???";
	char	*result = ft_strjoin(s1, s2);
	str_cmp(result, s3, ++i);
	free(result);

	s1 = "where is my ";
	char	*s = ft_strjoin(NULL, s1);
	if (s == NULL)
		printf("\x1b[32m[OK:%d] ", ++i);
	else
		printf("\x1b[31m[KO:%d] ", ++i);

	s = ft_strjoin(s1, NULL);
	if (s == NULL)
		printf("\x1b[32m[OK:%d] ", ++i);
	else
		printf("\x1b[31m[KO:%d] ", ++i);

	printf("\n");
	return 0;
}
