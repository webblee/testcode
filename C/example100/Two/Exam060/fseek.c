# include <stdio.h>
# include <stdlib.h>

void main(int argc, char *argv[])
{
	FILE *fp;

	if(argc!=3)
	{
		printf("ȱ���ֽ�λ�ã��޷����в�����\n");
		exit(0);
	}

	if((fp=fopen(argv[1], "rb"))==NULL)
	{
		printf("�޷����ļ���\n");
		exit(0);
	}

	if(fseek(fp, atol(argv[2]), 0))
	{
		printf("Ѱ�ҳ��ִ���\n");
		exit(0);
	}

	printf("��%ld�����ַ���%c��\n", atol(argv[2]), getc(fp));
	fclose(fp);
}