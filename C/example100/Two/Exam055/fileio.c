# include <stdio.h>
# include <stdlib.h>

void main()
{
	/* ����һ���ļ�ָ��fp */
	FILE *fp;
	char ch, filename[10];

	printf("Please input the name of file: ");
	scanf("%s", filename);  /* �����ַ�������������filename */

	/* �Զ���ʹ�÷�ʽ���ļ�filename */
	if((fp=fopen(filename, "r")) == NULL)
	{
		printf("Cannot open the file.\n");
		exit(0);  /* ������������ */
	}

	/* �ر��ļ� */
	fclose(fp);
}