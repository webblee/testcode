# include <stdio.h>

int count;    /* count��ȫ�ֱ��� */
void func1();    /* �������� */
void func2();

void main()
{
	count = 100;
	func1();
}

void func1()    /* �������� */
{
	int temp;    /* temp�Ǿֲ����� */
	temp = count;
	func2();
	printf("   count is %d\n", count);    /* ��ӡ100 */
	func2();
}

void func2()
{
	int count;    /* ����ֲ�����count */
	for(count = 1; count < 20; count++)
		printf(".");    /* ��ӡ��"." */
	printf("\n");
}
