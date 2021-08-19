#include <stdio.h>
#include "../libft.h"
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <time.h>

#define true 1
#define false 0

void diff(int b)
{
	static int i;
	i++;
	if (b) printf("\x1b[32m[OK:%d] ", i);
	else   printf("\x1b[31m[KO:%d] ", i);
}

void print(int actual, int expected)
{
	printf("actual   => %d  ", actual);
	printf("expected => %d\n", expected);
}
void atoi_main()
{
	char *c = "atoi";
	printf("\x1b[39m%-14s", c);
	int		i1;
	int		i2;
	for (int i = 0; i < 64; i++) {
		char n[15];
		sprintf(n, "%i", rand());
		i1 = atoi(n);
		i2 = ft_atoi(n);
		if (i1 != i2) {
			print(i1, i2);
			exit(EXIT_FAILURE);
		}
	}
	diff(true);
	char	M[40];  sprintf(M, "%i", INT_MAX);
	char	m[40];  sprintf(m, "%i", INT_MIN);
	char	lM[40]; sprintf(lM, "%li", LONG_MAX);
	char	lm[40]; sprintf(lm, "%li", LONG_MIN);
	char *arg[] = {"\t\v\f\r\n \f-06050", "\t\v\f\r\n \f- \f\t\n\r    06050", 
		"\e06050", "-123THERE IS A NYANCAT UNDER YOUR BED", M, m, lM, lm, 
		"99999999999999999999999999", "-99999999999999999999999999", "+1234", 
		"\t\v\f\r\n \f+\t\v\f\r\n \f1234", "+\t\v\f\r\n \f1234", NULL};
	for (int i = 0; arg[i]; i++){
		i1 = atoi(arg[i]);
		i2 = ft_atoi(arg[i]);
		diff(i1 == i2);
		if (i1 != i2) {
			print(i1, i2);
			exit(EXIT_FAILURE);
		}
	}
	printf("\n");
	exit(EXIT_SUCCESS);
	printf("SEGMENTATION FAULT\n");
	atoi(NULL);
	ft_atoi(NULL);
}

/* #define Atoi atoi_main() */
int main(){
	atoi_main();
	/* char s[] = "atoi_main()"; */
	/* if (!strcmp(argv[argc-1], "atoi")) */
	/* 	Atoi; */
}
