#include <stdio.h>
#include "../libft.h"
#include <string.h>

int main()
{
	ft_lstsize(NULL);

	int diff[2];
	int i = 0;
	int actual;
	int expected;
	t_list *l;

	l = ft_lstnew(strdup("1"));
	l->next = ft_lstnew(strdup("2"));
	l->next->next = ft_lstnew(strdup("3"));
	expected = 3;
	actual = ft_lstsize(l);
	if (actual == expected)
		diff[i] = 1;;
	i++;
	free(l);

	t_list *u = NULL;
	expected = 0;
	actual = ft_lstsize(u);
	if (actual == expected)
		diff[i] = 1;;
	i++;
	free(u);

	char *c = "lstsize";
	printf("\x1b[39m%-14s", c);
	i = 0;
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
