# include <stdio.h>

void main()
{
	/* �������������ֵ */
 	int    a = 5;       
	char   c = 'a';   
	float  f = 5.3;     
	double m = 12.65; 
    double result;
	
	/* ͬ�������ݼ�������㲢������ */
	printf("a + c = %d\n", a + c);
	printf("a + c = %c\n", a + c);
	printf("f + m = %f\n", f + m);

	/* ��ͬ�������ݼ�������㲢������ */
	printf("a + m = %f\n", a + m);
	printf("c + f = %f\n", c + f);

	/* �������ĸ��������л�����㣬�������� */
	result = a + c * (f + m);
	printf("double = %f\n", result);
}


