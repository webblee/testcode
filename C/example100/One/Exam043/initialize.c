# include <stdio.h>
# include <string.h>

int search(char* p[], char* name);

/* ���ַ��͵�ָ�����鸳��ֵ */
char* names[] = {
	"Herb",
	"Rex",
	"Dennis",
	"John",
	NULL};    /* NULLָ���־�������ݵĽ��� */ 
 
void main()
{
	if(search(names, "Herb") != -1)
		printf("Herb is in list.\n");
  
    if(search(names, "Mary") == -1)
		printf("Mary not found.\n");
}
 
int search(char* p[], char* name)
{
	register int t;
   
	for(t = 0; p[t]; ++t)
		if(!strcmp(p[t], name)) return t;
    return -1;
}
