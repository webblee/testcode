# include <stdio.h>

void head1();
void head2();
void head3();

int count;    /* ȫ�ֱ��� */
void main()
{
	register int index;    /* ����Ϊ�������Ĵ������� */
	head1(); 
	head2();
	head3();
	for (index=8; index>0; index--)    /* ������"for" ѭ�� */
	{
		int stuff;    /* �ֲ����� */
		              /* ���ֱ����Ķ��巽����Turbo C ���ǲ������ */
		              /* stuff �Ŀɼ���Χֻ�ڵ�ǰѭ������ */

		for(stuff=0; stuff<=6; stuff++)
			printf("%d ", stuff);
		printf("index is now %d\n", index);
	}
}

int counter;    /* ȫ�ֱ��� */
			    /* �ɼ���ΧΪ�Ӷ���֮����Դ�����β */
void head1()
{
	int index;    /* �˱���ֻ����head1 */

	index = 23;
	printf("The header1 value is %d\n", index);
}

void head2()
{
	int count;    /* �˱����Ǻ���head2()�ľֲ����� */
				  /* �˱�������ȫ�ֱ���count���� */
				  /* ��ȫ�ֱ���count�����ں���head2()��ʹ�� */

	count = 53;
	printf("The header2 value is %d\n", count);
	counter = 77;
}

void head3()
{
	printf("The header3 value is %d\n", counter);
}