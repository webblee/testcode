# include <stdio.h>
# include <stdlib.h>
# include <string.h>

void main()
{
	char str[80];
	FILE *fp;  /* ����һ���ļ����͵�ָ�� */

	/* ��д�ķ�ʽ���ļ�test */
	if((fp=fopen("test.txt", "w"))==NULL)
	{
		printf("Cannot open file.\n");
		exit(0);
	}

	do{
		printf("Please enter a string: \n");
		gets(str);
		strcat(str, "\n");  /* ����һ������ */
		fputs(str, fp);
	} while(*str!='\n');

	/* ���ļ��ж����ַ���,����������ʾ���� */
	rewind(fp);  /* �����ļ�ָ�� */
	while(!feof(fp))
	{
		fgets(str, 79, fp);
		printf(str);
	}

	fclose(fp);
}
