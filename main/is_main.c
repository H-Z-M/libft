#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "../libft.h"

int main()
{
	int		i;
	i = -1;
	int diff = 1;
	while (i < 530)
	{
		int actual = ft_isalnum(i);
		int expected = isalnum(i);
		if (actual != expected)
		{
			printf("actual %d  expected %d  i %d\n", actual, expected, i);
			diff = 0;
		}
		i++;
	}
	char *c = "isalnum";
	printf("\x1b[39m%-14s", c);
	if (diff)
		printf("\x1b[32m[OK:1]\n");
	else
		printf("\x1b[31m[KO:1]\n");
	diff = 1;

	i = -1;
	while (i < 530)
	{
		int actual = ft_isalpha(i);
		int expected = isalpha(i);
		if (actual != expected)
		{
			printf("actual %d  expected %d  i %d\n", actual, expected, i);
			diff = 0;
		}
		i++;
	}
	c = "isalpha";
	printf("\x1b[37m%-14s", c);
	if (diff)
		printf("\x1b[32m[OK:1]\n");
	else
		printf("\x1b[31m[KO:1]\n");
	diff = 1;

	i = -1;
	while (i < 530)
	{
		int actual = ft_isascii(i);
		int expected = isascii(i);
		if (actual != expected)
		{
			printf("actual %d  expected %d  i %d\n", actual, expected, i);
			diff = 0;
		}
		i++;
	}
	c = "isascii";
	printf("\x1b[37m%-14s", c);
	if (diff)
		printf("\x1b[32m[OK:1]\n");
	else
		printf("\x1b[31m[KO:1]\n");
	diff = 1;

	i = -1;
	while (i < 530)
	{
		int actual = ft_isdigit(i);
		int expected = isdigit(i);
		if (actual != expected)
		{
			printf("actual %d  expected %d  i %d\n", actual, expected, i);
			diff = 0;
		}
		i++;
	}
	c = "isdigit";
	printf("\x1b[37m%-14s", c);
	if (diff)
		printf("\x1b[32m[OK:1]\n");
	else
		printf("\x1b[31m[KO:1]\n");
	diff = 1;

	i = -1;
	while (i < 530)
	{
		int actual = ft_isprint(i);
		int expected = isprint(i);
		if (actual != expected)
		{
			printf("actual %d  expected %d  i %d\n", actual, expected, i);
			diff = 0;
		}
		i++;
	}
	c = "isprint";
	printf("\x1b[37m%-14s", c);
	if (diff)
		printf("\x1b[32m[OK:1]\n");
	else
		printf("\x1b[31m[KO:1]\n");

}
