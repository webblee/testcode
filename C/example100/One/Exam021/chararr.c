# include <stdio.h>
/* �궨�� */
# define MAX 100
# define LEN 80

/* һ���ǳ��򵥵��ı��༭�� */
void main()
{
	char text[MAX][LEN];
	register int t, i, j;    /* ���������Ĵ������� */
	/* ���������ַ��� */
    for(t=0; t<MAX; t++)    
	{
		printf("%d: ", t);
		gets(text[t]);
		if(!text[t][0])
			break;  /* �����˳� */
	}
	
	/* ���У�����ַ�����ַ��� */
	for(i=0; i<t; i++)  
	{
		for(j=0; text[i][j]; j++)
			putchar(text[i][j]);
		putchar('\n');
	}
}
