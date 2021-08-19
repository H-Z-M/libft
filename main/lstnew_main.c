#include <stdio.h>
#include <string.h>
#include "../libft.h"

/*
* Allocates (with malloc(3)) and returns a new
* element.  The variable ’content’ is initialized
* with the value of the parameter ’content’.
* The variable ’next’ is initialized to NULL.
*/

int main()
{
	ft_lstnew(NULL);

	char	*data = "hello, i'm a data";
	t_list	*l = ft_lstnew(data);
	int diff[2];
	int i = 0;

	if (!strcmp(data, l->content))
		diff[i] = 1;;
	i++;
	free(l);
	l = NULL;

	l = ft_lstnew(NULL);
	if (!l->content)
		diff[i] = 1;;
	i++;
	free(l);
	l = NULL;

	char *c = "lstnew";
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
