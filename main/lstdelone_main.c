#include <stdio.h>
#include "../libft.h"
#include <string.h>

/* Returns the last element of the list. */

void lstdelone_f(void *d) { free(d); }

int main()
{
	int diff[2];
	int i = 0;

	t_list	*l = ft_lstnew(malloc(100000000));

	ft_lstdelone(NULL, lstdelone_f);
	ft_lstdelone(l, NULL);
	ft_lstdelone(NULL, NULL);

	if (l)
	{
		ft_lstdelone(l, lstdelone_f);
		diff[i] = 1;
	}
	i++;
	l = ft_lstnew(strdup("1"));
	if (l)
	{
		/* printf("%s\n",(char *)l->content); */
		ft_lstdelone(l, lstdelone_f);
		diff[i] = 1;
	}
	i++;
	i = 0;
	char *c = "lstdelone";
	printf("\x1b[39m%-14s", c);
	while (i < 2)
	{
		if (diff[i])
		{
			printf("\x1b[32m[OK:%d] ", i+1);
		}
		else
		{
			printf("\x1b[31m[KO:%d] ", i+1);
		}
		i++;
	}
	printf("\n");
}
