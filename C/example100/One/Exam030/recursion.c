/* �ݹ鷨������ת�����ַ� */
# include <stdio.h>

void convert(int n)
{
	int i;
	if((i=n/10) != 0)
		convert(i);
	putchar(n%10+'0');
}

void main()
{
	int number;
	printf("����������");
	scanf("%d", &number);
	printf("����ǣ�");
	if(number < 0)
	{
		putchar('-');
		number = -number;
	}
	convert(number);
	putchar('\n');
}