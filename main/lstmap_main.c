#include <stdio.h>
#include "../libft.h"
#include <string.h>

void *lstmap_f(void *content)
{
	(void)content;
	return ("OK !");
}

void lstdelone_f(void *d) { free(d); }

int main()
{
	int diff[7];
	int i = 0;
	t_list	*ret;
	t_list	*l = ft_lstnew(strdup(" 1 2 3 "));

	l->next = ft_lstnew(strdup("ss"));
	l->next->next = ft_lstnew(strdup("-_-"));
	ret = ft_lstmap(l, lstmap_f, lstdelone_f);
	if (!strcmp(ret->content, "OK !"))
		diff[i] = 1;
	i++;
	if (!strcmp(ret->next->content, "OK !"))
		diff[i] = 1;
	i++;
	if (!strcmp(ret->next->next->content, "OK !"))
		diff[i] = 1;
	i++;
	if (!strcmp(l->content, " 1 2 3 "))
		diff[i] = 1;
	i++;
	if (!strcmp(l->next->content, "ss"))
		diff[i] = 1;
	i++;
	if (!strcmp(l->next->next->content, "-_-"))
		diff[i] = 1;
	i++;

	ft_lstmap(l, lstmap_f, NULL);
	ft_lstmap(NULL, lstmap_f, lstdelone_f);
	ft_lstmap(NULL, NULL, lstdelone_f);
	ft_lstmap(l, NULL, NULL);

	i = 0;
	char *c = "lstmap";
	printf("\x1b[39m%-14s", c);
	while (i < 6)
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
