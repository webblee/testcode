# include <stdio.h>
# include <stdlib.h>

# define NUM 10

int main()
{
	char *str[NUM];  /* ����һ���ַ��Ե�ָ������ */
	int t;

	/* Ϊ�����е�ÿ��ָ������ڴ� */
	for(t=0; t<NUM; t++)
	{
		if((str[t]=(char *)malloc(128))==NULL)
		{
			printf("Allocation Error.\n");
			exit(1);
		}
		/* �ڷ�����ڴ��д���ַ��� */
		printf("Enter string %d: ", t);
		gets(str[t]);
	}
	
	/* �ͷ��ڴ� */
	for(t=0; t<NUM; t++)
		free(str[t]);

	/* �����������з���ֵ���ʷ���0ֵ */
	return 0;
}