# include <stdio.h>
# include <stdlib.h>
# include <ctype.h>

char *alpha = "abcdefghijklmnopqrstuvwxyz";

int comp(const void *ch, const void *s);

int main()
{
	char ch;
	char *p;

	printf("Enter a character: ");
	ch = getchar();
	ch = tolower(ch);    /* ����Ԫchת����Сд�ַ� */
	p = (char *)bsearch(&ch, alpha, 26, 1, comp);
	if(p)
		printf("%c is in alphabet\n", *p);
	else
		printf("is not in alphabet\n");

	return 0;
}

int comp(const void *ch, const void *s)
{
	return *(char *)ch -*(char *)s;
}