#include <stdio.h>
#include "libft.h"

void lstdelone_f(void *d) { free(d); d = NULL;}
int main(void) {
	t_list *lst = malloc(sizeof(t_list));
	lst->content = malloc(256*1024);
	printf("%s\n",(char *)lst->content);
	ft_lstclear(&lst, lstdelone_f);
	printf("%s\n",(char *)lst->content);
	return 0;
}
