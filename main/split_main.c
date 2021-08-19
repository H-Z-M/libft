#include "../libft.h"
#include <stdio.h>
#include <string.h>
#include <sys/mman.h>

void	split_cmp_array(char **expected, char **result, int n)
{
	for (; *expected; expected++, result++)
	{
		if (*result == NULL || strcmp(*expected, *result))
		{
			printf("\x1b[31m[KO:%d] ", n);
			return ;
		}
	}
	printf("\x1b[32m[OK:%d] ", n);
	return ;
}

int main(){
	int i = 0;
	char *c = "split";
	printf("\x1b[39m%-14s", c);
	char	*string = "      split       this for   me  !       ";
	char	**expected = (char*[6]){"split", "this", "for", "me", "!", NULL};
	char	**result = ft_split(string, ' ');
	split_cmp_array(expected, result, ++i);

	expected = (char*[1]){NULL};
	string = "                  ";
	result = ft_split(string, ' ');
	split_cmp_array(expected, result, ++i);

	expected = (char*[2]){"olol", NULL};
	char	*s = "                  olol";
	result = ft_split(s, ' ');
	split_cmp_array(expected, result, ++i);

	s = "olol                  ";
	result = ft_split(s, ' ');
	split_cmp_array(expected, result, ++i);

	expected = (char*[2]){NULL};
	s = "";
	result = ft_split(s, '\65');
	split_cmp_array(expected, result, ++i);

	s = "0 0 0 0 0 0 0 0 0";
	result = ft_split(s, ' ');
	split_cmp_array(expected, result, ++i);

	expected = (char*[6]){"split  ", "this", "for", "me", "!", NULL};
	s = "split  ||this|for|me|||||!|";
	result = ft_split(s, '|');
	split_cmp_array(expected, result, ++i);

	expected = ft_split(NULL, ' ');
	if (!expected)
		printf("\x1b[32m[OK:%d]\n", ++i);
	else
		printf("\x1b[31m[KO:%d]\n", ++i);
}
