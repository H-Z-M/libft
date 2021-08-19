#include <stdio.h>
#include <string.h>
#include "../libft.h"

#ifndef LSTADD_FRONT_P
#define LSTADD_FRONT_P 0
#endif
/*
* Adds the element ’new’ at the beginning of the list.
*/

int main()
{
	char	*data = "hello, i'm a data";
	int diff[2];
	int i = 0;

	t_list	*l = ft_lstnew(data);
	t_list	*n = ft_lstnew("ok");

	ft_lstadd_front(&n, NULL);
	ft_lstadd_front(NULL, n);
	ft_lstadd_front(NULL, NULL);

	ft_lstadd_front(&l, n);
	if (LSTADD_FRONT_P)
	{
		printf("l->next->content       => %s\n", (char *)l->next->content);
		printf("l->content             => %s\n", (char *)l->content);
	}
	if (l == n && !strcmp(l->content, "ok"))
		diff[i] = 1;;
	i++;

	n = ft_lstnew("FRONT");
	ft_lstadd_front(&l, n);
	if (LSTADD_FRONT_P)
	{
		printf("l->next->next->content => %s\n", (char *)l->next->next->content);
		printf("l->next->content       => %s\n", (char *)l->next->content);
		printf("l->content             => %s\n", (char *)l->content);
	}
	if (l == n && !strcmp(l->content, "FRONT"))
		diff[i] = 1;
	i++;
	free(l->next);
	free(l);

	char *c = "lstadd_front";
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
