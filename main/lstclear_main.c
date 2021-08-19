#include <stdio.h>
#include "../libft.h"
#include <string.h>

/*
* Deletes and frees the given element and every
* successor of that element, using the function ’del’ 
* and free(3).
* Finally, the pointer to the list must be set to NULL.
*/

void lstdelone_f(void *d) { free(d); }

int main()
{
	int diff[3];
	int i = 0;

	t_list	*l = ft_lstnew(strdup("cat"));
	l->next = ft_lstnew(strdup("foo"));
	ft_lstclear(&l, lstdelone_f);
	if (!l)
	{
		diff[i] = 1;
	}
	i++;

	l = ft_lstnew(strdup("cat"));
	l->next = ft_lstnew(strdup("foo"));
	ft_lstclear(&l, lstdelone_f);
	if (!l)
	{
		diff[i] = 1;
	}
	i++;

	void *heap = malloc(512*1024*1024);
	l = ft_lstnew(heap);
	l->next = ft_lstnew(strdup("foo"));
	ft_lstclear(&l, lstdelone_f);
	if (!l)
	{
		diff[i] = 1;
	}
	i++;

	i = 0;
	char *c = "lstclear";
	printf("\x1b[39m%-14s", c);
	while (i < 3)
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

	ft_lstclear(NULL, lstdelone_f);
	ft_lstclear(&l, NULL);
	ft_lstclear(NULL, NULL);
}
