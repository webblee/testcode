# include <stdio.h>
# include <string.h>
# include <stdlib.h>

void main()
{
	FILE *fp;
	char str[100];
	int i;

	if((fp=fopen("file.txt", "w"))==NULL)
	{
		printf("�޷����ļ�\n");
		exit(0);
	}

	printf("������һ���ַ�����\n");
	gets(str);

	/* ���ַ����е�Сд�ַ�ת���ɴ�д�ַ���ֱ������"."Ϊֹ */
	for(i=0; str[i]!='.'; i++)
	{
		if(str[i]>='a' && str[i]<='z')
			str[i] = str[i] - 32;
		fputc(str[i], fp);  /* ��ת������ַ������ļ� */
	}
	fclose(fp);

	fp = fopen("file.txt", "r");
	for(i=0; str[i]!='.'; i++)
		str[i] = fgetc(fp);
	printf("%s\n", str);
	fclose(fp);
}