#include <stdio.h>
#include <string.h>
#include "../libft.h"

#ifndef LSTADD_BACK_P
#define LSTADD_BACK_P 0
#endif
/*
* Adds the element ’new’ at the end of the list.
*/
int main()
{
	char	*data = "hello, i'm a data";
	int diff[2];
	int i = 0;

	t_list	*l = ft_lstnew(data);
	t_list	*n = ft_lstnew(strdup("ok"));

	ft_lstadd_back(&n, NULL);
	ft_lstadd_back(NULL, n);
	ft_lstadd_back(NULL, NULL);

	ft_lstadd_back(&l, n);
	if (LSTADD_BACK_P)
	{
		printf("l->next->content => %s\n", (char *)l->next->content);
		printf("l->content       => %s\n", (char *)l->content);
	}
	if (l->next == n && !strcmp(l->next->content, "ok"))
		diff[i] = 1;;
	i++;

	n = ft_lstnew(strdup("foo"));
	ft_lstadd_back(&l, n);
	if (LSTADD_BACK_P)
	{
		printf("l->next->content => %s\n", (char *)l->next->next->content);
		printf("l->next->content => %s\n", (char *)l->next->content);
		printf("l->content       => %s\n", (char *)l->content);
	}
	if (l->next->next == n && !strcmp(l->next->next->content, "foo"))
		diff[i] = 1;
	i++;
	free(l->next);
	free(l);

	char *c = "lstadd_back";
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
