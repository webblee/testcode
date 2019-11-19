# include <stdio.h>

void avsco(float *psco, float *pave);
void avcour5(char *pcou, float *psco);
void fali2(char *pcou, int *pnum, float *psco, float *pave);
void excellence(char *pcou, int *pnum, float *psco, float *pave);

void main()
{
	/* ����num���ڴ��ÿλѧ����ѧ�� */
	int i, j, *pnum, num[4];

    /* ����aver���ڴ��ÿλѧ����ƽ���֣���ά����score���ڴ��ѧ���ɼ� */
	float score[4][5], aver[4], *psco, *pave;

	/* ����course���5�ſγ̵����� */
	char course[5][10], *pcou;  

	printf("�밴������5�Ź��ε����ƣ�\n");
	pcou = course[0];  /* ָ�����pcou�����������course���׵�ַ */
	                   /* ���׵�ַ��ʼ��ÿʮ���ֽڴ��һ���γ̵����� */
	for(i=0; i<5; i++)
		scanf("%s", pcou+10*i);  /* �Կո�Ϊ����������ſγ̵����� */    

	printf("�밴����ĸ�ʽ����4��ѧ����ѧ�ź͸��Ƴɼ���\n");
	printf("ѧ��");
	for(i=0; i<5; i++)
		printf(",%s", pcou+10*i);  /* ������ſγ̵����� */
	printf("\n");
	psco = &score[0][0];  /* ָ��pscoָ������score�еĵ�һ��Ԫ�� */
	                      /* ��ָ���һ��ѧ����һ�ſγ̵ĳɼ� */
	pnum = &num[0];
	for(i=0; i<4; i++)
	{
		scanf("%d", pnum+i);  /* ����ѧ�� */
		for(j=0; j<5; j++)
			scanf(",%f", psco+5*i+j);  /* �Զ���Ϊ�������ѧ���ɼ� */
	}

	pave = &aver[0];  /* ������aver���׵�ַ����ָ��pave */
	printf("\n");  /* ���� */

	avsco(psco, pave);
	avcour5(pcou, psco);
	printf("\n");  /* ���� */

	fali2(pcou, pnum, psco, pave);
	printf("\n");  /* ���� */

	excellence(pcou, pnum, psco, pave);
}

void avsco(float *psco, float *pave)  /* ��ÿ��ѧ����ƽ���ɼ� */
{
	int i, j;
	float sum, average;
	for(i=0; i<4; i++)  /* i����ѧ������ţ���ʾ��i��ѧ�� */
	{
		sum = 0.0;
		for(j=0; j<5; j++)  /* j����γ̵���ţ���ʾ��j�ſγ� */
			sum = sum + (*(psco+5*i+j));  /* �ۼ�ÿ��ѧ���ĸ��Ƴɼ� */
		average = sum/5;  /* �����i��ѧ��ƽ���ɼ� */
		*(pave+i) = average;
	}
}

void avcour5(char *pcou, float *psco)  /* ������ſγ̵�ƽ���ɼ� */
{
	int i;
	float sum, average5;
	sum = 0.0;
	for(i=0; i<4; i++)
		sum = sum + (*(psco+5*i+4));  /* �ۼ�ÿ��ѧ�������ſεĵ÷� */
	average5 = sum/4;    /* ��������ſγ̵�ƽ���ɼ� */
	printf("��5�ſγ�%s��ƽ���ɼ�Ϊ%5.2f.\n", pcou, average5);
}

void fali2(char *pcou, int *pnum, float *psco, float *pave)
{
	int i, j, k, label;
	printf("      =====�������Ͽγ̲������ѧ��=====     \n");
	printf("  ѧ��  ");
	for(i=0; i<5; i++)
		printf(" %-8s", pcou+10*i);  /* ����γ����� */
	printf("  ƽ����\n");
	for(i=0; i<4; i++)
	{
		label = 0;
		for(j=0; j<5; j++)
			if(*(psco+5*i+j) < 60.0)
				label++;  /* �����i��ѧ��������γ̵����� */
		if(label >= 2)
		{
			printf("%-8d", *(pnum+i));  /* ���ѧ�� */
			for(k=0; k<5; k++)
				printf("  %-8.2f", *(psco+5*i+k));  /* �����������ѧ���ĸ��Ƴɼ� */
			printf("  %-8.2f\n", *(pave+i));  /* �����������ѧ����ƽ���� */
		}
	}
}

/* ����ṹ����һ���Ӻ���fali2���� */
void excellence(char *pcou, int *pnum, float *psco, float *pave)    
{
	int i, j, k, label;
	printf("      =====�ɼ�����ѧ��=====\n");
	printf("  ѧ��  ");
	for(i=0; i<5; i++)
		printf("  %-8s", pcou+10*i);
	printf("  ƽ����\n");
	for(i=0; i<4; i++)
	{
		label = 0;
		for(j=0; j<5; j++)
			if(*(psco+5*i+j) >= 85.0)
				label++;
		if((label>=5)||(*(pnum+i)>=90))
		{
			printf("%-8d", *(pnum+i));
			for(k=0; k<5; k++)
				printf("  %-8.2f", *(psco+5*i+k));
			printf("  %-8.2f\n", *(pave+i));
		}
	}
}
