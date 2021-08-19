#include <stdio.h>
#include "../libft.h"
#include <string.h>

/*
* Iterates the list ’lst’ and applies the function
* ’f’ to the content of each element.
*/
void	lstiter_f(void *content)
{
	char *s = content;

	s[0] = 'O';
	s[1] = 'K';
}

int main()
{
	int diff[6];
	int i = 0;
	t_list	*l = ft_lstnew(strdup("KO !"));

	ft_lstiter(NULL, lstiter_f);
	ft_lstiter(l, NULL);
	ft_lstiter(NULL, NULL);

	l->next = ft_lstnew(strdup("KO !"));
	l->next->next = ft_lstnew(strdup("KO !"));
	ft_lstiter(l, lstiter_f);
	if (!strcmp(l->content, "OK !"))
		diff[i] = 1;
	i++;
	if (!strcmp(l->next->content, "OK !"))
		diff[i] = 1;
	i++;
	if (!strcmp(l->next->next->content, "OK !"))
		diff[i] = 1;
	i++;

	ft_lstiter(NULL, lstiter_f);



	i = 0;
	char *c = "lstiter";
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
}
