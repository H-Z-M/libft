#include "../libft.h"
#include <stdio.h>
#include <string.h>

/* Allocates (with malloc(3)) and returns a copy of/
* ’s1’ with the characters specified in ’set’ removed/
* from the beginning and the end of the string.
*/

#define TRIM_SET_PLACEHOLDER " \n\t"

void str_cmp(char *result, char *expected, int n)
{
	if (!(strcmp(result, expected)))
		printf("\x1b[32m[OK:%d] ", n);
	else
		printf("\x1b[31m[KO:%d] ", n);
}

int main()
{
	char *c = "strtrim";
	printf("\x1b[39m%-14s", c);
	int i = 0;

	char *s1 = "   \t  \n\n \t\t  \n\n\nHello \t  Please\n Trim me !\n   \n \n \t\t\n  ";
	char *s2 = "Hello \t  Please\n Trim me !";
	char *ret = ft_strtrim(s1, " \n\t");
	str_cmp(ret, s2, ++i);

	s1 = "   \t  \n\n \t\t  \n\n\nHello \t  Please\n Trim me !";
	s2 = "Hello \t  Please\n Trim me !";
	ret = ft_strtrim(s1, " \n\t");
	str_cmp(ret, s2, ++i);

	s1 = "Hello \t  Please\n Trim me !";
	s2 = "Hello \t  Please\n Trim me !";
	ret = ft_strtrim(s1, " \n\t");
	str_cmp(ret, s2, ++i);

	s1 = "  \t \t \n   \n\n\n\t";
	s2 = "";
	ret = ft_strtrim(s1, " \n\t");
	str_cmp(ret, s2, ++i);

	s1 = "";
	s2 = "";
	ret = ft_strtrim(s1, " \n\t");
	str_cmp(ret, s2, ++i);

	s1 = "\t   \n\n\n  \n\n\t    Hello \t  Please\n Trim me !\t\t\t\n  \t\t\t\t  ";
	s2 = "Hello \t  Please\n Trim me !";
	ret = ft_strtrim(s1, " \n\t");
	str_cmp(ret, s2, ++i);

	s1 = "   \t  \n\n \t\t  \n\n\nHello \t  Please\n Trim me !\n   \n \n \t\t\n  ";
	s2 = "Hello \t  Please\n Trim me !";
	ret = ft_strtrim(s1, " \n\t");
	str_cmp(ret, s2, ++i);

	s1 = "   \t  \n\n \t\t  \n\n\nHello \t  Please\n Trim me !\n   \n \n \t\t\n  ";
	s2 = "Hello \t  Please\n Trim me !";
	ret = ft_strtrim(s1, " \n\t");
	str_cmp(ret, s2, ++i);

	ret = ft_strtrim(NULL, TRIM_SET_PLACEHOLDER);
	if (!ret)
		printf("\x1b[32m[OK:%d] ", ++i);
	else
		printf("\x1b[31m[KO:%d] ", ++i);
	printf("\n");
}
