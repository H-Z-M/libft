#include <stdio.h>
#include "../libft.h"
#include <string.h>

/* Returns the last element of the list. */

int main()
{
	int diff[2];
	int i = 0;
	t_list *actual;
	t_list *expected;
	t_list *l;

	ft_lstlast(NULL);

	l = ft_lstnew(strdup("1"));
	l->next = ft_lstnew(strdup("2"));
	l->next->next = ft_lstnew(strdup("333333"));
	expected = l->next->next;
	actual = ft_lstlast(l);
	/* printf("actual   => %s\n", (char *)actual->content); */
	/* printf("expected => %s\n", (char *)expected->content); */
	if (actual == expected)
		diff[i] = 1;;
	i++;
	free(l);

	t_list *u = NULL;
	expected = NULL;
	actual = ft_lstlast(u);
	/* printf("actual   => %s\n", (char *)actual); */
	/* printf("expected => %s\n", (char *)expected); */
	if (actual == expected)
		diff[i] = 1;;
	i++;
	free(u);

	char *c = "lstlast";
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
	printf("\x1b[39m\n");
}
