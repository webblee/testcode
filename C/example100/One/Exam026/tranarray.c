/* �����ת�� */
# include <stdio.h>
# define N 3

/* ת�ú������� */
void convert(int element[N][N]);

void main()
{
	/* ����һ����ά���� */
	int array[N][N];

	int i, j;
	/* ���������ֵ */
	printf("��������Ԫ�أ�\n");
	for(i=0; i<N; i++)
		for(j=0; j<N; j++)
			scanf("%d", &array[i][j]);
	printf("\n�����ǣ�\n");
	for(i=0; i<N; i++)
	{
		for(j=0; j<N; j++)
			printf("%5d", array[i][j]);
		printf("\n");
	}

	/* ���������ת�ù��� */
	convert(array);
	printf("ת�������ǣ�\n");
	for(i=0; i<N; i++)
	{
		for(j=0; j<N; j++)
			printf("%5d", array[i][j]);
		printf("\n");
	}
}

/* ת�ú������� */
void convert(int element[N][N])
{
	int i, j, t;
	for(i=0; i<N; i++)
		for(j=i+1; j<N; j++)
		{
			t = element[i][j];
			element[i][j] = element[j][i];
			element[j][i] = t;
		}
}

