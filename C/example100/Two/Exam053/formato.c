# include <stdio.h>

void main()
{
	unsigned number;
	double item = 1.23456;

	for(number=8; number<16; number++)
	{
		printf("%o   ", number);  /* �԰˽��Ƹ�ʽ���number */
		printf("%x   ", number);  /* ��ʮ���Ƹ�ʽ(Сд)���number */
		printf("%X\n", number);   /* ��ʮ���Ƹ�ʽ(��д)���number */
	}
	printf("\n");
	
	printf("%p\n\n", &item);  /* ��ʾ����item�ĵ�ַ */

	printf("%f\n", item);
	printf("%8.2f\n", item);  /* �����Ϊ8��С������ռ2 */
	printf("%-8.2f\n", item);  /* ������������(Ĭ���Ҷ���) */
}