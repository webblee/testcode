/* ʹ��ѡ������ */
# include <stdio.h>

void main()
{
	int i, j, min, temp;
	/* ����һ�����͵�һά���� */
	int array[10];
	/* �������� */
	printf("Please input ten integer: \n");
	for(i=0; i<10; i++)
	{
		printf("array[%d] = ", i);
		scanf("%d", &array[i]);
	}
	printf("The array is: ");
	for(i=0; i<10; i++)
		printf("%d ", array[i]);
	printf("\n");
	/* ���� */
	for(i=0; i<9; i++)
	{
		min = i;
		for(j=i; j<10; j++)
			if(array[min]>array[j]) min = j;
		temp = array[i];
		array[i] = array[min];
		array[min] = temp;
	}
	/* ��� */
	printf("\nThe result: \n");
	for(i=0; i<10; i++)
		printf("%d ", array[i]);
	printf("\n");
}