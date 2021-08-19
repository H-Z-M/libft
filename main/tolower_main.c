#include <stdio.h>
#include <ctype.h>
#include "../libft.h"

int main()
{
	char *c = "tolower";
	printf("\x1b[39m%-14s", c);
	int i;

	i = -100;
	while (i < 530)
	{
		if (ft_tolower(i) != tolower(i))
		{
			printf("\x1b[31m[KO:%d]\n", 1);
			return 0;
		}
		i++;
	}
	printf("\x1b[32m[OK:%d]\n", 1);
}
