#include <stdio.h>
#include "../libft.h"
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>

void print(char *actual, char *expected)
{
	printf("actual   => %s\n", actual);
	printf("expected => %s\n", expected);
}

int main()
{
	int PF = 0;

	int sz = 10;
	int diff[sz];
	while (sz--)
		diff[sz] = 0;
	int i = 0;
	char *rn;
	srand(clock());
	for (int i = 0; i < 100; i++) {
		char n[15];
		int r = rand();
		if (i % 2 == 0)
			r = -r;
		sprintf(n, "%i", r);
		rn = ft_itoa(r);
		if (strcmp(rn, n)) {
			printf("RANDOM NUMBER FAILURE\n");
			print(rn, n);
			return 0;
		}
		if (PF && i % 11 == 0)
			print(rn, n);
	}
	diff[i] = 1;;
	i++;
	char *n = "\t\v\f\r\n \f-06050";
	int N = atoi(n);
	char expected[15];
	char *actual = ft_itoa(N);
	sprintf(expected, "%i", N);
	if (!strcmp(actual, expected))
		diff[i] = 1;;
	i++;
	if (PF)
		print(actual, expected);

	n = "\t\v\f\r\n \f- \f\t\n\r    06050";
	N = atoi(n);
	actual = ft_itoa(N);
	sprintf(expected, "%i", N);
	if (!strcmp(actual, expected))
		diff[i] = 1;;
	i++;
	if (PF)
		print(actual, expected);

	n = "\e06050";
	N = atoi(n);
	actual = ft_itoa(N);
	sprintf(expected, "%i", N);
	if (!strcmp(actual, expected))
		diff[i] = 1;;
	i++;
	if (PF)
		print(actual, expected);

	n = "-123";
	N = atoi(n);
	actual = ft_itoa(N);
	sprintf(expected, "%i", N);
	if (!strcmp(actual, expected))
		diff[i] = 1;;
	i++;
	if (PF)
		print(actual, expected);

	N = INT_MAX;
	actual = ft_itoa(N+1);
	sprintf(expected, "%i", N+1);
	if (!strcmp(actual, expected))
		diff[i] = 1;;
	i++;
	if (PF)
		print(actual, expected);

	N = INT_MIN;
	actual = ft_itoa(N);
	sprintf(expected, "%i", N);
	if (!strcmp(actual, expected))
		diff[i] = 1;;
	i++;
	if (PF)
		print(actual, expected);

	n = "+1234";
	N = atoi(n);
	actual = ft_itoa(N);
	sprintf(expected, "%i", N);
	if (!strcmp(actual, expected))
		diff[i] = 1;;
	i++;
	if (PF)
		print(actual, expected);

	char *c = "itoa";
	printf("\x1b[39m%-14s", c);
	i = 0;
	while (i < 8)
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
}
