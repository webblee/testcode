# include <stdio.h>

void main()
{
	/* ����һ������ָ��p */
	int *p;
	int begin, end;

	begin = 10;
	/* ��ָ��p����ֵ */
	p = &begin;
	/* ��ָ��ָ���ֵ��������end */
	end = *p;

	printf("begin = %d\n", begin);
	printf("end = %d\n", end);

	/* ���ָ���еĵ�ֵַ */
	printf("p = %d\n", p);
	printf("*p = %d\n", *p);
}