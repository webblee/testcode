# include <stdio.h>

void  main()
{
	/* ˵�����ļ���Ҫʹ�������ļ��еĺ��� */
	extern int multiply();
	extern int sum();

    int a, b;
	int result;
	printf("Please input a and b: ");
	scanf("%d, %d", &a, &b);
	result = multiply(a, b);
	printf("The result of multiply is: %d", result);
	result = sum(a, b);
	printf("\nThe result of sum is: %d\n", result);

}