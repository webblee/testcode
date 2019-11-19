/* ѧ���ɼ�ͳ�� */
# include <stdio.h>
# define M 5
# define N 10

float score[N][M];
float a_stu[N], a_cor[M];

/* �����Ӻ��� */
void input_stu();
void avr_stu();
void avr_cor();
float highest(int *r, int *c);
float s_diff();

void main()    /* ������ */
{
	int i, j, r, c;
	float h;

	r = 0;
	c = 1;

	input_stu();    /* ���ú���input_stu,����ѧ�����Ź��εĳɼ� */    
	avr_stu();    /* ���ú���avr_stu,���ÿ��ѧ����ƽ���� */
	avr_cor();    /* ���ú���avr_cor,�ҳ�ѧ���ɼ��е���߷�*/

	printf("\n  ���   �γ�1   �γ�2   �γ�3   �γ�4   �γ�5   ƽ����");
	for(i=0; i<N; i++)
	{
		printf("\n  NO%2d", i+1);
		for(j=0; j<M; j++)
			printf("%8.2f", score[i][j]);
		printf("%8.2f", a_stu[i]);
	}

	printf("\n��ƽ��");
	for(j=0; j<M; j++)
		printf("%8.2f", a_cor[j]);

	h = highest(&r, &c);
	printf("\n\n��߷�%8.2f�� %d��ѧ���ĵ�%d�ſ�\n", h, r, c);
	printf("  ���� %8.2f\n", s_diff());
}

void input_stu()    /* ����ѧ���ĳɼ� */
{
	int i, j;

	for(i=0; i<N; i++)
	{
		printf("������ѧ��%2d��5���ɼ�:\n", i+1);
		for(j=0; j<M; j++)
			scanf("%f", &score[i][j]);
	}
}

void avr_stu()    /* ����ѧ����ƽ���� */
{
	int i, j;
	float s;

	for(i=0; i<N; i++)
	{
		s = 0;
		for(j=0; j<M; j++)
			s = s + score[i][j];
		a_stu[i] = s/M;
	}
}

void avr_cor()    /* ����γ̵�ƽ���� */
{
	int i, j;
	float s;

	for(j=0; j<M ;j++)
	{
		s = 0;
		for(i=0; i<N; i++)
			s = s + score[i][j];
		a_cor[j] = s/(float)N;
	}
}

float highest(int *r, int *c)    /* ����߷� */
{
	float high;
	int i, j;

	high = score[0][0];
	for(i=0; i<N; i++)
		for(j=0; j<M; j++)
			if(score[i][j]>high)
			{
				high = score[i][j];
				*r = i + 1;
				*c = j + 1;
			}
	return high;
}

float s_diff()    /* �󷽲� */
{
	int i;
	float sumx, sumxn;

	sumx = 0.0;
	sumxn = 0.0;

	for(i=0; i<N; i++)
	{
		sumx = sumx + a_stu[i]*a_stu[i];
		sumxn = sumxn + a_stu[i];
	}
	return (sumx/N-(sumxn/N)*(sumxn/N));
}