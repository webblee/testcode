# include <stdio.h>
# include <io.h>
# include <stdlib.h>

void main()
{
	FILE *fp;
	char str[80];
	int i;

	if((fp=fopen("test", "w"))==NULL)
	{
		printf("���ܴ��ļ�.\n");
		exit(0);
	}

	printf("Please enter a string and a number: \n");
	fscanf(stdin, "%s %d", str, &i);  /* ����stdin��ʾ�Ӽ��̶��� */
	fprintf(fp, "%s %d", str, i);
	fclose(fp);

	if((fp=fopen("test", "r"))==NULL)
	{
		printf("���ܴ��ļ�.\n");
		exit(0);
	}

	fscanf(fp, "%s %d", str, &i);
	fprintf(stdout, "%s %d\n", str, i);  /* ����stdout��ʾд����Ļ */
	fclose(fp);
}