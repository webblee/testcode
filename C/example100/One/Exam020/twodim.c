# include <stdio.h>

void main()
{
	int array[16][16];
	int i, j, k, m, n;
	
	/* ������ʼ�� */
	m = 1;
	while(m == 1)
	{
		printf("������n(0<n<=15)��n������)\n");
		scanf("%d", &n);
		/* �ж�n�Ƿ��Ǵ���0С�ڵ���15������ */
		if((n!=0) && (n<=15) && (n%2!=0))
		{
			printf("��������� %d\n", n);
			m = 0;
		}
	}
	/* ���鸳��ֵΪ0 */
	for(i=1; i<=n; i++)
		for(j=1; j<=n; j++)
			array[i][j] = 0;

	/* ����ħ���� */
	j = n/2 + 1;
	array[1][j] = 1;
	for(k=2; k<=n*n; k++)
	{
		i = i - 1;
		j = j + 1;
		if((i<1) && (j>n))
		{
			i = i + 2;
			j = j - 1;
		}
		else
		{
			if(i < 1)
				i = n;
			if(j > n)
				j = 1;
		}
		if(array[i][j] == 0)
			array[i][j] = k;
		else
		{
			i = i + 2;
			j = j - 1;
			array[i][j] = k;
		}
	}

	/* ���ħ���� */
	for(i=1; i<=n; i++)
	{
		for(j=1; j<=n; j++)
			printf("%5d", array[i][j]);
		printf("\n");
	}
}